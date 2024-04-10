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
#define all(v) v.begin(), v.end()
#define random srand(time(NULL))
#define rand_int ((rand() << 15) | rand())
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
//string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
//template< typename T >
//T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
template< typename T >
bool is_prime_sqrt(T n)
{
    if (n == 1)
        return false;
    T k = trunc(sqrt(n));
    for (T i = 2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
string follow(string s) { for (int i = 0; i < s.length(); i++) if (is_upper(s[i])) s[i] += 'a' - 'A'; return s; }

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
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 1e5 + 1;
const int MAX_M = 2 * MAX_N + 100;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 18;
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
const int bt = 31;

// Code starts here

struct dsu
{
    vector<int> parent, r;

    dsu()
    {
        parent = r = {};
    }

    dsu(int n)
    {
        parent.resize(n);
        r.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i, r[i] = 0;
    }

    int find_set(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find_set(parent[a]);
    }

    void merge_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (r[a] >= r[b])
            swap(a, b);
        parent[a] = b;
        if (r[a] == r[b])
            r[b]++;
    }

    bool is_connect(int a, int b)
    {
        return find_set(a) == find_set(b);
    }
};

vector<vector<int> > v(MAX_N);
vector<vector<int> > tp(MAX_N);
int gl[MAX_N], first[MAX_N], how[MAX_M], n, m, k, tin[MAX_N], tout[MAX_N], timer, pref[MAX_N];
pair<int, int> dp[MAX_LOG][MAX_M];
vector<int> et;
dsu c;

void dfs(int p, int f)
{
    first[p] = et.size();
    et.push_back(p);
    gl[p] = f;
    tin[p] = timer++;
    int it = 0;
    for (int i : v[p])
    {
        pref[i] = pref[p] + tp[p][it];
        dfs(i, f + 1);
        et.push_back(p);
        it++;
    }
    tout[p] = timer;
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

bool is_good(int s, int f)
{
    return (tin[s] <= tin[f] && tout[f] <= tout[s]);
}

bool is_all_zeroes(int s, int f)
{
    if (!is_good(s, f))
        return false;
    return (pref[s] == pref[f]);
}

bool is_all_ones(int s, int f)
{
    if (!is_good(s, f))
        return false;
    return (pref[f] - pref[s] == gl[f] - gl[s]);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    timer = 0;
    vector<int> fr;
    scanf("%d", &n);
    c = dsu(n);
    for (int i = 0; i < n; i++)
    {
        int t, s;
        scanf("%d%d", &t, &s);
        t--;
        if (t == -2)
        {
            fr.push_back(i);
            continue;
        }
        v[t].push_back(i);
        c.merge_set(t, i);
        tp[t].push_back(s);
    }
    for (int i : fr)
    {
        dfs(i, 0);
        pref[i] = 0;
    }
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
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int t, s, f;
        scanf("%d%d%d", &t, &s, &f);
        s--, f--;
        if (s == f)
        {
            cout << "NO\n";
            continue;
        }
        if (!c.is_connect(s, f))
        {
            cout << "NO\n";
            continue;
        }
        if (t == 1)
            cout << (is_all_zeroes(s, f) ? "YES\n" : "NO\n");
        else
        {
            int r = lca(s, f);
            if (r == f)
            {
                cout << "NO\n";
                continue;
            }
            cout << ((is_all_zeroes(r, s) && is_all_ones(r, f)) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}