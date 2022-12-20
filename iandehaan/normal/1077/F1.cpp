#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll n, k, x;
ll a[201];

ll inf = ((ll) 1) << 60;

ll memo[300][300];

ll dp(ll ind, ll lft) {
    if (ind < 0) return -inf;
    //cout << ind << ' ' << lft << endl;
    if (ind == 0) {
        if (lft == 0) return 0;
        return -inf;
    }
    if (lft == 0) {
        if (ind >= k) return -inf;
        return 0;
    }

    if (memo[ind][lft] != -1) return memo[ind][lft];

    ll out = -inf;
    for (ll i = ind-k; i < ind; i++) {
        if (i < 0) continue;
        out = max(out, dp(i, lft-1) + a[i]);
    }
    return memo[ind][lft] = out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo, -1, sizeof memo);
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << max((ll)-1, dp(n, x)) << endl;
}