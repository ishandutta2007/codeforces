#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve(vector<pair<int, char>> a) {
    cout << "YES" << endl;
    cout << a.size() << endl;
    for (auto el : a) {
        cout << el.first << " " << el.second << endl;
    }
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, char>> a;
    for (int i = 1; i < n; i++) {
        if (k == 0) solve(a);
        a.push_back({1, 'D'});
        k--;
        if (k == 0) solve(a);
        if (m == 1) continue;
        if (k <= m - 1) {
            a.push_back({k, 'R'});
            solve(a);
        }
        a.push_back({m - 1, 'R'});
        k -= m - 1;
        if (k == 0) solve(a);
        if (k <= m - 1) {
            a.push_back({k, 'L'});
            solve(a);
        }
        a.push_back({m - 1, 'L'});
        k -= m - 1;
    }
    if (k == 0) solve(a);
    if (n != 1) {
        if (k <= n - 1) {
            a.push_back({k, 'U'});
            solve(a);
        }
        a.push_back({n - 1, 'U'});
        k -= n - 1;
        if (k == 0) solve(a);
    }
    for (int i = 1; i < m; i++) {
        if (k == 0) solve(a);
        a.push_back({1, 'R'});
        k--;
        if (k == 0) solve(a);
        if (n == 1) continue;
        if (k <= n - 1) {
            a.push_back({k, 'D'});
            solve(a);
        }
        a.push_back({n - 1, 'D'});
        k -= n - 1;
        if (k == 0) solve(a);
        if (k <= n - 1) {
            a.push_back({k, 'U'});
            solve(a);
        }
        a.push_back({n - 1, 'U'});
        k -= n - 1;
        if (k == 0) solve(a);
    }
    if (k == 0) solve(a);
    if (m != 1) {if (k <= m - 1) {
        a.push_back({k, 'L'});
        solve(a);
    }}
    cout << "NO";
}