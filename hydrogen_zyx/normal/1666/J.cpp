#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 500;
const ll mod = 1e9 + 7;
ll c[N][N];
ll dp[N][N];
ll rt[N][N];

ll n;

ll query(ll l, ll r) {
    if(l > r) return 0;
    ll ans = c[r][n] - c[l - 1][n];
    ans -= c[r][r] - c[l - 1][r] - c[r][l - 1] + c[l - 1][l - 1];
    return ans;
}

ll fa[N];

ll getrt(ll l, ll r) {
    ll mid = rt[l][r];
    if (l != mid) {
        ll tmp = getrt(l, mid - 1);
        fa[tmp] = mid;
    }
    if (r != mid) {
        ll tmp = getrt(mid + 1, r);
        fa[tmp] = mid;
    }
    return mid;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }


    for (ll i = 1; i <= n; i++) rt[i][i] = i;
    for (ll len = 2; len <= n; len++) {
        for (ll i = 1; i + len - 1 <= n; i++) {
            ll l = i, r = i + len - 1;
            dp[l][r] = 0x3f3f3f3f3f3f3f3f;
            for (ll mid = l; mid <= r; mid++) {
                ll res = dp[l][mid - 1] + dp[mid + 1][r] + query(l, mid - 1) + query(mid + 1, r);
                if (res < dp[l][r]) {
                    dp[l][r] = res;
                    rt[l][r] = mid;
                }
            }
        }
    }
    getrt(1, n);
    for (ll i = 1; i <= n; i++) cout << fa[i] << " ";
}