#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n;
ll a[501];

ll memo[501][501];

ll dp(ll l, ll r) {
    if (memo[l][r] != -1) return memo[l][r];

    if (l == r) return a[l];

    memo[l][r] = 1e9;
    for (int split = l+1; split <= r; split++) {
        if (dp(l, split-1) != 0 && dp(split, r) != 0) {
            if (dp(l, split-1) == dp(split, r)) {
                return memo[l][r] = dp(l, split-1)+1;
            }
        }
    }
    return memo[l][r] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i];

    

    ll out = 0;
    ll best[n];
    best[0] = 1;
    for (ll i = 1; i < n; i++) {
        best[i] = 1e9;
        for (ll j = 0; j <= i; j++) {
            if (dp(j, i)) {
                //cout << j << ' ' << i << " works" << endl;
                if (j == 0) {
                    best[i] = min(best[i], (ll)1);
                } else {
                    best[i] = min(best[i], best[j-1]+1);
                }
            }
        }
    }
    cout << best[n-1] << endl;
}