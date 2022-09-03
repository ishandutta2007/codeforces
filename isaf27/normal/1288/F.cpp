//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

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
const ll btc = 30;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7; //(int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 210;

struct MCMF
{
    struct Edge
    {
        int to, fr;
        ll c, f, p;

        Edge()
        {
            fr = to = c = f = p = 0;
        }

        Edge(int fr1, int to1, ll c1, ll p1)
        {
            fr = fr1;
            to = to1;
            c = c1;
            f = 0;
            p = p1;
        }
    };

    int n;
    vector<Edge> e;
    vector<vector<int> > v;
    int s, f;
    vector<int> pr;
    vector<ll> dist;
    vector<ll> pot;

    MCMF()
    {

    }

    MCMF(int nn, int ss, int ff)
    {
        n = nn;
        dist.resize(n);
        v.resize(n);
        pot.resize(n);
        pr.resize(n);
        for (int i = 0; i < n; i++)
            pot[i] = 0;
        s = ss, f = ff;
    }

    inline int connect(int a, int b, ll c, ll p)
    {
        int i = e.size();
        e.push_back(Edge(a, b, c, p));
        v[a].push_back(i);
        e.push_back(Edge(b, a, 0, -p));
        v[b].push_back(i + 1);
        return i;
    }

    inline ll cost(int i)
    {
        return e[i].p + pot[e[i].fr] - pot[e[i].to];
    }

    inline void phase()
    {
        for (int i = 0; i < n; i++)
            dist[i] = INF, pr[i] = -1;
        dist[s] = 0;
        set<pair<ll, int> > q;
        for (int i = 0; i < n; i++)
            q.insert(make_pair(dist[i], i));
        while (!q.empty())
        {
            int x = q.begin()->second;
            q.erase(q.begin());
            for (int i : v[x])
                if (e[i].c > e[i].f && dist[e[i].to] > dist[x] + cost(i))
                {
                    q.erase(make_pair(dist[e[i].to], e[i].to));
                    pr[e[i].to] = i;
                    dist[e[i].to] = dist[x] + cost(i);
                    q.insert(make_pair(dist[e[i].to], e[i].to));
                }
        }
        if (dist[f] >= BIG)
            return;
        int t = f;
        ll w = INF;
        vector<int> way;
        while (t != s)
        {
            way.push_back(t);
            w = min(w, e[pr[t]].c - e[pr[t]].f);
            t = e[pr[t]].fr;
        }
        way.push_back(s);
        reverse(way.begin(), way.end());
        t = f;
        while (t != s)
        {
            e[pr[t]].f += w;
            e[pr[t] ^ 1].f -= w;
            t = e[pr[t]].fr;
        }
        for (int i = 0; i < n; i++)
            pot[i] = dist[i];
        phase();
    }

    inline void compute_fb()
    {
        for (int i = 0; i < n; i++)
            pot[i] = 0;
        for (int z = 0; z < n; z++)
            for (Edge ee : e)
                if (ee.c > 0)
                    pot[ee.to] = min(pot[ee.to], pot[ee.fr] + ee.p);
        //for (int i = 0; i < (int)e.size(); i++)
        //    if (cost(i) < 0 && e[i].c > 0)
        //        cerr << "bad!\n";
    }

    inline void run()
    {
        compute_fb();
        phase();
    }

    inline ll gett()
    {
        ll ans = 0;
        for (Edge ee : e)
            if (ee.c > 0)
                ans += ee.f * ee.p;
        return ans;
    }

    inline int getsize()
    {
        ll ans = 0;
        for (int i : v[s])
            if (e[i].c > 0)
                ans += e[i].f;
        return ans;
    }
};

int n1, n2, m, r, b;
string s1, s2;
int ri[X], bi[X];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;
    MCMF gr = MCMF(n1 + n2 + 4, n1 + n2 + 2, n1 + n2 + 3);
    int L = n1 + n2;
    int R = n1 + n2 + 1;
    int S = n1 + n2 + 2;
    int F = n1 + n2 + 3;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        ri[i] = gr.connect(s, f + n1, 1, r);
        bi[i] = gr.connect(f + n1, s, 1, b);
    }
    int big = 2 * m + 10;
    gr.connect(R, L, big, 0);
    int need = 0;
    for (int i = 0; i < n1; i++)
    {
        if (s1[i] == 'U')
        {
            gr.connect(i, R, big, 0);
            gr.connect(L, i, big, 0);
            continue;
        }
        need++;
        if (s1[i] == 'B')
        {
            gr.connect(i, R, big, 0);
            gr.connect(i, F, 1, 0);
            gr.connect(S, R, 1, 0);
        }
        else
        {
            gr.connect(L, i, big, 0);
            gr.connect(L, F, 1, 0);
            gr.connect(S, i, 1, 0);
        }
    }
    for (int ii = 0; ii < n2; ii++)
    {
        int i = ii + n1;
        if (s2[ii] == 'U')
        {
            gr.connect(i, R, big, 0);
            gr.connect(L, i, big, 0);
            continue;
        }
        need++;
        if (s2[ii] == 'R')
        {
            gr.connect(i, R, big, 0);
            gr.connect(i, F, 1, 0);
            gr.connect(S, R, 1, 0);
        }
        else
        {
            gr.connect(L, i, big, 0);
            gr.connect(L, F, 1, 0);
            gr.connect(S, i, 1, 0);
        }
    }
    gr.run();
    if (gr.getsize() != need)
    {
        cout << "-1\n";
        return 0;
    }
    cout << gr.gett() << "\n";
    string ans = "";
    for (int i = 0; i < m; i++)
    {
        if (gr.e[ri[i]].f == 1)
            ans += "R";
        else if (gr.e[bi[i]].f == 1)
            ans += "B";
        else
            ans += "U";
    }
    cout << ans << "\n";
    return 0;
}