//Updated 29.09.18
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define sqr(z) (z) * (z)
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i++)
#define nfor(i, n) for (int (i) = (n) - 1; (i) != -1; i--)
#define do_nothing cout << " Work_Error ";
#define erace erase
#define incert insert
#define reverce reverse
#define re return
#define prev prev1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
typedef unsigned long long ull;
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
const int SZ = 300100;
const double PI = 3.14159265358979323846264338327;
ll inq(ll k, ll q, ll mod)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2, mod);
    if (q % 2 == 0)
        return l * l % mod;
    else
        return l * l % mod * k % mod;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll cubr(ll a)
{
    ll l = -1, r = 1e6 + 2;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return l;
}
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min(ll a, ll b)
{
    return -1 * max(-a, -b);
}
ll possible(ll q)
{
    if (q == INF)
        return -1;
    return q;
}
bool correct(int x, int xx)
{
    if (x < 0)
        return 0;
    if (x >= xx)
        return 0;
    return 1;
}
ll dsumm(ll x, ll k)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; y < 1e18; i++)
    {
        z += x / y % k;
        y *= k;
    }
    return z;
}
ll dcount(ll x)
{
    ll y = 1;
    ll z = 0;
    int c[100];
    for (int i = 0; i < 10; i++)
    c[i] = 0;
    for (int i = 0; x > 0; i++)
    {
        if (c[x / y % 10] == 0)
        z++;
        c[x / y % 10] = 1;
        x /= 10;
    }
    return z;
}
ll lg10(ll x)
{
    if (10000 <= x && x < 100000)
        re 5;
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
}
ll g(ll x, ll mod)
{
    if (x == 0)
        re 0;
    return x / mod + g(x / mod, mod);
}
bool is_digit(char c)
{
    re ('0' <= c && c <= '9');
}

#define bitcount __builtin_popcount
#define bitcountl __builtin_popcountll

#define RA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i];
#define WA(n, arr) cout << n << "\n"; forn(i, n) cout << (arr)[i] << " ";
#define WWA(n, arr) forn(i, n) cout << (arr)[i] << " ";
#define RSA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i]; sort(arr, arr + n);
#define WSA(n, arr) cout << n << "\n"; sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WWSA(n, arr) sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WSV(vec) cout << vec.size() << "\n"; sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
#define WWSV(vec) sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
//string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
ll w, n, k;
ll t[600000];
ll c[(1 << 12)];
ll convert[(1 << 12)];
string s;
ll ans;
ll bit;

void qwer(int x, int y)
{
    vector<int> ds;
    while (x > 0)
    {
        ds.pb(x % y);
        x /= y;
    }
    reverce(all(ds));
    for (int i = 0; i < ds.sz; i++)
    {
        cout << ds[i];
    }
}

ll tao(int x)
{
    vector<int> ds;
    while (x > 0)
    {
        ds.pb(x % 2);
        x /= 2;
    }
    for (int i = ds.sz; i < 12; i++)
    {
        ds.pb(0);
    }
    reverce(all(ds));
    ll ans = 0;
    for (int i = 0; i < 12; i++)
    {
        ans = ans * 3 + ds[i];
    }
    re ans;
}

void precalc()
{
    for (int i = 0; i < (1 << 12); i++)
    {
        convert[i] = tao(i);
        //qwer(i, 2); cout << " "; qwer(convert[i], 3); cout << endl;
    }
}

void work()
{
    for (int i = 0; i < (1 << 12); i++)
    {
        for (int j = 0; j < (1 << 12); j++)
        {
            ll i2 = convert[i];
            ll j2 = convert[j];
            /*if (c[i] != 0 && c[j] != 0)
            {
                cout << c[i] << " " << c[j] << endl;
                qwer(i, 2); cout << " "; qwer(j, 2); cout << endl;
                qwer(i2 + j2, 3); cout << endl;
            }*/
            t[i2 + j2] += c[i] * c[j];
        }
    }
}

void rec(int x)
{
    //cout << x << " " << bit << endl;
    if (x == s.sz)
    {
        //cout << bit << endl;
        ans += t[bit];
        re;
    }

    if (s[x] == 'A')
    {
        bit = bit * 3 + 0;
        rec(x + 1);
        bit = (bit - 0) / 3;

        bit = bit * 3 + 1;
        rec(x + 1);
        bit = (bit - 1) / 3;
    }

    if (s[x] == 'O')
    {
        bit = bit * 3 + 0;
        rec(x + 1);
        bit = (bit - 0) / 3;
    }

    if (s[x] == 'X')
    {
        bit = bit * 3 + 0;
        rec(x + 1);
        bit = (bit - 0) / 3;

        bit = bit * 3 + 2;
        rec(x + 1);
        bit = (bit - 2) / 3;
    }

    if (s[x] == 'a')
    {
        bit = bit * 3 + 2;
        rec(x + 1);
        bit = (bit - 2) / 3;
    }

    if (s[x] == 'o')
    {
        bit = bit * 3 + 1;
        rec(x + 1);
        bit = (bit - 1) / 3;

        bit = bit * 3 + 2;
        rec(x + 1);
        bit = (bit - 2) / 3;
    }

    if (s[x] == 'x')
    {
        bit = bit * 3 + 1;
        rec(x + 1);
        bit = (bit - 1) / 3;
    }
}

void work2()
{
    ans = 0;
    rec(0);
    cout << ans << "\n";
}

signed main()
{
    //freopen("conspiracy.in", "r", stdin);
    //freopen("conspiracy.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    precalc();
    cin >> w >> n >> k;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        c[x]++;
    }
    work();
    while (k--)
    {
        cin >> s;
        work2();
    }
}