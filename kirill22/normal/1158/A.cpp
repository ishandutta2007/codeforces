#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (auto x : a) {
        ans += x * 1ll * m;
    }
    vector<pair<int, int>> tmp(n);
    for (int i = 0; i < n; i++) {
        tmp[i] = {a[i], m - 1};
    }
    for (auto y : b) {
        if (a.back() > y) {
            cout << -1;
            return 0;
        }
        int it = lower_bound(a.begin(), a.end(), y) - a.begin();
        if (it < n && a[it] == y) {
            continue;
        }
        it = upper_bound(tmp.begin(), tmp.end(), make_pair(y, n)) - tmp.begin() - 1;
        if (it < 0) {
            cout << -1;
            return 0;
        }
        ans += y - tmp[it].first;
        tmp[it].second--;
        if (!tmp[it].second) {
            tmp.erase(tmp.begin() + it);
        }
    }
    cout << ans;
}