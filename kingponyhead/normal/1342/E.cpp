// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 41, Mod = 998244353;
int q, A[N], F[N], I[N];
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1LL * a * a % Mod)
        if (b & 1) ret = 1LL * ret * a % Mod;
    return (ret);
}
inline int NCR(int a, int b)
{
    if (a < 0 || a > b)
        return 0;
    return (F[b] * 1LL * I[a] % Mod * I[b - a] % Mod);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll c = n - k;
    if (c <= 0 || c > n)
        return !printf("0\n");
    for (int i = F[0] = 1; i < N; i ++)
        F[i] = 1LL * F[i - 1] * i % Mod;
    I[N - 1] = Power(F[N - 1], Mod - 2);
    for (int i = N - 2; ~ i; i --)
        I[i] = 1LL * I[i + 1] * (i + 1) % Mod;
    ll res = 0;
    for (int i = c; i; i --)
    {
        ll tmp = 1LL * Power(i, n) * NCR(i, c) % Mod;
        if ((c - i) % 2 == 0)
            res = (res + tmp) % Mod;
        else
            res = (res - tmp + Mod) % Mod;
    }
    res = 1LL * res * NCR(c, n) % Mod;
    res = res * 2LL % Mod;
    if (k == 0)
        res = F[n];
    printf("%lld\n", res);
    return 0;
}