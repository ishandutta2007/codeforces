#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const long long inf = 1e18;
const long long infsmart = 1e12;

void Set(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        //Tree[V] = max(val, Tree[V]);
        return;
    }
    if (r <= L || R <= l)
        return;
}

long long Get(int l, int r, int L, int R, int V)
{
    if (l <= L && R <= r)
    {
        //return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return 0;
    }
}

const long long MOD = 1e9 + 7;

vector<int> submasks[(1 << 12)];
int n, m;
int a[15][2150];
int dp[(1 << 12)][13];
int maskdifs[(1 << 12)];
int b[12][12];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            b[i][j] = 0;
    for (int i = 0; i < 12; i++)
    {
        int id = 0, mx = 0;
        for (int j = 0; j < m; j++)
        {
            int mxx = 0;
            for (int i = 0; i < n; i++)
            {
                mxx = max(mxx, a[i][j]);
            }
            if (mxx > mx)
            {
                mx = mxx;
                id = j;
            }
        }
        for (int j = 0; j < n; j++)
        {
            b[j][i] = a[j][id];
            a[j][id] = 0;
        }
    }
    for (int i = 0; i < (1 << 12); i++)
    {
        for (int j = 0; j < 13; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int col = 0; col < n; col++)
    {
        for (int i = 0; i < (1 << 12); i++) maskdifs[i] = 0;
        for (int moves = 0; moves < n; moves++)
        {
            for (int mask = 0; mask < (1 << n); mask++)
            {
                int r = 0;
                for (int i = 0; i < n; i++)
                {
                    if ((1 << i) & mask)
                        r += b[(i + moves) % n][col];
                }
                maskdifs[mask] = max(maskdifs[mask], r);
            }
        }
        for (int mask = 0; mask < (1 << n); mask++)
        {
            for (int d = 0; d < submasks[mask].size(); d++)
            {
                int submask = submasks[mask][d];
                int r = dp[mask][col] + maskdifs[mask - submask];
                dp[submask][col + 1] = max(r, dp[submask][col + 1]);
            }
        }
    }
    cout << dp[0][n] << "\n";
}

signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    for (int i = 0; i < (1 << 12); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((j & i) == j)
            {
                submasks[i].push_back(j);
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}