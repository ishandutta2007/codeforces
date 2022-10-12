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
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;
typedef complex<double> cd;

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

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
#define int long long

void YN(int val)
{
    if (val >= 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

const ll MOD = 998244353;
//const ll MOD = 1e9 + 7;

ll n;
string s[500000];
ll deg10[1000];

ll go[11][11][11];
ll summ[11][11];
ll cnt[11];
ll ans = 0;

void calc(int len1, int len2)
{
    vector<int> a(10, -1);
    vector<int> b(10, -1);
    int pointer = 0;
    int key = 0;
    for (int d = 9; d >= 0; d--)
    {
        if (key < len2)
        {
            b[d] = pointer;
            pointer++;
        }
        if (key < len1)
        {
            a[d] = pointer;
            pointer++;
        }
        key++;
    }
    ll res = 0;
    for (int i = 0; i < len1; i++)
    {
        int new_pos = a[9 - i];
        res += summ[len1][i] * deg10[new_pos] * cnt[len2];
        res %= MOD;
    }
    for (int i = 0; i < len2; i++)
    {
        int new_pos = b[9 - i];
        res += summ[len2][i] * deg10[new_pos] * cnt[len1];
        res %= MOD;
    }
    ans += res * (cnt[len1] * cnt[len2] > 0);
    if (res * cnt[len1] * cnt[len2] != 0)
    //cout << res * (cnt[len1] * cnt[len2] > 0) << " " << len1 << " " << len2 << endl;
    ans %= MOD;
}

void stcalc(int len)
{
    ll res = 0;
    int n0 = cnt[len];
    for (int i = 0; i < n; i++)
    {
        ll k = 1;
        if (s[i].size() == len)
        {
            for (int j = 0; j < len; j++)
            {
                res += (s[i][len - 1 - j] - '0') * n0 * 11 * k;
                //cout << s[i][len - 1 - j] - '0' << " " << n0 << " " << 11 * k << endl;
                res %= MOD;
                k *= 100;
                k %= MOD;
            }
        }
    }
    //cout << res << " " << len << endl;
    ans += res;
    ans %= MOD;
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    deg10[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        deg10[i] = deg10[i - 1] * 10 % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        cnt[s[i].size()]++;
        for (int j = 0; j < s[i].size(); j++)
        {
            int d = s[i][s[i].size() - 1 - j] - '0';
            summ[s[i].size()][j] += d;
        }
    }

    for (int len1 = 1; len1 <= 10; len1++)
    {
        for (int len2 = 1; len2 <= 10; len2++)
        {
            if (len1 == len2)
            {
                stcalc(len1);
                continue;
            }
            calc(len1, len2);
        }
    }

    cout << ans;
}