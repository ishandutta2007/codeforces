#include <algorithm>
#include <cstdio>
#define ll long long
#define mod 998244353
#define tod 998244352
#define MaxN 1005000
using namespace std;
ll powM(ll a, int t) {
    ll ans = 1;
    while (t) {
        if (t & 1) ans = ans * a % mod;
        a = a * a % mod;
        t >>= 1;
    }
    return ans;
}
int n;
ll fac[MaxN], ifac[MaxN], pw[35000], pw2[35000];
ll C(int n, int m) { return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
ll pow3(int t) { return pw2[t >> 15] * pw[t & 32767] % mod; }
void Init() {
    fac[0] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++)
        ifac[i] = (ifac[mod % i] * (mod - mod / i)) % mod;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i] * ifac[i - 1] % mod;
    }
    pw[0] = pw2[0] = 1;
    for (int i = 1; i <= 32767; i++) pw[i] = pw[i - 1] * 3 % mod;
    ll buf = pw[32767] * 3 % mod;
    for (int i = 1; i <= 31000; i++) pw2[i] = pw2[i - 1] * buf % mod;
}
int main() {
    scanf("%d", &n);
    Init();
    ll ans = 0, sav;
    for (int i = 1; i <= n; i++) {
        sav = C(n, i) * pow3(1ll * (tod - i) * n % tod) % mod *
              (powM(1 - pow3(i - n + tod), n) - 1) % mod;
        if (i & 1)
            ans = (ans - sav) % mod;
        else
            ans = (ans + sav) % mod;
    }
    ans = ans * pow3((1ll * n * n + 1) % tod) % mod;
    ans = (ans + 2 * pow3(1ll * n * n % tod) % mod *
                     (powM(1 - pow3(tod + 1 - n), n) - 1)) %
          mod;
    printf("%I64d", (mod - ans) % mod);
    return 0;
}