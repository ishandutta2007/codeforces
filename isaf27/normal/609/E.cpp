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
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 2 * 1e5 + 10;
const int MAX_M = (1 << 20);
const int MAX_T = (1 << 22);
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

vector<vector<pair<int, int> > > v(MAX_N);
int n, m;
ll ans[MAX_N], sum;
vector<tuple<int, int, int, int> > qw;

void read()
{
    cin >> n >> m;
    vector<tuple<int, int, int, int> > r;
    for (int i = 0; i < m; i++)
    {
        int s, f, c;
        cin >> s >> f >> c;
        s--, f--;
        r.push_back(make_tuple(c, s, f, i));
    }
    dsu w = dsu(n);
    sort(r.begin(), r.end());
    sum = 0;
    vector<int> ids;
    for (int i = 0; i < m; i++)
    {
        int c = get<0>(r[i]);
        int s = get<1>(r[i]);
        int f = get<2>(r[i]);
        if (w.is_connect(s, f))
        {
            qw.push_back(r[i]);
            continue;
        }
        w.merge_set(s, f);
        sum += (ll)c;
        v[s].push_back(make_pair(f, c));
        v[f].push_back(make_pair(s, c));
        ids.push_back(get<3>(r[i]));
    }
    for (int i : ids)
        ans[i] = sum;
}

int up[MAX_LOG][MAX_N];
int mx[MAX_LOG][MAX_N];
int tin[MAX_N], tout[MAX_N], timer;

void dfs(int p, int pr, int w)
{
    up[0][p] = pr;
    tin[p] = timer++;
    for (int i = 1; i < MAX_LOG; i++)
        up[i][p] = up[i - 1][up[i - 1][p]];
    mx[0][p] = w;
    for (int i = 1; i < MAX_LOG; i++)
        mx[i][p] = max(mx[i - 1][p], mx[i - 1][up[i - 1][p]]);
    for (pair<int, int> t : v[p])
        if (t.first != pr)
            dfs(t.first, p, t.second);
    tout[p] = timer;
}

bool upper(int s, int f)
{
    return (tin[s] <= tin[f] && tout[f] <= tout[s]);
}

int max_way(int s, int f)
{
    if (upper(f, s))
        swap(s, f);
    if (upper(s, f))
    {
        int ans = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--)
            if (!upper(up[i][f], s))
            {
                ans = max(ans, mx[i][f]);
                f = up[i][f];
            }
        ans = max(ans, mx[0][f]);
        f = up[0][f];
        return ans;
    }
    int ans = 0;
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (!upper(up[i][f], s))
        {
            ans = max(ans, mx[i][f]);
            f = up[i][f];
        }
    ans = max(ans, mx[0][f]);
    f = up[0][f];
    swap(s, f);
    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (!upper(up[i][f], s))
        {
            ans = max(ans, mx[i][f]);
            f = up[i][f];
        }
    ans = max(ans, mx[0][f]);
    f = up[0][f];
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    read();
    dfs(0, 0, 0);
    for (tuple<int, int, int, int> t : qw)
        ans[get<3>(t)] = sum + (ll)get<0>(t) - (ll)max_way(get<1>(t), get<2>(t));
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
    return 0;
}