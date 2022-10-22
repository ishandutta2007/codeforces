#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    int t = a[0] % 2;
    int j = n - 1;
    while (a[j] % 2 != t) {
        j--;
    }
    for (int i = 0; i < j; i++) {
        if (a[i] % 2 == t) {
            ans.push_back({i, j});
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != t) {
            ans.push_back({0, i});
        }
    }
    cout << (int) ans.size() << '\n';
    for (auto [i, j] : ans) {
        cout << i + 1 << " " << j + 1 << '\n';
    }
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