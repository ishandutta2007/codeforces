//isaf27

#pragma GCC optimize("O3")
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
#include <ctime>
#include <bits/stdc++.h>
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
const ld eps = 1e-6;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
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

bool used[M], is[M];
int n, m;
vector<pair<int, int> > r;
map<pair<int, int>, int> id;
vector<vector<int> > v;
vector<vector<int> > to;
vector<int> st;

void dfs(int p)
{
    used[p] = true;
    for (int i : to[p])
        if (!used[i])
        {
            dfs(i);
            v[p].push_back(i);
            is[id[make_pair(min(p, i), max(p, i))]] = true;
        }
}

pair<int, int> dp[L][M];
vector<int> et;
int gl[M], first[M], how[M], k;

void dfs_lca(int p, int pr, int f)
{
    first[p] = et.size();
    et.push_back(p);
    gl[p] = f;
    for (int i : v[p])
    {
        if (i != pr)
        {
            dfs_lca(i, p, f + 1);
            et.push_back(p);
        }
    }
}

int lca(int s, int f)
{
    if (first[s] > first[f])
        swap(s, f);
    int l = first[s];
    int r = first[f];
    int len = r - l + 1;
    int e = how[len];
    pair<int, int> ans = min(dp[e][l], dp[e][r + 1 - (1 << e)]);
    return ans.second;
}

void init_lca()
{
    for (int i : st)
        dfs_lca(i, -1, 0);
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
}

int gt[M], a[M], up[M];

void dfs_run(int p)
{
    a[p] = gt[p];
    for (int i : v[p])
    {
        dfs_run(i);
        a[p] += a[i];
        up[i] = p;
    }
}

vector<int> ans;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        if (s > f) swap(s, f);
        r.push_back(make_pair(s, f));
        id[make_pair(s, f)] = i;
    }
    to.resize(n);
    v.resize(n);
    for (pair<int, int> t : r)
    {
        to[t.first].push_back(t.second);
        to[t.second].push_back(t.first);
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            dfs(i);
            st.push_back(i);
        }
    init_lca();
    for (int i = 0; i < m; i++)
    {
        if (is[i]) continue;
        int s = r[i].first;
        int f = r[i].second;
        int x = lca(s, f);
        gt[s]++;
        gt[f]++;
        gt[x] -= 2;
    }
    for (int i : st)
        dfs_run(i);
    for (int i = 0; i < m; i++)
    {
        if (is[i]) continue;
        int s = r[i].first;
        int f = r[i].second;
        int x = lca(s, f);
        vector<pair<int, int> > now;
        now.push_back(make_pair(s, f));
        bool ch = true;
        while (s != x)
        {
            if (a[s] != 1)
            {
                ch = false;
                break;
            }
            now.push_back(make_pair(s, up[s]));
            s = up[s];
        }
        if (!ch) continue;
        while (f != x)
        {
            if (a[f] != 1)
            {
                ch = false;
                break;
            }
            now.push_back(make_pair(f, up[f]));
            f = up[f];
        }
        if (!ch) continue;
        for (pair<int, int> t : now)
            ans.push_back(id[make_pair(min(t.first, t.second), max(t.first, t.second))]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
    return 0;
}