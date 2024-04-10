//Updated 29.09.18
//#pragma GCC optimize ("O2")
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
//___________________
#define int long long
int n, m;

struct Node{
    int L, R;
    ll res;
    ll upd;
};

vector<Node> segment(2010000);
ll tourist;

void build(int L, int R, int v)
{
    segment[v].L = L;
    segment[v].R = R;
    int M = (L + R) / 2;
    if (L + 1 >= R)
    {
        return;
    }
    build(L, M, 2 * v + 1);
    build(M, R, 2 * v + 2);
}

void push(int v)
{
    segment[2 * v + 1].res += segment[v].upd;
    segment[2 * v + 2].res += segment[v].upd;
    segment[2 * v + 1].upd += segment[v].upd;
    segment[2 * v + 2].upd += segment[v].upd;
    segment[v].upd = 0;
}

void add(int l, int r, int v, int w)
{
    if (l >= r)
        return;
    int L = segment[v].L;
    int R = segment[v].R;
    if (r <= L || R <= l)
        return;
    if (l <= L && R <= r)
    {
        segment[v].res += w;
        segment[v].upd += w;
        return;
    }
    push(v);
    add(l, r, 2 * v + 1, w);
    add(l, r, 2 * v + 2, w);
    push(v);
    segment[v].res = min(segment[2 * v + 1].res, segment[2 * v + 2].res);
}

ll get(int l, int r, int v)
{
    int L = segment[v].L;
    int R = segment[v].R;
    if (r <= L || R <= l)
        return INFLL;
    if (l <= L && R <= r)
        return segment[v].res;
    push(v);
    return min(get(l, r, 2 * v + 1), get(l, r, 2 * v + 2));
}

struct query{
    ll v, l, r, num;
};
bool comp(query a1, query a2){
    return a1.v < a2.v;
}

ll ans[900000];
ll p[501000], w[501000];
vector<pair<ll, ll> > graph[501000];
vector<query> s;
long long std_tree[501000];
long long ukaz[501000];

void dp(int v, ll value)
{
    std_tree[v] = value;
    for (int i = 0; i < graph[v].size(); i++)
    {
        dp(graph[v][i].first, graph[v][i].second + value);
    }
    return;
}

int VERTEX = 1;
int last_[501000];

void dp2(int v)
{
    last_[v] = v;
    for (int i = 0; i < graph[v].size(); i++)
    {
        dp2(graph[v][i].first);
        last_[v] = last_[graph[v][i].first];
    }
    //cout << v << " " << last_[v] << endl;
}

void go(int v)
{
    int l = VERTEX + 1;
    int r = last_[VERTEX];
    //cout << VERTEX << " " << l << " " << r << " " << v << endl;
    if (v == VERTEX)
        return;
    if (l <= v && v <= r)
    {
        ll ww = graph[VERTEX][ukaz[VERTEX]].second;
        VERTEX = graph[VERTEX][ukaz[VERTEX]].first;
        add(VERTEX, last_[VERTEX] + 1, 0, -2 * ww);
        tourist += ww;
        ukaz[p[VERTEX]]++;
    }
    else
    {
        add(VERTEX, last_[VERTEX] + 1, 0, 2 * w[VERTEX]);
        tourist -= w[VERTEX];
        VERTEX = p[VERTEX];
    }
    go(v);
}

void solve()
{
    dp(1, 0);
    dp2(1);
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 0)
        {
            add(i, i + 1, 0, std_tree[i]);
        }
        else
        {
            add(i, i + 1, 0, INFLL);
        }
        //cout << get(i, i + 1, 0) << " ";
    }
    //cout << endl << get(1, n + 1, 0) << endl;
    for (int i = 0; i < m; i++)
    {
        go(s[i].v);
        ans[s[i].num] = tourist + get(s[i].l, s[i].r + 1, 0);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    build(0, 500002, 0);
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i] >> w[i];
        graph[p[i]].push_back({i, w[i]});
    }
    for (int i = 0; i < m; i++)
    {
        int v, l, r;
        cin >> v >> l >> r;
        s.push_back({v, l, r, i});
    }
    sort(all(s), comp);
    solve();
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }
}