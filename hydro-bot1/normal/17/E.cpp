// Hydro submission #62a88fb4ffcafb3af9e2985e@1655214005474
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

const ll N = 4e6 + 10;
const ll mod = 51123987;
ll n, ans, tot, sum;
char s[N], a[N];
ll f[N], g[N], p[N];

inline void manacher(){
    s[0] = '*', s[(n << 1) + 1] = '#';
    for(ll i = 1; i <= n; ++i)
        s[(i << 1) - 1] = '#', s[i << 1] = a[i];
    n = (n << 1) + 1;
    ll mx = 0, id = 0;
    for(ll i = 1; i <= n; ++i){
        if(i < mx) p[i] = min(mx - i, p[(id << 1) - i]);
        else p[i] = 1;
        while(i - p[i] >= 1 && i + p[i] <= n && s[i - p[i]] == s[i + p[i]]) p[i]++;
        if(i + p[i] > mx) mx = i + p[i], id = i;
        tot = (tot + (p[i] >> 1)) % mod;
    }
}

signed main(){
    scanf("%lld%s", &n, a + 1);
    manacher();
    for(ll i = 1; i <= n; ++i){
        f[i - p[i] + 1]++, f[i + 1]--;
        g[i]++, g[i + p[i]]--;
    }
    for(ll i = 1; i <= n; ++i)
        f[i] += f[i - 1], g[i] += g[i - 1];
    ans = tot * (tot - 1) / 2 % mod;
    for(ll i = 2; i <= n - 2; i += 2){
        sum = (sum + g[i]) % mod;
        ans = (ans - sum * f[i + 2] % mod + mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}