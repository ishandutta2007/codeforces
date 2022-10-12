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
int a[15][2150];
vector<vector<int> > colls;
vector<int> v;
int pin[2100];
int ans = 0;

void check()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int ri = 0;
        for (int j = 0; j < colls.size(); j++)
        {
            ri = max(ri, colls[j][(i + v[j]) % n]);
        }
        res += ri;
    }
    ans = max(ans, res);
}

void rec(int last_moved, int kek)
{
    if (kek + 1 == colls.size())
    {
        check();
        return;
    }
    for (int i = last_moved; i < n; i++)
    {
        v.push_back(i);
        rec(i, kek + 1);
        v.pop_back();
    }
}

vector<int> canon(vector<int> a)
{
    int pos = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > a[pos])
            pos = i;
    }
    vector<int> b;
    for (int i = pos; i < pos + a.size(); i++)
    {
        b.push_back(a[i % a.size()]);
    }
    return b;
}

void solve()
{
    ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    colls.resize(0);
    vector<int> used(m);
    for (int i = 0; i < min(m, n); i++)
    {
        int mx = 0, id = 0;
        for (int j = 0; j < m; j++)
        {
            if (used[j]) continue;
            int mmx = 0;
            for (int i = 0; i < n; i++)
            {
                mmx = max(mmx, a[i][j]);
            }
            if (mmx > mx)
            {
                mx = mmx;
                id = j;
            }
        }
        vector<int> v;
        for (int k = 0; k < n; k++)
        {
            v.push_back(a[k][id]);
        }
        colls.push_back(canon(v));
        used[id] = 1;
    }
    /*for (int i = 0; i < colls.size(); i++)
    {
        for (int j = 0; j < colls[i].size(); j++)
        {
            cout << colls[i][j] << " ";
        }
        cout << "\n";
    }*/
    v.push_back(0);
    rec(0, 0);
    v.pop_back();
    cout << ans << "\n";
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