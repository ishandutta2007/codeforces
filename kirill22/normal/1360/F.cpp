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
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool f = false;
    string ans;
    for (int j = 0; j < m; j++) {
        string s = a[0];
        for (int k = 0; k < 26; k++) {
            s[j] = 'a' + k;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int cnt2 = 0;
                for (int j2 = 0; j2 < m; j2++) {
                    if (s[j2] != a[i][j2]) cnt2++;
                }
                if (cnt2 <= 1) cnt++;
            }
            if (cnt == n) {
                f = true;
                ans = s;
            }
        }
    }
    if (f) cout << ans << endl;
    else cout << -1 << endl;
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