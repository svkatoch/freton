#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int amountPaid;
    vector<int> apples;
    int totalWeight;
};

bool compareByWeight(int a, int b) {
    return a > b;
}

void inputAppleWeights(vector<int>& appleWeights) {
    int weight;
    cout << "Enter apple weight in gram (-1 to stop): ";
    while (cin >> weight && weight != -1) {
        appleWeights.push_back(weight);
        cout << "Enter apple weight in gram (-1 to stop): ";
    }
}

bool comparePersons(const Person& a, const Person& b) {
    return a.totalWeight * b.amountPaid < b.totalWeight * a.amountPaid;
}

void distributeApples(vector<int>& appleWeights, vector<Person>& people) {
    sort(appleWeights.begin(), appleWeights.end(), compareByWeight);

    for (int weight : appleWeights) {
        sort(people.begin(), people.end(), comparePersons);

        people[0].apples.push_back(weight);
        people[0].totalWeight += weight;
    }
}

void displayResults(const vector<Person>& people) {
    for (const auto& person : people) {
        cout << person.name << ": ";
        for (int weight : person.apples) {
            cout << weight << " ";
        }
        cout << "(total " << person.totalWeight << "g, " << (person.totalWeight * 100) / 1000 << "%)" << endl;
    }
}

int main() {
    vector<int> appleWeights;
    inputAppleWeights(appleWeights);

    vector<Person> people = {
        {"Ram", 50, {}, 0},
        {"Sham", 30, {}, 0},
        {"Rahim", 20, {}, 0}
    };

    distributeApples(appleWeights, people);
    displayResults(people);

    return 0;
}
