#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> squares;
    vector<int> non;

    vector<pair<int, int>> vv(n);
    for (int i = 0; i < n; i++) {
        int sq = sqrt(v[i]);
        int sq2 = sq * sq;
        if (sq2 == v[i]) {
            if (v[i] == 0)
                squares.push_back(2);
            else
                squares.push_back(1);
        } else {
            non.push_back(min(v[i] - sq2, (sq+1) * (sq+1) - v[i]));
        }
    }

    sort(squares.begin(), squares.end());
    sort(non.begin(), non.end());

    long long cost = 0;
    if (squares.size() > non.size()) {
        int change = (squares.size() - non.size()) / 2;
        for (int i = 0; i < change; i++) {
            cost += squares[i];
        }
        cout << cost << endl;
    } else {
        int change = (non.size() - squares.size()) / 2;
        for (int i = 0; i < change; i++) {
            cost += non[i];
        }
        cout << cost << endl;
    }
}