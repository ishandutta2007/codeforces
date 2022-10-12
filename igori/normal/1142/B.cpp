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
#define endl "\n"
#define int long long
long long n, m, q;
ll p[500000];
ll a[500000];
ll fm[500000];
int go[20][300000];
int last_pos[500000];
int pos[500000];
int dist[500000];
int sparce[20][300000];
int H[500000];

int get(int l, int r)
{
    int h = H[r - l + 1];
    return min(sparce[h][l], sparce[h][r - (1 << h) + 1]);
}

signed main()
{
    H[1] = 0;
    H[2] = 0;
    H[3] = 1;
    for (int i = 4; i <= 400000; i++)
    {
        H[i] = H[i - 1];
        if (((i - 1) & (i - 2)) == 0)
            H[i]++;
    }
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    p[n + 1] = p[1];
    for (int j = 1; j <= m; j++)
    {
        cin >> a[j];
    }
    for (int j = m; j >= 1; j--)
    {
        last_pos[a[j]] = j;
        int num = pos[a[j]];
        int look = p[num + 1];
        //cout << look << endl;
        if (last_pos[look] != 0)
        {
            go[0][j] = last_pos[look];
        }
        else
        {
            go[0][j] = m + 1;
        }
    }
    for (int j = 0; j < 20; j++)
        go[j][m + 1] = m + 1;
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            int p1 = go[j - 1][i];
            int p2 = go[j - 1][p1];
            go[j][i] = p2;
        }
    }
    long long h = n - 1;
    dist[0] = 1;
    for (int j = 1; j < 20; j++)
        dist[j] = dist[j - 1] * 2;
    for (int i = 1; i <= m; i++)
    {
        int g = h, j = 19;
        int res = i;
        while (g >= 1)
        {
            if (dist[j] <= g)
            {
                g -= dist[j];
                res = go[j][res];
            }
            j--;
        }
        sparce[0][i] = res;
        fm[i] = res;
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= m; i++)
        {
            sparce[j][i] = get(i, i + (1 << j) - 1);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (get(l, r) <= r)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}