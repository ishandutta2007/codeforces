#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ve<ve<int>> dp(n, ve<int> (n)), go(n, ve<int> (n));
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            if (s[l] == s[r]) {
                go[l][r] = 1;
                if (r + 1 < n) go[l][r] += go[l + 1][r + 1];
            }
            else {
                go[l][r] = 0;
            }
        }
    }
    int ans = 0;
    forn (i, n) {
        forn (v, i) {
            int x = go[v][i];
            if (x + i < n && s[x + i] > s[x + v]) {
                dp[i][i + x] = max(dp[i][i + x], dp[v][n - 1] + 1);
            }
        }
        for (int j = i; j < n; j++) {
            dp[i][j] = max(dp[i][j], 1);
            if (j != i) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1); 
            }
        }
    }
    forn (i, n) forn (j, n) ans = max(ans, dp[i][j]);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}