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

S s;

void solve()
{
    int n;
    cin >> n >> s;
    vector<int> ans(n);
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - '0']++;
    }
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        while (cnt[d] == 0 && d < 10) d++;
        if (d == 10) break;
        if (s[i] - '0' == d)
        {
            ans[i] = 1;
            cnt[s[i] - '0']--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        while (cnt[d] == 0 && d < 10) d++;
        if (d == 10) break;
        if (s[i] - '0' == d)
        {
            ans[i] = 2;
            cnt[s[i] - '0']--;
        }
    }
    int x = 0;
    for (int i = 0; i < 10; i++) if (cnt[i] > 0) x = 1;
    if (x)
    {
        cout << "-\n";
        return;
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}