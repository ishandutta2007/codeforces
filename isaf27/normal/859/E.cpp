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
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
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
const int MAX_N = 2 * 1e5 + 1;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 21;
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

int n;
vector<vector<int> > v(MAX_N);
ll kol[MAX_N];
bool used[MAX_N];
bool can[MAX_N];
int color[MAX_N];
vector<int> now;
vector<int> cyc;
vector<int> st;

ll power(ll a, int b)
{
    if (b == 0)
        return 1;
    ll x = power(a, b >> 1);
    x = (x * x) % MOD;
    if (b & 1)
        x = (x * a) % MOD;
    return x;
}

void fndcyc(int t)
{
    cyc.clear();
    bool dd = false;
    for (int i : st)
    {
        if (!dd && i == t)
            dd = true;
        if (dd)
            cyc.push_back(i);
    }
}

void dfs(int p, int ls)
{
    used[p] = true;
    st.push_back(p);
    now.push_back(p);
    color[p] = 1;
    bool fnd = false;
    for (int i : v[p])
    {
        if (i == ls && !fnd)
        {
            fnd = true;
            continue;
        }
        if (color[i] == 1)
        {
            fndcyc(i);
        }
        if (!used[i])
            dfs(i, p);
    }
    st.pop_back();
    color[p] = 2;
}

void dfs_comp(int p)
{
    can[p] = true;
    vector<int> to;
    for (int i : v[p])
        if (!can[i])
            to.push_back(i);
    if (to.empty())
    {
        kol[p] = 0;
        return;
    }
    for (int i : to)
        dfs_comp(i);
    kol[p] = 0;
    for (int i : to)
        kol[p] = (kol[p] + 1 + kol[i]) % MOD;
}

ll compute(int x)
{
    cyc.clear();
    now.clear();
    st.clear();
    dfs(x, -1);
    for (int i : cyc)
        can[i] = true;
    for (int i : cyc)
        dfs_comp(i);
    if (cyc.empty())
        dfs_comp(x);
    if (cyc.empty())
        return (1 + kol[x]) % MOD;
    if (cyc.size() == 1)
        return 1;
    return 2;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        //if (a == b)
        //    continue;
        v[a].push_back(b);
        v[b].push_back(a);
        if (a == b)
            v[b].pop_back();
    }
    memset(used, 0, sizeof(used));
    memset(can, 0, sizeof(can));
    memset(color, 0, sizeof(color));
    ll ans = 1;
    for (int i = 0; i < 2 * n; i++)
        if (!used[i])
            ans = (ans * compute(i)) % MOD;
    cout << ans;
    return 0;
}