#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    vector<int> ma_r(n);
    ma_r[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--)
        ma_r[i] = max(ma_r[i+1], v[i]);

    stack<pair<int, int>> s;
    s.push({v[0], 0});
    int prefix = 0;
    for (int i = 1; i < n - 1; i++) {
        while (!s.empty() && s.top().first <= v[i]) {
            s.pop();
        }
        if (v[i] < ma_r[i+1] && !s.empty() && v[i] < s.top().first)
            prefix = max(prefix, s.top().second + 1);
        s.push({v[i], i});
    }
    cout << prefix << '\n';
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