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
vi cx = {-1, 0, 1, 0}, cy = {0, -1, 0, 1};
//______________________
#include <deque>
#define endl "\n"
#define int long long

ll n, m, N, M;
string s[500];
ll comp[50][50];
signed main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    forn(i, n)
    {
        cin >> s[i];
    }
    forn(i, n)
    {
        forn(j, m)
        {
            if (s[i][j] == '#')
                N++;
        }
    }
    if (N <= 2)
    {
        cout << -1;
        re 0;
    }
    forn(i, n)
    {
        forn(j, m)
        {
            ll deg = 0;
            forn(k, 4)
            {
                if (correct(i + cx[k], n) && correct(j + cy[k], m) && s[i][j] == '#' && s[i + cx[k]][j + cy[k]] == '#')
                {
                    M++;
                    deg++;
                }
            }
            if (deg == 1)
            {
                cout << 1;
                re 0;
            }
        }
    }
    if (N == M + 1)
    {
        cout << 1;
        re 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
            {
                s[i][j] = '.';
                for (int i2 = 0; i2 < n; i2++)
                {
                    for (int j2 = 0; j2 < m; j2++)
                    {
                        comp[i2][j2] = 0;
                        if (s[i2][j2] == '.')
                        comp[i2][j2] = 1;
                    }
                }
                for (int i2 = 0; i2 < n; i2++)
                {
                    for (int j2 = 0; j2 < m; j2++)
                    {
                        if (s[i2][j2] == '#')
                        {
                            vector<pii> q;
                            q.pb({i2, j2});
                            comp[i2][j2] = 1;
                            for (int kk = 0; kk < q.sz; kk++)
                            {
                                ll x = q[kk].fi;
                                ll y = q[kk].se;
                                for (int k = 0; k < 4; k++)
                                {
                                    if (correct(x + cx[k], n) && correct(y + cy[k], m)
                                    && s[x + cx[k]][y + cy[k]] == '#' && comp[x + cx[k]][y + cy[k]] == 0)
                                    {
                                        comp[x + cx[k]][y + cy[k]] = 1;
                                        q.pb({x + cx[k], y + cy[k]});
                                    }
                                }
                            }
                            for (int i3 = 0; i3 < n; i3++)
                            {
                                for (int j3 = 0; j3 < m; j3++)
                                {
                                    if (comp[i3][j3] == 0)
                                    {
                                        cout << 1;
                                        re 0;
                                    }
                                }
                            }
                            break;
                        }
                        
                    }
                }
                s[i][j] = '#';
            }
        }
    }
    cout << 2;
}