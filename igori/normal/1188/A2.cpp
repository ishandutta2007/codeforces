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

const ll MOD = 998244353;
ll n;

struct edge{
    int a, b, c;
};

vector<int> graph[500000];
vector<edge> s;
vector<pair<pii, int> > ans;

vector<int> reached(1001);
vector<int> vis(1001);

int go(int id, int from)
{
    return s[id].a + s[id].b - from;
}

void add(int v, int leaf, int num)
{
    if (v == leaf)
    {
        return;
    }
    if (graph[v].size() == 1)
    {
        ans.push_back({{v, leaf}, num});
        return;
    }
    fill(all(vis), 0);
    vis[leaf] = 1;
    vector<int> q;
    q.push_back(leaf);
    int BIGV = v;
    
    for (int i = 0; i < q.size(); i++)
    {
        int v = q[i];
        for (int j = 0; j < graph[v].size(); j++)
        {
            int u = go(graph[v][j], v);
            if (vis[u] == 0)
            {
                vis[u] = 1;
                q.push_back(u);
                if (u == BIGV)
                {
                    BIGV = -1;
                    break;
                }
            }
        }
        if (BIGV == -1)
        {
            break;
        }
    }
    
    vector<int> pl;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = go(graph[v][i], v);
        if (vis[u] == 0)
            pl.push_back(u);
        if (pl.size() == 2)
            break;
    }
    //cout << leaf << endl;
    //cout << "root = " << v << " it is equal to 2 :" << pl.size() << endl;
    int p1 = pl[0];
    int p2 = pl[1];

    while (graph[p1].size() != 1)
    {
        vis[p1] = 1;
        for (int i = 0; i < graph[p1].size(); i++)
        {
            int u = go(graph[p1][i], p1);
            if (vis[u] == 0)
            {
                p1 = u;
                break;
            }
        }
    }
    
    while (graph[p2].size() != 1)
    {
        vis[p2] = 1;
        for (int i = 0; i < graph[p2].size(); i++)
        {
            int u = go(graph[p2][i], p2);
            if (vis[u] == 0)
            {
                p2 = u;
                break;
            }
        }
    }

    ans.push_back({{p1, leaf}, num / 2});
    ans.push_back({{p2, leaf}, num / 2});
    ans.push_back({{p1, p2}, - num / 2});
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(i);
        graph[b].push_back(i);
        s.push_back({a, b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 2)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            root = i;
            break;
        }
    }
    reached[root] = 1;
    vector<int> q;
    q.push_back(root);
    for (int i = 0; i < q.size(); i++)
    {
        for (int j = 0; j < graph[q[i]].size(); j++)
        {
            int u = s[graph[q[i]][j]].a + s[graph[q[i]][j]].b - q[i];
            int v = q[i];
            if (reached[u] == 0)
            {
                //reached[u] = 1;
                add(v, root, s[graph[q[i]][j]].c);
                add(u, root, -s[graph[q[i]][j]].c);
                reached[u] = 1;
                q.push_back(u);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se * (-1) << "\n";
    }
}