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
struct Matrix{
    ll a, b;
    vector<vector<ll>> x;
    Matrix(int a_, int b_)
    {
        a = a_;
        b = b_;
        x.resize(a);
        forn(i, a)
        {
            x[i].resize(b);
        }
    }
};

Matrix MatrixMultiplication(Matrix M, Matrix N)
{
    if (M.b != N.a)
    {
        exit(0);
    }
    ll k = M.b;
    Matrix K(M.a, N.b);
    for (int i = 0; i < M.a; i++)
    {
        for (int j = 0; j < N.b; j++)
        {
            for (int q = 0; q < k; q++)
            {
                K.x[i][j] += M.x[i][q] * N.x[q][j];
                K.x[i][j] %= MOD;
            }
        }
    }
    re K;
}

Matrix inqMatrix(Matrix A, ll q)
{
    if (q == 0)
    {
        if (A.a == A.b)
        {
            Matrix C(A.a, A.b);
            for (int i = 0; i < A.a; i++)
            {
                C.x[i][i] = 1;
            }
            re C;
        }
        else
        {
            exit(0);
        }
    }
    if (q == 1)
    {
        re A;
    }
    Matrix L = inqMatrix(A, q / 2);
    L = MatrixMultiplication(L, L);
    if (q % 2 != 0)
        L = MatrixMultiplication(L, A);
    re L;
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
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
ll n, m, k;

struct req{
    int a, b, c;
    req(int a_, int b_, int c_)
    {
        a = a_;
        b = b_;
        c = c_;
    }
};

vector<int> graph[500000];
ll dist1[500000];
ll dist2[500000];
ll dist3[500000];
ll deg[500000];
ll res;
vector<req> ans;

void bfs1(int x)
{
    vector<int> q;
    q.pb(x);
    dist1[x] = 1;
    for (int i = 0; i < q.sz; i++)
    {
        int u = q[i];
        for (int j = 0; j < graph[u].sz; j++)
        {
            int v = graph[u][j];
            if (dist1[v] == 0)
            {
                dist1[v] = dist1[u] + 1;
                q.pb(v);
            }
        }
    }
}

void bfs2(int x)
{
    vector<int> q;
    q.pb(x);
    dist2[x] = 1;
    for (int i = 0; i < q.sz; i++)
    {
        int u = q[i];
        for (int j = 0; j < graph[u].sz; j++)
        {
            int v = graph[u][j];
            if (dist2[v] == 0)
            {
                dist2[v] = dist2[u] + 1;
                q.pb(v);
            }
        }
    }
}

void bfs3(int x)
{
    vector<int> q;
    q.pb(x);
    dist3[x] = 1;
    for (int i = 0; i < q.sz; i++)
    {
        int u = q[i];
        for (int j = 0; j < graph[u].sz; j++)
        {
            int v = graph[u][j];
            if (dist3[v] == 0)
            {
                dist3[v] = dist3[u] + 1;
                q.pb(v);
            }
        }
    }
}

signed main()
{
    //freopen("conspiracy.in", "r", stdin);
    //freopen("conspiracy.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    forn(i, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    bfs1(1);
    ll f1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dist1[i] > dist1[f1])
        {
            f1 = i;
        }
    }
    bfs2(f1);
    ll f2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dist2[i] > dist2[f2])
        {
            f2 = i;
        }
    }
    bfs3(f2);
    vector<int> waiting;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1 && i != f1 && i != f2)
            waiting.pb(i);
    }
    for (int i = 0; i < waiting.sz; i++)
    {
        ll v = waiting[i];
        ll d1 = dist2[v];
        ll d2 = dist3[v];
        if (d1 > d2)
        {
            req A(f1, v, v);
            ans.pb(A);
            res += d1 - 1;
        }
        else
        {
            req A(f2, v, v);
            ans.pb(A);
            res += d2 - 1;
        }
        for (int j = 0; j < graph[v].sz; j++)
        {
            ll u = graph[v][j];
            deg[u]--;
            if (deg[u] == 1)
                waiting.pb(u);
        }
    }
    waiting.resize(0);
    waiting.pb(f2);
    for (int i = 0; i < waiting.sz; i++)
    {
        ll v = waiting[i];
        ll d1 = dist2[v];
        req A(f1, v, v);
        ans.pb(A);
        res += d1 - 1;
        for (int j = 0; j < graph[v].sz; j++)
        {
            ll u = graph[v][j];
            deg[u]--;
            if (deg[u] == 1)
                waiting.pb(u);
        }
    }
    cout << res << "\n";
    forn(i, ans.sz)
    {
        cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << "\n";
    }
}