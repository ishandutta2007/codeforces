#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <iomanip>
#include <cassert>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev kekekekek

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 55;

struct MaxFlow
{
    struct Edge
    {
        int to;
        ll c, f;

        Edge()
        {
            to = c = f = 0;
        }

        Edge(int to1, ll c1)
        {
            to = to1;
            c = c1;
            f = 0;
        }
    };

    int n;
    vector<Edge> e;
    vector<vector<int> > v;
    int s, f;
    vector<int> dist, last;

    MaxFlow()
    {

    }

    MaxFlow(int nn, int ss, int ff)
    {
        n = nn;
        dist.resize(n);
        v.resize(n);
        last.resize(n);
        s = ss, f = ff;
    }

    void connect(int a, int b, ll c)
    {
        int i = e.size();
        e.push_back(Edge(b, c));
        v[a].push_back(i);
        e.push_back(Edge(a, 0));
        v[b].push_back(i + 1);
    }

    ll dfs(int p, ll f0)
    {
        if (p == f)
            return f0;
        while (last[p] >= 0)
        {
            int i = v[p][last[p]];
            if (dist[e[i].to] != dist[p] + 1)
            {
                last[p]--;
                continue;
            }
            if (e[i].c == e[i].f)
            {
                last[p]--;
                continue;
            }
            ll res = dfs(e[i].to, min(f0, e[i].c - e[i].f));
            if (res == 0)
            {
                last[p]--;
                continue;
            }
            e[i].f += res;
            e[i ^ 1].f -= res;
            if (e[i].f == e[i].c)
                last[p]--;
            return res;
        }
        return 0;
    }

    void phase()
    {
        for (int i = 0; i < n; i++)
            dist[i] = BIG;
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i : v[x])
                if (e[i].c > e[i].f && dist[e[i].to] > dist[x] + 1)
                {
                    dist[e[i].to] = dist[x] + 1;
                    q.push(e[i].to);
                }
        }
        if (dist[f] >= BIG)
            return;
        for (int i = 0; i < n; i++)
            last[i] = (int)v[i].size() - 1;
        while (dfs(s, INF) != 0);
        phase();
    }

    void run()
    {
        phase();
    }

    ll gett()
    {
        ll ans = 0;
        for (int i : v[s])
            ans += e[i].f;
        return ans;
    }
};

int n, h, m, l[X], r[X];
ll x[X], c[X];

int gett(int i, int x)
{
    return (i * h + x + 1);
}

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> h >> m;
    MaxFlow g = MaxFlow(2 + n * h + m, 0, 1 + n * h + m);
    ll ans = (ll)n * (ll)h * (ll)h;
    for (int i = 0; i < n; i++)
        for (int x = 0; x < h; x++)
            g.connect(0, gett(i, x), 2 * x + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> x[i] >> c[i];
        l[i]--, r[i]--;
        for (int t = l[i]; t <= r[i]; t++)
            for (int y = x[i]; y < h; y++)
                g.connect(gett(t, y), n * h + 1 + i, BIG);
        g.connect(n * h + 1 + i, 1 + n * h + m, c[i]);
    }
    g.run();
    ans -= g.gett();
    cout << ans;
    return 0;
}