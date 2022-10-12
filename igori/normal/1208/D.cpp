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

ll n, m, k;
ll a[1000000];
ll ans[1000000];

ll Tree[1000000];
ll Push[1000000];

void push(int V)
{
    Tree[2 * V + 1] += Push[V];
    Push[2 * V + 1] += Push[V];
    Tree[2 * V + 2] += Push[V];
    Push[2 * V + 2] += Push[V];
    Push[V] = 0;
}

void add(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        Tree[V] += val;
        Push[V] += val;
        return;
    }
    if (r <= L || R <= l)
        return;
    int M = (L + R) / 2;
    push(V);
    add(l, r, L, M, 2 * V + 1, val);
    add(l, r, M, R, 2 * V + 2, val);
    Tree[V] = min(Tree[2 * V + 1], Tree[2 * V + 2]);
}

int last_zero()
{
    int ver = 0;
    int L = 1, R = n + 1;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        push(ver);
        if (Tree[2 * ver + 2] == 0)
        {
            L = M;
            ver = ver * 2 + 2;
        }
        else
        {
            R = M;
            ver = ver * 2 + 1;
        }
    }
    return L;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, i + 1, 1, n + 1, 0, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int x = last_zero();
        ans[x] = i;
        add(x, x + 1, 1, n + 1, 0, 1000000000000);
        add(x + 1, n + 1, 1, n + 1, 0, -i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}