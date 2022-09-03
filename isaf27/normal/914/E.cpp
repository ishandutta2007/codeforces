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
//template< typename T >
//T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
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
const int MAX_N = 2 * 1e5 + 10;
const int MAX_M = 1011;
const int MAX_T = (1 << 20) + 100;
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

int pr[MAX_N], n, kol[MAX_N], mask[MAX_N], nw[MAX_N];
vector<vector<int> > v(MAX_N);
ll ans[MAX_N], in[MAX_N], al[MAX_T];
vector<int> now;
vector<int> ok;

void dfs(int p, int last, int xr)
{
    now.push_back(p);
    kol[p] = 1;
    nw[p] = xr;
    for (int i : v[p])
        if (i != last && pr[i] == -2)
        {
            dfs(i, p, xr ^ mask[i]);
            kol[p] += kol[i];
        }
}

void dfs_fnd(int p, int last)
{
    now.push_back(p);
    for (int i : v[p])
        if (i != last && pr[i] == -2)
            dfs_fnd(i, p);
}

void dfs_run(int p, int last)
{
    now.push_back(p);
    for (int i : v[p])
        if (i != last && pr[i] == -2)
        {
            dfs_run(i, p);
            in[p] += in[i];
        }
}

int centroid(int p, int last, int n)
{
    for (int i : v[p])
        if (i != last && pr[i] == -2)
        {
            if (kol[i] > n / 2)
                return centroid(i, p, n);
        }
    return p;
}

void find_centroid(int p, int last)
{
    now.clear();
    dfs(p, -1, 0);
    int to = centroid(p, -1, kol[p]);
    now.clear();
    dfs(to, -1, 0);
    for (int i : now)
        in[i] = 0;
    for (int i : now)
        if (__builtin_popcount(nw[i] ^ mask[to]) <= 1)
            in[i]++;
    for (int i : now)
        if (i != to)
            al[nw[i]]++;
    for (int i : v[to])
        if (pr[i] == -2)
        {
            now.clear();
            dfs_fnd(i, to);
            for (int x : now)
                al[nw[x]]--;
            for (int t : now)
                for (int ms : ok)
                    in[t] += al[ms ^ mask[to] ^ nw[t]];
            for (int x : now)
                al[nw[x]]++;
        }
    now.clear();
    dfs_run(to, -1);
    for (int i : now)
        al[nw[i]] = 0;
    ll kek = 0;
    for (int i : now)
        if (__builtin_popcount(nw[i] ^ mask[to]) <= 1)
            kek++;
    in[to] = (in[to] - kek) / 2;
    in[to] += kek;
    for (int i : now)
        ans[i] += in[i];
    for (int i : now)
        in[i] = 0;
    pr[to] = last;
    for (int i : v[to])
        if (pr[i] == -2)
            find_centroid(i, to);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    memset(al, 0, sizeof(al));
    cin >> n;
    for (int i = 0; i < n; i++)
        pr[i] = -2;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        mask[i] = (1 << (s[i] - 'a'));
    for (int i = 0; i < 20; i++)
        ok.push_back((1 << i));
    ok.push_back(0);
    //cerr << "kek\n";
    find_centroid(0, -1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}