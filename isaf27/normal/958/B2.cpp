//isaf27

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
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
const ld eps = 1e-12;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 80;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

int n, dist[M], pr[M], l[M], r[M];
bool used[M];
vector<vector<int> > v(M);
vector<int> ls;

void dfs(int p, int ls, int d)
{
    dist[p] = d;
    for (int i : v[p])
        if (i != ls)
            dfs(i, p, d + 1);
}

void dfs_ans(int p, int lsg, int d)
{
    pr[p] = lsg;
    dist[p] = d;
    l[p] = ls.size();
    for (int i : v[p])
        if (i != lsg)
            dfs_ans(i, p, d + 1);
    if (v[p].size() == 1 && v[p][0] == lsg)
        ls.push_back(p);
    r[p] = ls.size();
}

pair<int, int> tree[T];
int add[T];

void build(int i, int l, int r)
{
    add[i] = 0;
    if (r - l == 1)
    {
        tree[i] = make_pair(dist[ls[l]], ls[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

void push(int i, int l, int r)
{
    tree[i].first += add[i];
    if (r - l != 1)
    {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void upd(int i, int l, int r, int ql, int qr, int x)
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
    upd(2 * i + 1, l, mid, ql, qr, x);
    upd(2 * i + 2, mid, r, ql, qr, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int ans[M];

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    dfs(0, -1, 0);
    int t = 0;
    for (int i = 0; i < n; i++)
        if (dist[i] > dist[t])
            t = i;
    dfs_ans(t, -1, 0);
    build(0, 0, ls.size());
    ans[0] = 1;
    used[t] = true;
    for (int i = 0; i < n - 1; i++)
    {
        ans[i + 1] = ans[i];
        int p = tree[0].second;
        int gt = dist[p];
        vector<int> now;
        while (!used[p])
        {
            used[p] = true;
            now.push_back(p);
            p = pr[p];
        }
        ans[i + 1] += now.size();
        for (int i : now)
            upd(0, 0, ls.size(), l[i], r[i], -1);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}