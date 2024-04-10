#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    map<pair<char, char>, int> dp;
    for (int i = 0; i < n; i++) {
        auto x = s[i], y = t[n - i - 1];
        if (x > y) {
            swap(x, y);
        }
        dp[{x, y}]++;
    }
    int cnt = 0;
    for (auto [x, c] : dp) {
        cnt += c % 2;
    }
    map<char, int> d;
    for (auto c : s) {
        d[c]++;
    }
    for (auto c : t) {
        d[c]++;
    }
    for (auto [x, c] : d) {
        if (c % 2 == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << (cnt <= n % 2 ? "YES\n" : "NO\n");
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