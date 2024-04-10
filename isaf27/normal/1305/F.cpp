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
const int MOD = 998244353; //1e9 + 7;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;

int n, ans;
ll a[M];

set<ll> was;

void prime(ll p)
{
    if (was.find(p) != was.end())
        return;
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= p)
            cur += p - a[i];
        else
            cur += min(a[i] % p, p - (a[i] % p));
    }
    if (cur < (ll)ans)
        ans = cur;
    was.insert(p);
}

void upd(ll x)
{
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            prime(i);
            while (x % i == 0)
                x /= i;
        }
    if (x != 1)
        prime(x);
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ans = n;
    while (TIME <= 2.0)
    {
        int pos = rnd() % n;
        upd(a[pos]);
        upd(a[pos] + 1);
        if (a[pos] != 1)
            upd(a[pos] - 1);
    }
    cout << ans << "\n";
    return 0;
}