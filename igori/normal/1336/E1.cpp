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
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

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
using std::fill;

using std::setprecision;
using std::fixed;
using std::min;

#define int long long

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

const int N = 500000;
const int M = 36;
const int MOD = 998244353;

int n, m;
int a[N];
int bz[N];
int c;
int popa = 1;
int ans[N];

int compress(int a, int b)
{
    int w = 0;
    for (int j = m - 1; j >= 0; j--)
    {
        if (b & (1LL << j))
        {
            w = 2 * w;
            if (a & (1LL << j)) w++;
        }
    }
    return w;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int j = 0; j < m; j++) bz[j] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = m - 1; j >= 0; j--)
        {
            if ((a[i] & (1LL << j)))
            {
                if (bz[j] == -1)
                {
                    bz[j] = a[i];
                    c++;
                    break;
                }
                a[i] ^= bz[j];
            }
        }
    }
    for (int j = m - 1; j >= 0; j--)
    {
        if (bz[j] == -1) continue;
        for (int i = 0; i < m; i++)
        {
            if (bz[i] != -1 && i != j && bz[i] & (1LL << j))
            {
                bz[i] ^= bz[j];
            }
        }
    }
    for (int i = 0; i < n - c; i++) popa = 2 * popa % MOD;
    if (c <= 20)
    {
        vector<int> vv;
        for (int j = m - 1; j >= 0; j--) if (bz[j] != -1) vv.push_back(bz[j]);
        for (int i = 0; i < (1 << c); i++)
        {
            int r = 0;
            for (int j = 0; j < c; j++)
            {
                if ((1 << j) & i) r ^= vv[j];
            }
            ans[__builtin_popcountll(r)]++;
        }
    }
    else
    {
        vector<int> vv;
        for (int j = m - 1; j >= 0; j--) if (bz[j] != -1) vv.push_back(bz[j]);
        vector<int> w(c);
        int bit = 0;
        for (int j = 0; j < m; j++) if (bz[j] != -1) bit += (1LL << j);
        bit = (1LL << m) - 1 - bit;
        for (int i = 0; i < w.size(); i++) w[i] = compress(vv[i], bit);
        vector<vector<int> > dp(vv.size() + 1, vector<int>(1 << (m - c)));
        dp[0][0] = 1;
        for (int i = 0; i < w.size(); i++)
        {
            vector<vector<int> > dp2(vv.size() + 1, vector<int>(1 << (m - c)));
            for (int have = 0; have <= i; have++)
            {
                for (int mask = 0; mask < (1 << (m - c)); mask++)
                {
                    dp2[have][mask] = (dp2[have][mask] + dp[have][mask]) % MOD;
                    dp2[have + 1][mask ^ w[i]] = (dp2[have + 1][mask ^ w[i]] + dp[have][mask]) % MOD;
                }
            }
            dp = dp2;
        }
        for (int have = 0; have <= w.size(); have++)
        {
            for (int mask = 0; mask < (1 << (m - c)); mask++)
            {
                ans[have + __builtin_popcount(mask)] = (ans[have + __builtin_popcount(mask)] + dp[have][mask]) % MOD;
            }
        }
    }
    for (int i = 0; i <= m; i++) cout << ans[i] * popa % MOD << " ";
}