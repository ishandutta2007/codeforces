//Updated 29.09.18
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O2")
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
#define mm(k) memset((k), 0, sizeof(k));
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i+=1)
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
const int MAX = 100001;
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
    for (int i = 0; y < 1e18; i+=1)
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
    for (int i = 0; i < 10; i+=1)
    c[i] = 0;
    for (int i = 0; x > 0; i+=1)
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
#define ll int
ll n, m;
ll cr = 0;
ll a[200000];
vector<int> graph[500000];
ll in[200000];
ll h[200000];
ll out[200000];
ll t = 1;
const ll K = 1670;
ll ch[200000];
ll x[200000];
ll val[200000];
ll vis[200000];

void dfs(int v)
{
    in[v] = t++;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (in[u] == 0)
        {
            dfs(u);
        }
    }
    out[v] = t++;
}

void dfs(int v, int value)
{
    value *= -1;
    value += ch[v];
    a[v] += value;
    vis[v] = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (vis[u] == 0)
        {
            dfs(u, value);
        }
    }
}

void bfs(int v)
{
    vector<int> s;
    s.push_back(v);
    h[v] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i];
        for (int j = 0; j < graph[x].size(); j++)
        {
            int y = graph[x][j];
            if (h[y] == 0)
            {
                h[y] = h[x] + 1;
                s.push_back(y);
            }
        }
    }
}

void upd()
{
    dfs(0, 0);
    mm(ch);
    mm(vis);
}

bool pred(int x, int y)
{
    return (in[x] <= in[y] && out[y] <= out[x]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    forn(i, n - 1)
    {
        int v, u;
        scanf("%d %d", &u, &v);
        v--, u--;
        graph[v].pb(u);
        graph[u].pb(v);
    }
    dfs(0);
    bfs(0);
    int j = 0;
    for (int i = 0; i + j < m; i++)
    {
        if (i % K == 0 && i > cr)
        {
            upd();
            cr = i;
        }
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d %d", &x[i], &val[i]);
            x[i]--;
            ch[x[i]] += val[i];
        }
        else
        {
            int X;
            scanf("%d", &X);
            X--;
            int res = a[X];
            for (int j = cr; j < i; j++)
            {
                if (val[j] != 0)
                {
                    if (pred(x[j], X))
                    {
                        if (abs(h[X] - h[x[j]]) % 2 == 0)
                        {
                            res += val[j];
                            //cout << val[j] << " ";
                        }
                        else
                        {
                            res -= val[j];
                            //cout << -val[j] << " ";
                        }
                    }
                }
            }
            printf("%d ", res);
            i--;
            j++;
        }
    }
}