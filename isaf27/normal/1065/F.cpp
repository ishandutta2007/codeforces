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
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
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
mt19937 rnd(239);

//constants
const int M = 1e6 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 150;

int n, k, r, comp[M], dp[M];
vector<int> d[M];
bool used[M];
vector<int> v[M], u[M], in[M];
vector<int> tp;

void dfs_go(int p)
{
    used[p] = true;
    for (int i : v[p])
        if (!used[i])
            dfs_go(i);
    tp.push_back(p);
}

void dfs_back(int p)
{
    in[r].push_back(p);
    if (d[p].empty()) dp[r]++;
    used[p] = true;
    comp[p] = r;
    for (int i : u[p])
        if (!used[i])
            dfs_back(i);
}

int st[M];

void dfs_tree(int p, int h)
{
    st[h] = p;
    for (int i : d[p])
        dfs_tree(i, h + 1);
    if (d[p].empty())
    {
        if (h < k)
            v[p].push_back(0);
        else
            v[p].push_back(st[h - k]);
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        d[p - 1].push_back(i);
        v[p - 1].push_back(i);
    }
    dfs_tree(0, 0);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs_go(i);
    for (int i = 0; i < n; i++)
        for (int j : v[i])
            u[j].push_back(i);
    reverse(tp.begin(), tp.end());
    memset(used, 0, sizeof(used));
    r = 0;
    for (int i = 0; i < n; i++)
    {
        int x = tp[i];
        if (!used[x])
        {
            dfs_back(x);
            r++;
        }
    }
    for (int i = r - 1; i >= 0; i--)
    {
        int pl = 0;
        for (int x : in[i])
            for (int it : v[x])
            {
                if (comp[it] == i) continue;
                pl = max(pl, dp[comp[it]]);
            }
        dp[i] += pl;
    }
    cout << dp[comp[0]];
    return 0;
}