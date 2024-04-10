#include "bits/stdc++.h"
using namespace std;

void solve() {
    string s;
    cin >> s;
    int diff = 0;
    for (char c : s) {
        if (c == '0')
            diff--;
        else
            diff++;
    }
    int moves = (s.size() - abs(diff)) / 2;
    if (moves % 2)
        cout << "DA" << '\n';
    else
        cout << "NET" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}