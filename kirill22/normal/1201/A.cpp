#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<map<char, int>> a(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[j][s[j]]++;
        }
    }
    int ans = 0;
    for (int i = 0;  i < m; i++) {
        int x;
        cin >> x;
        int mx = 0;
        for (auto c : a[i]) {
            mx = max(mx, c.second);
        }
        ans +=  mx * x;
    }
    cout << ans;
}