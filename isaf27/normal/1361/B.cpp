//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
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
const int MOD = 1e9 + 7;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1e4 + 239;

const ll UP = 1e9;

int n, p, a[M];

ll mult(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == UP || b == UP)
        return UP;
    return min(UP, a * b);
}

pair<int, ll> power(int k)
{
    if (k == 0)
        return make_pair(1, 1);
    pair<int, ll> t = power(k >> 1);
    t.first = 1LL * t.first * t.first % MOD;
    t.second = mult(t.second, t.second);
    if (k & 1)
    {
        t.first = 1LL * t.first * p % MOD;
        t.second = mult(t.second, p);
    }
    return t;
}

void solve()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (p == 1)
    {
        cout << (n % 2) << "\n";
        return;
    }
    sort(a, a + n);
    reverse(a, a + n);
    ll ans = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        int dn = a[i - 1] - a[i];
        pair<int, ll> cur = power(dn);
        res = 1LL * res * cur.first % MOD;
        ans = mult(ans, cur.second);
        if (ans == 0)
        {
            ans = 1;
            res = 1;
        }
        else if (ans == UP)
        {
            res--;
            if (res < 0)
                res += MOD;
        }
        else
        {
            ans--;
            res--;
            if (res < 0)
                res += MOD;
        }
    }
    pair<int, ll> fn = power(a[n - 1]);
    res = 1LL * res * fn.first % MOD;
    cout << res << "\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}