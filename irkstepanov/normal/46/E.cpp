#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 1550;
const ll inf = 1e18;

ll dp[2][nmax];
ll a[nmax];
ll sum[nmax];

ll pref[nmax], suff[nmax];

int main() {
 
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    dp[0][0] = 0;
    for (int i = 1; i < nmax; ++i) {
        dp[0][i] = -inf;
    }

    int n, m;
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    int ptr = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //cin >> a[j];
            scanf("%lld", &a[j]);
        }

        sum[1] = a[0];
        for (int j = 2; j <= m; ++j) {
            sum[j] = sum[j - 1] + a[j - 1];
        }
        for (int j = 0; j < nmax; ++j) {
            dp[ptr ^ 1][j] = -inf;
        }

        if (i & 1) {
            suff[nmax - 1] = -inf;
            for (int j = nmax - 2; j >= 0; --j) {
                suff[j] = max(suff[j + 1], dp[ptr][j + 1]);
            }
        } else {
            pref[0] = -inf;
            for (int j = 1; j < nmax; ++j) {
                pref[j] = max(pref[j - 1], dp[ptr][j - 1]);
            }
        }
        

        for (int k = 1; k <= m; ++k) {
            if (i & 1) {
                dp[ptr ^ 1][k] = sum[k] + suff[k];
            } else {
                dp[ptr ^ 1][k] = sum[k] + pref[k];
            }
        }
        ptr ^= 1;
    }

    ll ans = -inf;
    for (int k = 1; k <= m; ++k) {
        ans = max(ans, dp[ptr][k]);
    }
    cout << ans << '\n';

}