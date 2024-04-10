#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

const int BIG = 300001;

ll fact[BIG], invfact[BIG];
ll ct_2[BIG], ct_3[BIG];

ll modpow(ll n, ll e = MOD - 2) {
    if(e == 0) return 1;
    ll x = modpow(n, e/2);
    x *= x; x %= MOD;
    if(e % 2 == 1) {
        x *= n;
        x %= MOD;
    }
    return x;
}

ll binom(int n, int k) {
    return (((invfact[k] * invfact[n-k]) % MOD) * fact[n]) % MOD;
}

void solve() {
    int n;
    cin >> n;
    ll tot = 0;
    for(int i = 0; i <= n; i += 4) {
        int block_count = i / 2;
        int empty_count = n - i;
        ll part_tot = binom(block_count + empty_count, empty_count);
        part_tot *= ct_2[block_count / 2];
        part_tot %= MOD;
        part_tot *= modpow(2, block_count / 2);
        part_tot %= MOD;
        part_tot *= ct_3[empty_count];
        part_tot %= MOD;
        tot += part_tot;
        tot %= MOD;
    }
    cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = invfact[0] = ct_2[0] = ct_3[0] = ct_3[1] = 1;
    for(int i = 1; i < BIG; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = modpow(fact[i]);
        ct_2[i] = (ct_2[i-1] * (2 * i - 1)) % MOD;
    }
    for(int i = 2; i < BIG; i++) {
        ct_3[i] = (ct_3[i-1] + (i - 1) * ct_3[i-2]) % MOD;
    }
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}