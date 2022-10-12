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
#define int long long

const long long MOD = 1e9 + 7;

const long long inf = 1e18;
const long long infsmart = 1e12;

ll n, w;
long long ans[1200000];

ll Tree[5000000];

void push(int V)
{
    Tree[2 * V + 1] = max(Tree[2 * V + 1], Tree[V]);
    Tree[2 * V + 2] = max(Tree[2 * V + 2], Tree[V]);
}

void Set(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        Tree[V] = max(val, Tree[V]);
        return;
    }
    if (r <= L || R <= l)
        return;
    int M = (L + R) / 2;
    push(V);
    Set(l, r, L, M, 2 * V + 1, val);
    Set(l, r, M, R, 2 * V + 2, val);
}

long long Get(int l, int r, int L, int R, int V)
{
    if (l <= L && R <= r)
    {
        return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return -inf;
    }
    int M = (L + R) / 2;
    push(V);
    return max(Get(l, r, L, M, 2 * V + 1), Get(l, r, M, R, 2 * V + 2));
}

long long addition = 0;

vector<long long> adds_more[1200000];
vector<long long> adds_less[1200000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k * 2 <= w)
        {
            vector<long long> a(k);
            for (int i = 0; i < k; i++)
            {
                cin >> a[i];
            }
            long long L = k;
            long long R = w - k - 1;
            long long mx = 0;
            for (int i = 0; i < k; i++) mx = max(mx, a[i]);
            long long pre = 0;
            for (int i = 0; i < k; i++)
            {
                pre = max(pre, a[i]);
                ans[i] += pre;
            }
            long long suff = 0;
            int pos = w - 1;
            for (int i = k - 1; i >= 0; i--, pos--)
            {
                suff = max(suff, a[i]);
                ans[pos] += suff;
            }
            adds_more[L].push_back(mx);
            adds_less[R].push_back(mx);
            continue;
        }
        vector<long long> a(k);
        for (int j = 0; j < 4 * w; j++)
        {
            Tree[j] = -infsmart;
        }
        Set(0, w - k, 0, w, 0, 0);
        Set(k, w, 0, w, 0, 0);
        for (int j = 0; j < k; j++)
        {
            cin >> a[j];
            int lefter = j;
            int righter = k - j - 1;
            //cout << "we : " << lefter << " " << w - righter - 1 << " " << a[j] << endl;
            Set(lefter, w - righter, 0, w, 0, a[j]);
        }
        for (int j = 0; j < w; j++)
        {
            ans[j] += Get(j, j + 1, 0, w, 0);
        }
    }
    long long k = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < adds_more[i].size(); j++)
            k += adds_more[i][j];
        cout << ans[i] + k << " ";
        for (int j = 0; j < adds_less[i].size(); j++)
            k -= adds_less[i][j];
    }
}