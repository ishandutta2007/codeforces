//#pragma GCC optimize("O3")
#ifdef ONPC
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

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
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const ll BIG = (ll)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = (int)sqrt(M);
const int X = 110;

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

int n, m, a, b;
bool used[X][X];
vector<tuple<int, int, int, int> > rect;
vector<int> vx, vy;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vx.push_back(0);
    vx.push_back(n);
    vy.push_back(0);
    vy.push_back(n);
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        vx.push_back(x1);
        vx.push_back(x2);
        vy.push_back(y1);
        vy.push_back(y2);
        rect.push_back(make_tuple(x1, y1, x2, y2));
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    sort(vy.begin(), vy.end());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    a = vx.size() - 1;
    b = vy.size() - 1;
    MaxFlow gr = MaxFlow(a + b + 2, 0, a + b + 1);
    for (int i = 0; i < a; i++)
        gr.connect(0, i + 1, vx[i + 1] - vx[i]);
    for (int i = 0; i < b; i++)
        gr.connect(i + a + 1, a + b + 1, vy[i + 1] - vy[i]);
    for (tuple<int, int, int, int> t : rect)
    {
        int x1 = lower_bound(vx.begin(), vx.end(), get<0>(t)) - vx.begin();
        int y1 = lower_bound(vy.begin(), vy.end(), get<1>(t)) - vy.begin();
        int x2 = lower_bound(vx.begin(), vx.end(), get<2>(t)) - vx.begin();
        int y2 = lower_bound(vy.begin(), vy.end(), get<3>(t)) - vy.begin();
        for (int i = x1; i < x2; i++)
            for (int j = y1; j < y2; j++)
                used[i][j] = true;
    }
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            if (used[i][j])
                gr.connect(i + 1, j + a + 1, n);
    gr.run();
    cout << gr.gett();
    return 0;
}