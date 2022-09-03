//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; // (int)(1e9 + 7);
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = 500;
const int X = 1e6 + 239;

int n, a[X];
ll c[X], s[X];

ll score(int l, int r)
{
    //cerr << l << " " << r << "!\n";
    ll ans = INF;
    for (int t = l; t < r; t++)
    {
        ll cur = (ll)t * (c[t] - c[l]) - (s[t] - s[l]);
        cur += (s[r] - s[t]) - (ll)t * (c[r] - c[t]);
        ans = min(ans, cur);
    }
    //cerr << ans << "?\n";
    return ans;
}

ll check(ll p)
{
    c[0] = 0;
    s[0] = 0;
    for (int i = 0; i < n; i++)
    {
        c[i + 1] = c[i] + (ll)(a[i] % p);
        s[i + 1] = s[i] + (ll)(a[i] % p) * (ll)i;
    }
    int l = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (c[i] % p == 0)
        {
            ans += score(l, i);
            l = i;
        }
    return ans;
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll x = 0;
    for (int i = 0; i < n; i++)
        x += a[i];
    if (x == 1)
    {
        cout << "-1";
        return 0;
    }
    ll ans = x * (ll)n;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            ans = min(ans, check(i));
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        ans = min(ans, check(x));
    cout << ans << "\n";
    return 0;
}