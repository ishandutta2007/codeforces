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
#include <deque>

ll n, m, k;
deque<int> x[301][301], y[301][301];
vector<pair<pii, pii>> p1, p2;
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            for (int k = 0; k < s.sz; k++)
                x[i][j].pb(s[k] - '0');
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            for (int k = s.sz - 1; k >= 0; k--)
                y[i][j].pb(s[k] - '0');
        }
    }
    for (int i = 1; i < n; i++)
    {
        while (x[i][0].sz > 0)
        {
            if (x[i][0][x[i][0].sz - 1] == 0)
            {
                p1.pb({{i, 0}, {0, 0}});
                x[i][0].pop_back();
                x[0][0].push_front(0);
            }
            else
            {
                p1.pb({{i, 0}, {0, 0}});
                x[i][0].pop_back();
                x[0][0].push_front(1);
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        while (x[0][i].sz > 0)
        {
            if (x[0][i][x[0][i].sz - 1] == 0)
            {
                p1.pb({{0, i}, {0, 0}});
                x[0][i].pop_back();
                x[0][0].push_front(0);
            }
            else
            {
                p1.pb({{0, i}, {0, 0}});
                x[0][i].pop_back();
                x[0][0].push_front(1);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            while (x[i][j].sz > 0)
            {
                if (x[i][j][x[i][j].sz - 1] == 0)
                {
                    p1.pb({{i, j}, {0, j}});
                    x[i][j].pop_back();
                    x[0][j].push_front(0);
                }
                else
                {
                    p1.pb({{i, j}, {i, 0}});
                    x[i][j].pop_back();
                    x[i][0].push_front(1);
                }
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        while (x[i][0].sz > 0)
        {
            if (x[i][0][x[i][0].sz - 1] == 0)
            {
                p1.pb({{i, 0}, {1, 0}});
                x[i][0].pop_back();
                x[1][0].push_front(0);
            }
            else
            {
                p1.pb({{i, 0}, {1, 0}});
                x[i][0].pop_back();
                x[1][0].push_front(1);
            }
        }
    }
    for (int i = 2; i < m; i++)
    {
        while (x[0][i].sz > 0)
        {
            if (x[0][i][x[0][i].sz - 1] == 0)
            {
                p1.pb({{0, i}, {0, 1}});
                x[0][i].pop_back();
                x[0][1].push_front(0);
            }
            else
            {
                p1.pb({{0, i}, {0, 1}});
                x[0][i].pop_back();
                x[0][1].push_front(1);
            }
        }
    }
    while (x[0][0].sz > 0)
    {
        if (x[0][0][x[0][0].sz - 1] == 0)
        {
            p1.pb({{0, 0}, {0, 1}});
            x[0][0].pop_back();
            x[0][1].push_front(0);
        }
        else
        {
            p1.pb({{0, 0}, {1, 0}});
            x[0][0].pop_back();
            x[1][0].push_front(1);
        }
    }
    for (int i = 1; i < n; i++)
    {
        while (y[i][0].sz > 0)
        {
            if (y[i][0][y[i][0].sz - 1] == 0)
            {
                p2.pb({{i, 0}, {0, 0}});
                y[i][0].pop_back();
                y[0][0].push_front(0);
            }
            else
            {
                p2.pb({{i, 0}, {0, 0}});
                y[i][0].pop_back();
                y[0][0].push_front(1);
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        while (y[0][i].sz > 0)
        {
            if (y[0][i][y[0][i].sz - 1] == 0)
            {
                p2.pb({{0, i}, {0, 0}});
                y[0][i].pop_back();
                y[0][0].push_front(0);
            }
            else
            {
                p2.pb({{0, i}, {0, 0}});
                y[0][i].pop_back();
                y[0][0].push_front(1);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            while (y[i][j].sz > 0)
            {
                if (y[i][j][y[i][j].sz - 1] == 0)
                {
                    p2.pb({{i, j}, {0, j}});
                    y[i][j].pop_back();
                    y[0][j].push_front(0);
                }
                else
                {
                    p2.pb({{i, j}, {i, 0}});
                    y[i][j].pop_back();
                    y[i][0].push_front(1);
                }
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        while (y[i][0].sz > 0)
        {
            if (y[i][0][y[i][0].sz - 1] == 0)
            {
                p2.pb({{i, 0}, {1, 0}});
                y[i][0].pop_back();
                y[1][0].push_front(0);
            }
            else
            {
                p2.pb({{i, 0}, {1, 0}});
                y[i][0].pop_back();
                y[1][0].push_front(1);
            }
        }
    }
    for (int i = 2; i < m; i++)
    {
        while (y[0][i].sz > 0)
        {
            if (y[0][i][y[0][i].sz - 1] == 0)
            {
                p2.pb({{0, i}, {0, 1}});
                y[0][i].pop_back();
                y[0][1].push_front(0);
            }
            else
            {
                p2.pb({{0, i}, {0, 1}});
                y[0][i].pop_back();
                y[0][1].push_front(1);
            }
        }
    }
    while (y[0][0].sz > 0)
    {
        if (y[0][0][y[0][0].sz - 1] == 0)
        {
            p2.pb({{0, 0}, {0, 1}});
            y[0][0].pop_back();
            y[0][1].push_front(0);
        }
        else
        {
            p2.pb({{0, 0}, {1, 0}});
            y[0][0].pop_back();
            y[1][0].push_front(1);
        }
    }
    cout << p1.sz + p2.sz << endl;
    for (int i = 0; i < p1.sz; i++)
        cout << p1[i].fi.fi + 1 << " " << p1[i].fi.se + 1 << " " << p1[i].se.fi + 1 << " " << p1[i].se.se + 1 << endl;
    cout << endl;
    for (int i = p2.sz - 1; i >= 0; i--)
        cout << p2[i].se.fi + 1 << " " << p2[i].se.se + 1 << " " << p2[i].fi.fi + 1 << " " << p2[i].fi.se + 1 << endl;
}