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

ll n, m;
ll a[800000];
ll ans;
ll A[2600000];
ll B[2600000];
ll l, r;

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    l = 0, r = n - 1;
    ll maxima = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxima = max(maxima, a[i]);
    }
    vector<int> rep;
    for (int i = 0; i < 3 * n; i++)
    {
        int aa = a[l];
        int bb = a[l + 1];
        l++;
        a[l] = max(aa, bb);
        r++;
        a[r] = min(aa, bb);
        A[i + 1] = aa;
        B[i + 1] = bb;
        //cout << A[i + 1] << " " << B[i + 1] << endl;
        if (aa == maxima)
        {
            rep.push_back(i);
        }
    }
    long long pr = rep[0];
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (x <= 2 * n)
        {
            cout << A[x] << " " << B[x] << "\n";
        }
        else
        {
            x -= pr;
            x = x % (n - 1);
            x += pr;
            x += (n - 1);
            cout << A[x] << " " << B[x] << "\n";
        }
    }
}