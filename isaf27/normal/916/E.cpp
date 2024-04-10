#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 1e5 + 10;
const int MAX_M = 2 * MAX_N;
const int MAX_T = (1 << 18);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

vector<vector<int> > vn(MAX_N);
int gl[MAX_N], first[MAX_N], how[MAX_M], n, q, k, tin[MAX_N], tout[MAX_N], time_now, root, up[MAX_LOG][MAX_N];
pair<int, int> dp[MAX_LOG][MAX_M];
vector<bool> used;
vector<int> et;
int lt[MAX_N], rt[MAX_N], pos[MAX_N], a[MAX_N];
vector<ll> arr;
ll tree[MAX_T], add[MAX_T];

void build(int i, int l, int r)
{
    if (r - l == 1)
    {
        tree[i] = arr[l];
        add[i] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    add[i] = 0;
}

void push(int i, int l, int r)
{
    tree[i] += add[i] * (ll)(r - l);
    if (r - l != 1)
    {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

ll gett(int i, int l, int r, int ql, int qr)
{
    push(i, l, r);
    if (qr <= l || r <= ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[i];
    int mid = (l + r) >> 1;
    return (gett(2 * i + 1, l, mid, ql, qr) + gett(2 * i + 2, mid, r, ql, qr));
}

void upd(int i, int l, int r, int ql, int qr, ll x)
{
    push(i, l, r);
    if (qr <= l || r <= ql)
        return;
    if (ql <= l && r <= qr)
    {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * i + 1, l, mid, ql, qr, x);
    upd(2 * i + 2, mid, r, ql, qr, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

void dfs(int p, int f, int pr)
{
    up[0][p] = pr;
    for (int i = 1; i < MAX_LOG; i++)
        up[i][p] = up[i - 1][up[i - 1][p]];
    used[p] = true;
    tin[p] = time_now;
    lt[p] = time_now;
    pos[p] = arr.size();
    arr.push_back(a[p]);
    time_now++;
    first[p] = et.size();
    et.push_back(p);
    gl[p] = f;
    for (int i : vn[p])
        if (!used[i])
        {
            dfs(i, f + 1, p);
            et.push_back(p);
        }
    tout[p] = time_now;
    rt[p] = time_now - 1;
}

bool upper(int u, int v)
{
    return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

int lca(int u, int v)
{
    if (first[u] > first[v])
        swap(u, v);
    int l = first[u];
    int r = first[v];
    int len = r - l + 1;
    int e = how[len];
    pair<int, int> ans = min(dp[e][l], dp[e][r + 1 - (1 << e)]);
    return ans.second;
}

int func(int s, int f)
{
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (!upper(up[i][f], s))
            f = up[i][f];
    return f;
}

int correct_lca(int u, int v)
{
    bool fu = upper(root, u);
    bool fv = upper(root, v);
    if (fu && fv)
        return lca(u, v);
    if (fu || fv)
        return root;
    int un = lca(root, u);
    int vn = lca(root, v);
    if (un == vn)
        return lca(u, v);
    if (gl[un] < gl[vn])
        swap(un, vn);
    return un;
}

void plus_on_good(int s, ll x)
{
    upd(0, 0, n, lt[s], rt[s] + 1, x);
}

void plus_in_vertex(int s, ll x)
{
    upd(0, 0, n, pos[s], pos[s] + 1, x);
}

ll in_vertex(int s)
{
    return gett(0, 0, n, pos[s], pos[s] + 1);
}

ll query_good(int s)
{
    return gett(0, 0, n, lt[s], rt[s] + 1);
}

void plus_on(int s, ll x)
{
    if (s == root)
    {
        plus_on_good(0, x);
        return;
    }
    if (upper(s, root))
    {
        plus_on_good(func(s, root), -x);
        plus_on_good(0, x);
        return;
    }
    plus_on_good(s, x);
}

ll query(int s)
{
    if (s == root)
        return query_good(0);
    if (upper(s, root))
        return (query_good(0) - query_good(func(s, root)));
    return query_good(s);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    time_now = 0;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    used.clear();
    used.resize(n);
    for (int i = 0; i < n; i++)
        used[i] = false;
    vn.clear();
    vn.resize(n);
    et.clear();
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        vn[s].push_back(f);
        vn[f].push_back(s);
    }
    dfs(0, 0, 0);
    k = et.size();
    for (int i = 0; i < k; i++)
        dp[0][i] = make_pair(gl[et[i]], et[i]);
    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 0; j < k; j++)
        {
            int st = (1 << (i - 1));
            if (st + j >= k)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][st + j]);
        }
    how[1] = 0;
    for (int i = 2; i <= k; i++)
    {
        how[i] = how[i - 1];
        if ((1 << (how[i] + 1)) == i)
            how[i]++;
    }
    build(0, 0, n);
    root = 0;
    for (int z = 0; z < q; z++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p;
            cin >> p;
            p--;
            root = p;
        }
        else if (t == 2)
        {
            int s, f, x;
            cin >> s >> f >> x;
            s--, f--;
            int to = correct_lca(s, f);
            //cerr << to + 1 << "\n";
            plus_on(to, x);
        }
        else
        {
            int s;
            cin >> s;
            s--;
            cout << query(s) << "\n";
        }
    }
    return 0;
}