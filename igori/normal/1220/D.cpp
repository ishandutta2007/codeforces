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

using std::setprecision;
using std::fixed;

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

int n;
ll b[500000];
ll del_pos[500000];

ll divide()
{
    ll g = 0;
    for (int i = 0; i < n; i++)
    {
        if (del_pos[i] == 1) continue;
        if (g == 0) g = b[i];
        g = std::__gcd(b[i], g);
    }
    for (int i = 0; i < n; i++)
    {
        if (del_pos[i] == 1) continue;
        b[i] /= g;
    }
}

ll cb[500000];
vector<int> res;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        cb[i] = b[i];
    }
    divide();
    ll ans = n;
    ll already_delete = 0;
    ll step = -1;
    for (int it = 0; it < 70; it++)
    {
        int cnt_even = 0;
        for (int i = 0; i < n; i++)
        {
            if (del_pos[i] == 0 && b[i] % 2 == 0)
            {
                cnt_even++;
            }
        }
        ans = min(ans, already_delete + cnt_even);
        if (ans == already_delete + cnt_even)
        {
            step = it;
            res.resize(0);
            for (int i = 0; i < n; i++)
            {
                if (del_pos[i] == 1 || b[i] % 2 == 0)
                {
                    res.push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (del_pos[i] == 0 && b[i] % 2 == 1)
            {
                del_pos[i] = 1;
                already_delete++;
            }
        }
        divide();
    }
    cout << ans << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << cb[res[i]] << " ";
    }
}