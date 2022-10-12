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

#include <deque>
#define endl "\n"
#define int long long
#define double long double

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
ll n;
pair<ll, ll> xy[500000];

const double eps = 1e-5;

struct Line{
    ll x1, y1, x2, y2;
};
vector<Line> ch;

bool under(int x, int y, int x1, int y1, int x2, int y2)
{
    double k = (double)(y1 - y2) / (x1 - x2);
    double b = y1 - k * x1;
    double yX = k * x + b;
    if (yX >= y - eps)
        return 1;
    return 0;
}

bool try_to_add(int i)
{
    int X = xy[i].first;
    int Y = xy[i].second;
    int X1 = ch[ch.size() - 1].x1;
    int Y1 = ch[ch.size() - 1].y1;
    int X2 = ch[ch.size() - 1].x2;
    int Y2 = ch[ch.size() - 1].y2;
    if (under(X2, Y2, X1, Y1, X, Y))
    {
        ch.pop_back();
        return 0;
    }
    return 1;
}

void add(int i)
{
    while (ch.size() >= 1)
    {
        if (try_to_add(i))
        {
            ch.push_back({ch[ch.size() - 1].x2, ch[ch.size() - 1].y2, xy[i].first, xy[i].second});
            return;
        }
    }
    ch.push_back({xy[0].first, xy[0].second, xy[i].first, xy[i].second});
    return;
}

signed main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> xy[i].first >> xy[i].second;
        xy[i].second -= xy[i].first * xy[i].first;
        //cout << xy[i].fi << " " << xy[i].se << endl;
    }
    sort(xy, xy + n);
    vector<pii> xy2;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n || xy[i + 1].first != xy[i].first)
        {
            xy2.push_back(xy[i]);
        }
    }
    n = xy2.size();
    for (int i = 0; i < n; i++)
    {
        xy[i] = xy2[i];
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    ch.push_back({xy[0].first, xy[0].second, xy[1].first, xy[1].second});
    for (int i = 2; i < n; i++)
    {
        add(i);
    }
    for (int i = 0; i < ch.size(); i++)
    {
        //cout << ch[i].x1 << " " << ch[i].y1 << " " << ch[i].x2 << " " << ch[i].y2 << endl;
    }
    cout << ch.size() << endl;
}