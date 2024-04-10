/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
mt19937 rnd(239);

//constants
const int M = 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 510;

int n;
ll a[X];

ll get2(ll x)
{
    ll l = 0;
    ll r = 1414213563;
    while (r - l > 1)
    {
        ll h = (l + r) / 2LL;
        ll f = h * h;
        if (f <= x)
            l = h;
        else
            r = h;
    }
    return l;
}

ll get3(ll x)
{
    ll l = 0;
    ll r = 1259922;
    while (r - l > 1)
    {
        ll h = (l + r) / 2LL;
        ll f = h * h * h;
        if (f <= x)
            l = h;
        else
            r = h;
    }
    return l;
}

ll get4(ll x)
{
    ll l = 0;
    ll r = 37607;
    while (r - l > 1)
    {
        ll h = (l + r) / 2LL;
        ll f = h * h * h * h;
        if (f <= x)
            l = h;
        else
            r = h;
    }
    return l;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<ll, ll> kol;
    map<ll, ll> st;
    for (int i = 0; i < n; i++)
    {
        ll x4 = get4(a[i]);
        if (x4 * x4 * x4 * x4 == a[i])
        {
            kol[x4] += 4;
            continue;
        }
        ll x3 = get3(a[i]);
        if (x3 * x3 * x3 == a[i])
        {
            kol[x3] += 3;
            continue;
        }
        ll x2 = get2(a[i]);
        if (x2 * x2 == a[i])
        {
            kol[x2] += 2;
            continue;
        }
        bool ch = false;
        for (int j = 0; j < n; j++)
            if (j != i)
            {
                ll t = gcd(a[i], a[j]);
                if (1 < t && t < a[i])
                {
                    kol[t]++;
                    kol[a[i] / t]++;
                    ch = true;
                    break;
                }
            }
        if (ch) continue;
        st[a[i]]++;
    }
    ll ans = 1;
    for (pair<ll, ll> t : kol)
        ans = (ans * (t.second + 1)) % MOD;
    for (pair<ll, ll> t : st)
    {
        ans = (ans * (t.second + 1)) % MOD;
        ans = (ans * (t.second + 1)) % MOD;
    }
    cout << ans;
    return 0;
}