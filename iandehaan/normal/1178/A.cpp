#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> parties[n];
    int totalSeats = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        totalSeats += x;
        parties[i] = make_pair(x, i+1);
    }
    int alice = parties[0].first;
    vector<int> out;
    out.push_back(1);
    int total = alice;
    for (int i = 0; i < n; i++) {
        if (parties[i].first <= double(alice)/2) {
            total += parties[i].first;
            out.push_back(parties[i].second);
        }
    }
    if (total > double(totalSeats)/2) {
        cout << out.size() << endl;
        for (int i = 0; i < out.size()-1; i++) {
            cout << out[i] << ' ';
        }
        cout << out[out.size()-1] << endl;
    } else {
        cout << 0 << endl;
    }
}