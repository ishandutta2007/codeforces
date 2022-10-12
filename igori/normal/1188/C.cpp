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
#include <time.h>
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
using std::complex;

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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;
typedef complex<double> cd;

namespace MySpace{
    struct Small_Segment_Tree{
        vector<int> a;
        int l, r;

        private:
        int __summ(int L, int R, int l, int r, int v)
        {
            if (L <= l && r <= R)
                return a[v];
            if (R <= l || r <= L)
                return 0;
            int m = (l + r) / 2;
            return __summ(L, R, l, m, 2 * v + 1) + __summ(L, R, m, r, 2 * v + 2);
        }

        void __set(int P, int l, int r, int v, int V)
        {
            if (l + 1 == r)
            {
                a[v] = V;
                return;
            }
            int m = (l + r) / 2;
            if (P < m)
            {
                __set(P, l, m, 2 * v + 1, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
            else
            {
                __set(P, m, r, 2 * v + 2, V);
                a[v] = a[2 * v + 1] + a[2 * v + 2];
            }
        }

        public:
        int Summ(int L, int R)
        {
            if (R < L)
                return 0;
            return __summ(L, R + 1, l, r, 0);
        }

        void Set(int P, int V)
        {
            __set(P, l, r, 0, V);
        }

        Small_Segment_Tree(int _n)
        {
            a.resize(4 * _n);
            l = 0, r = _n;
        }
    };
    long long inq(long long x, long long q, long long MOD)
    {
        if (q == 0)
            return 1;
        long long l = inq(x, q / 2, MOD);
        if (q % 2)
            return l * l % MOD * x % MOD;
        return l * l % MOD;
    }
};


using namespace MySpace;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;
ll n, k;
ll dp[2][1001][1001];
ll summ[2][1001][1001];
ll a[5000];

void solve(int b)
{
    dp[0][0][0] = 1;
    summ[0][0][0] = 1;
    int j = 0, j_equal = 0;
    for (int i = 1; i <= n; i++)
    {
        int val = a[i];
        while (j < i && a[j] + b < a[i])
            j++;
        while (j_equal < i && a[j_equal] + b <= a[i])
            j_equal++;
        for (int kk = 0; kk <= k; kk++)
        {
            dp[0][i][kk] = (j > 0 ? summ[0][j - 1][kk - 1] : 0);
            dp[1][i][kk] = (j > 0 ? summ[1][j - 1][kk - 1] : 0);
            if (a[j] + b == a[i])
            {
                dp[1][i][kk] = (dp[1][i][kk] + (j_equal - j) * dp[0][j][kk - 1]);
                dp[1][i][kk] = (dp[1][i][kk] + (j_equal - j) * dp[1][j][kk - 1]);
            }
            if (dp[0][i][kk] >= MOD) dp[0][i][kk] -= MOD;
            while (dp[1][i][kk] >= MOD) dp[1][i][kk] -= MOD;
            summ[0][i][kk] = summ[0][i - 1][kk] + dp[0][i][kk];
            summ[1][i][kk] = summ[1][i - 1][kk] + dp[1][i][kk];
            if (summ[0][i][kk] >= MOD) summ[0][i][kk] -= MOD;
            if (summ[1][i][kk] >= MOD) summ[1][i][kk] -= MOD;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    //n = 1000;
    //k = 2;
    a[0] = -100001;
    ll maxA = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //a[i] = i * 100; // 100000
        maxA = max(maxA, a[i]);
    }
    sort(a, a + n + 1);
    ll ans = 0;
    for (int b = 1; b <= maxA / (k - 1) + 1; b++)
    {
        solve(b);
        ans += b * summ[1][n][k];
        //if (dp[1][n][k] != 0)
        //    cout << b << " " << summ[1][n][k] << endl;
        ans %= MOD;
    }
    cout << ans;
}