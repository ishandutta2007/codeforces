#include "bits/stdc++.h"
using namespace std;

void solve() {
    vector<int> v(3);
    for (auto& x : v) {
        cin >> x;
    }

    auto w = v;
    w.push_back(1);
    sort(w.begin(), w.end());
    do {
        if (max(w[0], w[1]) == v[0] && max(w[0], w[2]) == v[1] && max(w[1], w[2]) == v[2]) {
            cout << "YES" << '\n';
            for (int i = 0; i < 3; i++) {
                cout << w[i] << ' ';
            }
            cout << '\n';
            return;
        }
    } while (next_permutation(w.begin(), w.end()));
    cout << "NO" << '\n';
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