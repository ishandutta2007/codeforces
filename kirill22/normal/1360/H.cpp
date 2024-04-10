#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(a) a.begin(), a.end()

void solve() {
    int n, m;
    cin >> n >> m;
    int k = (1ll << m) - n;
    int pos = (k - 1) / 2;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    string ans(m, '0');
    int cnt = -1;
    for (int j = 0; j < m; j++) {
        int l = (1ll << (m - j - 1));
        for (auto el : a) if (el[j] == '0') l--;
        if (cnt + l >= pos) {
            ans[j] = '0';
        }
        else {
            ans[j] = '1';
            cnt += l;
        }
        vector<string> b;
        for (auto s : a) {
            int p = 0;
            for (int i = 0; i <= j; i++) if (s[i] != ans[i]) p++;
            if (p == 0) b.push_back(s);
        }
        a.clear();
        a = b;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}