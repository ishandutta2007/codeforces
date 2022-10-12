
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
using std::fill;

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
#define int long long
const ll MOD = 998244353;

ll n;
ll X[500000];
ll Y[500000];
vector<ll> with_x[500000];
ll a[500000];
ll q[500000];
ll lst[500000];
ll seen[500000];
ll ready[500000];
Small_Segment_Tree ST(250000);

bool comp(pll a, pll b)
{
    return a.second > b.second;
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vi xes, yes;
    map<int, int> px, py;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        xes.push_back(x);
        yes.push_back(y);
    }
    sort(all(xes)); xes.resize(unique(all(xes)) - xes.begin());
    sort(all(yes)); yes.resize(unique(all(yes)) - yes.begin());
    for (int i = 0; i < xes.size(); i++)
    {
        px[xes[i]] = i;
    }
    for (int i = 0; i < yes.size(); i++)
    {
        py[yes[i]] = i;
    }
    vector<pll> v;
    for (int i = 0; i < n; i++)
    {
        X[i] = px[X[i]];
        Y[i] = py[Y[i]];
        with_x[X[i]].push_back(Y[i]);
        v.push_back({X[i], Y[i]});
    }
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < with_x[i].size(); j++)
        {
            a[p] = with_x[i][j];
            p++;
        }
        q[p - 1] = 1;
    }
    sort(all(v), comp);
    ll ans = 0;
    ll counter = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int curY = v[i].second;
        int j = i;
        while (j + 1 < v.size() && v[j + 1].second == curY)
            j++;
        ll ex = 0;
        ll cnt = 0;
        vector<int> vv;
        for (int k = i; k <= j; k++)
        {
            vv.push_back(v[k].first);
            if (ready[v[k].first])
            {
                counter--;
                cnt++;
                ex++;
            }
            else
            {
                ready[v[k].first] = 1;
                ST.Set(v[k].first, 1);
                cnt++;
                ex++;
            }
        }
        sort(all(vv));
        ans += ex * (ex + 1) / 2;
        ans += ex * counter;
        int prev = -1;
        for (int k = 0; k < vv.size(); k++)
        {
            ans += ST.Summ(prev + 1, vv[k] - 1) * (ST.Summ(vv[k] + 1, n) - (vv.size() - k - 1));
            prev = vv[k];
        }
        //cout << ex * (ex + 1) / 2 << " " << ex * counter << endl;
        counter += cnt;
        i = j;
    }
    cout << ans;
}