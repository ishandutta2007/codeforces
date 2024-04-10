#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

ll modpow(ll n, ll e = MOD - 2) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x; x%= MOD;
    if(e%2) {
        x *= n;
        x %= MOD;
    }
    return x;
}

// DO NOT SUBMIT

ll ans[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i <= 2000; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) ans[i][j] = 0;
            else if(i == j) ans[i][j] = i;
            else ans[i][j] = ((ans[i-1][j-1] + ans[i-1][j]) * modpow(2)) % MOD;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        cout << (ans[n][m] * k) % MOD;
        cout << '\n';
    }
}