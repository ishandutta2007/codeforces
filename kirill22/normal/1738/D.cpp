#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> d(n + 2);
    vector<int> need(n + 2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        need[x]++;
        d[x].push_back(i + 1);
    }
    vector<vector<int>> g;
    vector<int> tmp = {0, n + 1};
    while ((int) tmp.size()) {
        vector<int> b;
        for (auto y : tmp) {
            for (auto i : d[y]) {
                b.push_back(i);
            }
        }
        g.push_back(b);
        tmp = b;
    }
    for (auto& mas : g) {
        sort(mas.begin(), mas.end(), [&] (int i, int j) { return need[i] < need[j]; });
    }
    set<int> t;
    for (int i = 0; i < (int) g.size(); i += 2) {
        for (auto x : g[i]) {
            t.insert(x);
        }
    }
    if (need[0]) {
        cout << *t.begin() - 1 << '\n';
    } else {
        cout << *t.rbegin() << '\n';
    }
    for (auto x : g) {
        for (auto y : x) {
            cout << y << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}