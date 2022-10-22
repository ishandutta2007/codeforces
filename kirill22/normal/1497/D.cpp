#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double

const int nx = 10000;
int type[nx];
long long s[nx], dp[nx], dp2[nx];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> type[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    fill(dp, dp + n, 0);
    for (int r = 0; r < n; r++) {
        for (int i = 0; i < n; i++) dp2[i] = dp[i];
        long long tmp = -1e18;
        for (int l = r; l >= 0; l--) {
            if (type[l] == type[r]) continue;
            dp2[r] = max(dp2[r], dp[l] + abs(s[l] - s[r]));
            dp2[l] = max(dp2[l], dp[r] + abs(s[l] - s[r]));
            dp2[l] = max(dp2[l], tmp + abs(s[l] - s[r]));
            tmp = max(tmp, dp[l] + abs(s[l] - s[r]));
        }
        for (int i = 0; i < n; i++) dp[i] = dp2[i];
    }
    cout << *max_element(dp, dp + n) << '\n';
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