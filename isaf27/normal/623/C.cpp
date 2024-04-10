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
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7; // 998244353
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;
const int fr = 4;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int power(ll a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//random
mt19937 rnd(239);

//constants
const int M = 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 200;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;
const ll R = (1e17);

int n, x[M], y[M], np[M], mp[M], ms[M], ns[M];

inline ll mysqrt(ll x)
{
    ll l = 0;
    ll r = BIG;
    while (r - l > 1)
    {
        ll h = (l + r) >> 1LL;
        if (h * h <= x)
            l = h;
        else
            r = h;
    }
    return l;
}

inline ll dist(pair<int, int> &a, pair<int, int> &b)
{
    return (ll)(b.first - a.first) * (ll)(b.first - a.first) + (ll)(b.second - a.second) * (ll)(b.second - a.second);
}

inline ll diam(vector<pair<int, int> > &v)
{
    ll ans = 0;
    for (int i = 0; i < (int)v.size(); i++)
        for (int j = i + 1; j < (int)v.size(); j++)
            ans = max(ans, dist(v[i], v[j]));
    return ans;
}

inline bool checkup(int i, ll r, int z)
{
    if (y[i] > 0) return false;
    int j = upper_bound(y, y + n, min(-y[i], y[i] + z)) - y;
    if (i + (n - j) == 0) return true;
    int mn = np[i];
    int mx = mp[i];
    mn = min(mn, ns[j]);
    mx = max(mx, ms[j]);
    if ((ll)(mn - mx) * (ll)(mn - mx) > r) return false;
    mx = max(abs(mx), abs(mn));
    mn = max(abs(y[i]), abs(y[j - 1]));
    return ((ll)mx * (ll)mx + (ll)mn * (ll)mn <= r);
}

inline bool checkdn(int j, ll r, int z)
{
    if (y[j] < 0) return false;
    int i = lower_bound(y, y + n, max(-y[j], y[j] - z)) - y;
    j++;
    if (i + (n - j) == 0) return true;
    int mn = np[i];
    int mx = mp[i];
    mn = min(mn, ns[j]);
    mx = max(mx, ms[j]);
    if ((ll)(mn - mx) * (ll)(mn - mx) > r) return false;
    mx = max(abs(mx), abs(mn));
    mn = max(abs(y[i]), abs(y[j - 1]));
    return ((ll)mx * (ll)mx + (ll)mn * (ll)mn <= r);
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
        cin >> x[i] >> y[i];
    vector<tuple<int, int, int> > v;
    for (int i = 0; i < n; i++)
        v.push_back(make_tuple(y[i], x[i], i));
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        x[i] = get<1>(v[i]), y[i] = get<0>(v[i]);
    np[0] = BIG;
    mp[0] = -BIG;
    for (int i = 0; i < n; i++)
    {
        np[i + 1] = min(np[i], x[i]);
        mp[i + 1] = max(mp[i], x[i]);
    }
    ns[n] = BIG;
    ms[n] = -BIG;
    for (int i = n - 1; i >= 0; i--)
    {
        ns[i] = min(ns[i + 1], x[i]);
        ms[i] = max(ms[i + 1], x[i]);
    }
    ll l = -1;
    ll r = R;
    while (r - l > 1)
    {
        ll h = (l + r) >> 1LL;
        int z = mysqrt(h);
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            if (checkup(i, h, z))
            {
                ok = true;
                break;
            }
            if (checkdn(i, h, z))
            {
                ok = true;
                break;
            }
        }
        if (!ok) l = h;
        else r = h;
    }
    ll ans = min(r, (ll)(mp[n] - np[n]) * (ll)(mp[n] - np[n]));
    cout << ans;
    return 0;
}