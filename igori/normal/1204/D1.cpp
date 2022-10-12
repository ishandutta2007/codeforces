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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

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
};


using namespace MySpace;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;

ll n, l, r;
S s;
ll dp[2][500000];
ll dp2[2][500000];

long long calc()
{
    if (s[0] == '0')
    {
        dp2[0][0] = 1;
        dp2[1][0] = 0;
    }
    else
    {
        dp2[1][0] = 1;
        dp2[0][0] = 0;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i] == '1')
        {
            dp2[1][i] = max(dp2[1][i - 1] + 1, dp2[0][i - 1] + 1);
            dp2[0][i] = dp2[0][i - 1];
        }
        else
        {
            dp2[1][i] = dp2[1][i - 1];
            dp2[0][i] = dp2[0][i - 1] + 1;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (max(dp[0][i], dp[1][i]) != max(dp2[0][i], dp2[1][i]))
            return 0;
    }
    return 1;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;

    {
        if (s[0] == '0')
        {
            dp[0][0] = 1;
            dp[1][0] = 0;
        }
        else
        {
            dp[1][0] = 1;
            dp[0][0] = 0;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            if (s[i] == '1')
            {
                dp[1][i] = max(dp[1][i - 1] + 1, dp[0][i - 1] + 1);
                dp[0][i] = dp[0][i - 1];
            }
            else
            {
                dp[1][i] = dp[1][i - 1];
                dp[0][i] = dp[0][i - 1] + 1;
            }
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        int ok = 1;
        if (s[i] == '1')
        {
            s[i] = '0';
            if (!calc())
                s[i] = '1';
        }
    }

    cout << s;
}