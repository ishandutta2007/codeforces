/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 1e6 + 239;
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

ll power(ll a, int k)
{
    if (k == 0) return 1;
    ll t = power(a, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * a) % MOD;
    return t;
}

ll f[M], inv[M], pwm[M], pwn[M];

ll getC(int n, int k)
{
    if (n < k) return 0;
    ll ans = (inv[k] * inv[n - k]) % MOD;
    ans = (ans * f[n]) % MOD;
    return ans;
}

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[0] = 1;
    for (int i = 1; i < M; i++)
        f[i] = ((ll)i * f[i - 1]) % MOD;
    inv[M - 1] = power(f[M - 1], MOD - 2);
    for (int i = M - 2; i >= 0; i--)
        inv[i] = ((ll)(i + 1) * inv[i + 1]) % MOD;
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    pwm[0] = 1;
    for (int i = 1; i < M; i++)
        pwm[i] = (pwm[i - 1] * (ll)m) % MOD;
    pwn[0] = 1;
    for (int i = 1; i < M; i++)
        pwn[i] = (pwn[i - 1] * (ll)n) % MOD;
    ll ans = 0;
    for (int k = 1; k < n; k++)
    {
        ll now = (getC(m - 1, k - 1) * pwm[n - 1 - k]) % MOD;
        now = (now * getC(n - 2, k - 1)) % MOD;
        now = (now * f[k - 1]) % MOD;
        if (k < n - 1)
        {
            now = (now * (ll)(k + 1)) % MOD;
            now = (now * pwn[n - k - 2]) % MOD;
        }
        ans += now;
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans;
    return 0;
}