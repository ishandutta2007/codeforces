#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 1e6+5;
const ll MOD = 1e9+7;

int n, m;
ll fac[N];

// int exp (int a, int b) {
//     if (b == 0) return 1;
//     int x = exp(a, b/2);
//     if (b&1) 
//         return (int)((ll)x * (ll)x % (ll)MOD * (ll)a % (ll)MOD);
//     return (int)((ll)x * (ll)x % (ll)MOD);
// }


ll exp (int a, int b) {
    if (b == 0) return 1LL;
    ll x = exp(a, b/2);
    if (b&1) 
        return x * x % MOD * (ll)a % MOD;
    return x * x % MOD;
}

ll inv (int a) {
    return exp(a, MOD-2);
}

ll bin (int a, int b) {
    int mian = fac[b] * fac[a - b] % MOD;
    return fac[a] * inv(mian) % MOD;
}

int main () {
    fac[0] = 1LL;
    for (int i = 1; i <= (int)(1e6); i++)
        fac[i] = fac[i-1] * (ll)i % MOD;

    scanf("%d %d", &n, &m);

    ll ans = exp(m, n);
    for (int s = 1; s <= n; s++) {
        ll akt = exp(m, s) * exp(m-1, n-s) % MOD * bin(n, s-1) % MOD;

        ans += akt;
        ans %= MOD;
    } 

    printf("%lld\n", ans);

    return 0;
}