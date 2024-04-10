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

const ll MOD = 1e9 + 7;

ll n;
vector<int> graph[500000];
ll fc[500000];
ll scr;

ll Sz[500000];
ll par[500000];
ll dist[500000];
ll vis[500000];

void dfs(int v, int h)
{
    vis[v] = 1;
    dist[v] = h;
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (vis[graph[v][i]] == 0)
        {
            dfs(graph[v][i], h + 1);
        }
    }
}

void dfs(int v)
{
    if (fc[v] == 0)
        return;
    Sz[v] = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (Sz[u] == 0)
        {
            dfs(u);
            Sz[v] += Sz[u];
            par[u] = v;
        }
    }
}

int loop()
{
    fill(Sz, Sz + n + 1, 0);
    fill(par, par + n + 1, 0);
    dfs(scr);
    int toto = Sz[scr];
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Sz[i] == 0)
            continue;
        int t = 1;
        for (int j = 0; j < graph[i].size(); j++)
        {
            int pSz = Sz[graph[i][j]];
            if (graph[i][j] == par[i])
            {
                pSz = toto - Sz[i];
            }
            //cout << pSz << " ";
            if (pSz * 2 > toto)
                t = 0;
        }
        //cout << endl;
        if (t)
            return i;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs(1, 0);
    ll dist1;
    cout << "d 1" << endl;
    cin >> dist1;
    fill(fc, fc + n + 1, 1);
    scr = 1;
    while (1)
    {
        int u = loop();
        fc[u] = 0;
        int R;
        cout << "d " << u << endl;
        cin >> R;
        if (R == 0)
        {
            cout << "! " << u << endl;
            return 0;
        }
        if (R + dist[u] == dist1)
        {
            int S;
            cout << "s " << u << endl;
            cin >> S;
            scr = S;
        }
        else
        {

        }
    }
}