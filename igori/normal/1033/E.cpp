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
ll n, m, k;
map<vi, int> mm;

ll q(vector<int> a, vector<int> b)
{
    if (a.sz + b.sz == 1)
        re 0;
    vector<int> c;
    for (int i = 0; i < a.sz; i++)
        c.pb(a[i]);
    for (int i = 0; i < b.sz; i++)
        c.pb(b[i]);
    sort(all(c));
    if (mm[c] != 0)
        re mm[c] - 1;
    cout << "? " << a.sz + b.sz << endl;
    for (int i = 0; i < a.sz; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < b.sz; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    ll x;
    cin >> x;
    mm[c] = x + 1;
    re x;
}

ll q(vector<int> a)
{
    if (a.sz == 1)
        re 0;
    sort(all(a));
    if (mm[a] != 0)
        re mm[a] - 1;
    cout << "? " << a.sz << endl;
    for (int i = 0; i < a.sz; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    ll x;
    cin >> x;
    mm[a] = x + 1;
    re x;
}

pair<int, int> find_edge_between(vector<int> a, vector<int> b)
{
    if (a.sz == 0 || b.sz == 0)
    {
        return {-1, -1};
    }
    if (a.sz == 1 && b.sz == 1)
    {
        vector<int> c;
        c.pb(a[0]);
        c.pb(b[0]);
        if (q(c))
        return {a[0], b[0]};
        else
        return {-1, -1};
    }
    if (b.sz == 1)
    {
        swap(a, b);
    }
    vector<int> c, d;
    for (int i = 0; i < b.sz / 2; i++)
        c.pb(b[i]);
    for (int i = b.sz / 2; i < b.sz; i++)
        d.pb(b[i]);
    if (q(a, c) > q(a) + q(c))
        return find_edge_between(a, c);
    else
        return find_edge_between(a, d);
}

vector<int> graph[700];

void spawning_tree()
{
    vector<int> x;
    vector<int> is(700);
    is[1] = 1;
    x.pb(1);
    while (x.sz != n)
    {
        vector<int> y;
        for (int i = 1; i <= n; i++)
        {
            if (!(is[i]))
                y.pb(i);
        }
        pii e = find_edge_between(x, y);
        pii no = {-1, -1};
        if (no == e)
            break;
        if (is[e.fi])
        {
            is[e.se] = 1;
            x.pb(e.se);
            graph[e.fi].pb(e.se);
            graph[e.se].pb(e.fi);
        }
        else
        {
            is[e.fi] = 1;
            x.pb(e.fi);
            graph[e.fi].pb(e.se);
            graph[e.se].pb(e.fi);
        }
    }
}

ll c[700];
vector<int> p1;
vector<int> p2;

void dfs(int x, int fl)
{
    c[x] = 1;
    if (fl == 1)
        p1.pb(x);
    else
        p2.pb(x);
    for (int i = 0; i < graph[x].sz; i++)
    {
        ll u = graph[x][i];
        if (c[u] == 0)
        {
            dfs(u, 1 - fl);
        }
    }
}

ll beg, en;
ll pmt = 0;
vi cc;
ll prev[5000];

void dfs(int x, int pr, int q)
{
    prev[x] = pr;

    if (pmt == 1)
        return;

    c[x] = 2;
    for (int i = 0; i < graph[x].sz; i++)
    {
        ll u = graph[x][i];
        if (c[u] != 2)
        {
            prev[u] = x;
            if (u == en && pmt == 0)
            {
                vector <int> cnts(4000);
                while (u != beg)
                {
                    cc.pb(u);
                    cnts[u]++;
                    u = prev[u];
                    if (cnts[u] > 0)
                        break;
                }
                if (cnts[beg] == 0)
                    cc.pb(beg);
                pmt = 1;
                return;
            }
            dfs(u, x, INF);
        }
    }
}

signed main()
{
    //freopen("conspiracy.in", "r", stdin);
    //freopen("conspiracy.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if (n == 1)
    {
        cout << "Y 1" << endl;
        cout << 1 << endl;
        re 0;
    }
    spawning_tree();

    dfs(1, 1);

    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < graph[i].sz; j++)
        {
            ll u = i;
            ll v = graph[i][j];
            cout << u << " " << v << endl;
        }
    }
    for (int i = 0; i < p1.sz; i++)
    {
        cout << p1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < p2.sz; i++)
    {
        cout << p2[i] << " ";
    }
    cout << endl;
    cout << endl << endl;*/
    pii no = {-1, -1};
    if (q(p1) == 0 && q(p2) == 0)
    {
        cout << "Y " << p1.sz << endl;
        for (int i = 0; i < p1.sz; i++)
        {
            cout << p1[i] << " ";
        }
        cout << endl;
        re 0;
    }
    if (q(p1) == 0)
    {
        swap(p1, p2);
    }
    ll y = 0;
    for (int i = max(1, p1.sz - 1); i < p1.sz; i++)
    {
        vector<int> q1, q2;
        for (int j = 0; j < i; j++)
            q1.pb(p1[j]);
        for (int j = i; j < p1.sz; j++)
            q2.pb(p1[j]);
        pii F = find_edge_between(q1, q2);
        if (F != no)
        {
            //cout << "EDGE : " << F.fi << " " << F.se << endl;
            graph[F.fi].pb(F.se);
            graph[F.se].pb(F.fi);
            beg = F.fi;
            en = F.se;
            y = 1;
            break;
        }
    }
    if (y == 0)
    {
        for (int i = 1; i < p1.sz; i++)
        {
            vector<int> q1, q2;
            for (int j = 0; j < i; j++)
                q1.pb(p1[j]);
            for (int j = i; j < p1.sz; j++)
                q2.pb(p1[j]);
            pii F = find_edge_between(q1, q2);
            if (F != no)
            {
                //cout << "EDGE : " << F.fi << " " << F.se << endl;
                graph[F.fi].pb(F.se);
                graph[F.se].pb(F.fi);
                beg = F.fi;
                en = F.se;
                y = 1;
                break;
            }
        }
    }
    //cout << "DESC " << beg << " " << en << endl << endl;
    dfs(beg, -INF, INF);
    cout << "N " << cc.sz << endl;
    for (int i = 0; i < cc.sz; i++)
    {
        cout << cc[i] << " ";
    }
    cout << endl;
}