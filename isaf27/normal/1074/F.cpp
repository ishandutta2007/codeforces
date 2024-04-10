/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = 1e3 + 239;
const int L = 19;
const int T = (1 << 19);
const int B = trunc(sqrt(M)) + 1;
const int X = 260;

int mx[T], add[T], kol[T];

void push(int i, int l, int r)
{
    mx[i] += add[i];
    if (r - l != 1)
    {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void build(int i, int l, int r)
{
    if (r - l == 1)
    {
        mx[i] = 0;
        add[i] = 0;
        kol[i] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    kol[i] = kol[2 * i + 1] + kol[2 * i + 2];
}

void plus_tree(int i, int l, int r, int ql, int qr, int x)
{
    push(i, l, r);
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr)
    {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    plus_tree(2 * i + 1, l, mid, ql, qr, x);
    plus_tree(2 * i + 2, mid, r, ql, qr, x);
    mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
    kol[i] = 0;
    if (mx[i] == mx[2 * i + 1])
        kol[i] += kol[2 * i + 1];
    if (mx[i] == mx[2 * i + 2])
        kol[i] += kol[2 * i + 2];
}

int n, q, it, a[M], l[M], r[M], h[M], dp[L][M];
vector<int> v[M];

void dfs(int p, int pr, int d)
{
    if (pr == -1)
    {
        for (int i = 0; i < L; i++)
            dp[i][p] = 0;
    }
    else
    {
        dp[0][p] = pr;
        for (int i = 1; i < L; i++)
            dp[i][p] = dp[i - 1][dp[i - 1][p]];
    }
    h[p] = d;
    l[p] = it;
    a[it++] = p;
    for (int i : v[p])
        if (i != pr)
            dfs(i, p, d + 1);
    r[p] = it;
}

int upper(int s, int f)
{
    for (int i = L - 1; i >= 0; i--)
    {
        int to = dp[i][s];
        if (l[to] <= l[f] && r[f] <= r[to]) continue;
        s = to;
    }
    return s;
}

void add_edge(int s, int f, int pl)
{
    if (h[s] < h[f]) swap(s, f);
    if (l[f] <= l[s] && r[s] <= r[f])
    {
        plus_tree(0, 0, n, 0, n, pl);
        int t = upper(s, f);
        plus_tree(0, 0, n, l[t], r[t], -pl);
        plus_tree(0, 0, n, l[s], r[s], pl);
    }
    else
    {
        plus_tree(0, 0, n, l[s], r[s], pl);
        plus_tree(0, 0, n, l[f], r[f], pl);
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < (n - 1); i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    it = 0;
    dfs(0, -1, 0);
    build(0, 0, n);
    set<pair<int, int> > rb;
    for (int i = 0; i < q; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        if (s > f) swap(s, f);
        if (rb.find(make_pair(s, f)) == rb.end())
        {
            rb.insert(make_pair(s, f));
            add_edge(s, f, 1);
        }
        else
        {
            rb.erase(make_pair(s, f));
            add_edge(s, f, -1);
        }
        if (mx[0] != rb.size())
            cout << "0\n";
        else
            cout << kol[0] << "\n";
    }
    return 0;
}