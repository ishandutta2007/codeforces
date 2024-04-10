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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const int N = 14;
const int MOD = 998244353;

int n;
string s[N];
long long g[(1 << N)];
long long dp[N][(1 << N)];
long long ans[(1 << N) / 2];
vector<int> submasks[(1 << (N / 2))][N + 1];
vector<int> a;
vector<int> with[N + 1];
vector<long long> dp2(1 << N);
int X = (1 << (N / 2)) - 1;
int Y = X << (N / 2);

void check()
{
    int mask = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i] - 1; j++)
        {
            mask = 2 * mask + 1;
        }
        mask = 2 * mask;
    }
    mask /= 2;
    ans[mask] += dp2[(1 << n) - 1];
    return;
}

void rec(int x, int lst)
{
    if (x == n)
    {
        check();
        return;
    }
    for (int i = lst; x + i <= n; i++)
    {
        a.push_back(i);
        for (auto mask2 : with[x + i])
        {
            int p1 = mask2 & X;
            int p2 = mask2 & Y;
            for (int k = 0; k <= N / 2 && k <= x; k++)
            {
                for (auto q1 : submasks[p1][k])
                {
                    for (auto q2 : submasks[p2 >> (N / 2)][x - k])
                    {
                        int mask1 = (q2 << (N / 2)) + q1;
                        dp2[mask2] += g[mask2 - mask1] * dp2[mask1];
                    }
                }
            }
        }
        rec(x + i, i);
        for (auto mask2 : with[x + i])
        {
            int p1 = mask2 & X;
            int p2 = mask2 & Y;
            for (int k = 0; k <= N / 2 && k <= x; k++)
            {
                for (auto q1 : submasks[p1][k])
                {
                    for (auto q2 : submasks[p2 >> (N / 2)][x - k])
                    {
                        int mask1 = (q2 << (N / 2)) + q1;
                        dp2[mask2] -= g[mask2 - mask1] * dp2[mask1];
                    }
                }
            }
        }
        a.pop_back();
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < (1 << N); i++)
    {
        with[__builtin_popcount(i)].push_back(i);
    }
    for (int i = 0; i < (1 << (N / 2)); i++)
    {
        for (int mask = i; ; mask = (mask - 1) & i)
        {
            submasks[i][__builtin_popcount(mask)].push_back(mask);
            if (mask == 0) break;
        }
    }
    dp2[0] = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][(1 << i)] = 1;
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((1 << i) & mask)
            {
                int k = mask - (1 << i);
                if (k != 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if ((1 << j) & k)
                        {
                            if (s[i][j] == '1')
                            {
                                dp[i][mask] += dp[j][k];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            g[mask] += dp[i][mask];
        }
    }
    rec(0, 1);
    for (int mask = 0; mask < (1 << n) / 2; mask++)
    {
        vector<int> b;
        int len = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (mask & (1 << i))
            {
                len++;
            }
            else
            {
                b.push_back(len + 1);
                len = 0;
            }
        }
        b.push_back(len + 1);
        sort(all(b));
        int mask_ = 0;
        for (int i = 0; i < b.size(); i++)
        {
            for (int j = 0; j < b[i] - 1; j++)
            {
                mask_ = 2 * mask_ + 1;
            }
            mask_ = 2 * mask_;
        }
        mask_ /= 2;
        ans[mask] = ans[mask_];
    }
    for (int mask = 0; mask < (1 << n) / 2; mask++)
    {
        for (int upmask = mask; upmask < (1 << n) / 2; upmask = (upmask + 1) | mask)
        {
            int b = __builtin_popcount(upmask - mask);
            if (b == 0) continue;
            if (b % 2 == 1) ans[mask] -= ans[upmask];
            else ans[mask] += ans[upmask];
        }
    }
    for (int i = 0; i < (1 << n) / 2; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}