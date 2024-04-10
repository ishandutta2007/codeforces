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

int n, m;
int root[500000];
int sz[500000];

int Root(int x)
{
    if (x == root[x])
        return x;
    return root[x] = Root(root[x]);
}

void Merge(int a, int b)
{
    a = Root(a);
    b = Root(b);
    if (a == b) return;
    if (sz[a] == sz[b])
    {
        sz[a]++;
    }
    if (sz[a] < sz[b])
    {
        root[a] = b;
    }
    if (sz[a] > sz[b])
    {
        root[b] = a;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = i;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = Root(a);
        b = Root(b);
        if (a == b)
        {
            ans++;
        }
        else
        {
            Merge(a, b);
        }
    }
    cout << ans;
}