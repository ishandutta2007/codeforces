const int MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

struct max_flow{
    vector<int> v, u;
    vector<long long> c, f;
    vector<vector<int> > g;
    vector<int> dist, pnt;
    max_flow(int n)
    {
        g.resize(n);
        dist.resize(n);
        pnt.resize(n);
    }
    void add_edge(int from, int to, long long cap)
    {
        g[from].push_back(v.size());
        v.push_back(from), u.push_back(to), c.push_back(cap), f.push_back(0);

        g[to].push_back(v.size());
        v.push_back(to), u.push_back(from), c.push_back(0), f.push_back(0);
    }
    long long dfs(int V, int to, long long want)
    {
        if (V == to || want == 0) return want;
        for (; pnt[V] < g[V].size(); pnt[V]++)
        {
            int id = g[V][pnt[V]];
            int U = u[id];
            if (dist[U] == dist[V] + 1 && f[id] < c[id])
            {
                long long go = dfs(U, to, min(want, c[id] - f[id]));
                if (go > 0)
                {
                    f[id] += go;
                    f[id ^ 1] -= go;
                    return go;
                }
            }
        }
        return 0;
    }
    long long find_flow(int from, int to)
    {
        int n = g.size();
        fill(dist.begin(), dist.end(), n);
        fill(pnt.begin(), pnt.end(), 0);
        dist[from] = 0;
        vector<int> q = {from};
        for (int i = 0; i < q.size(); i++)
        {
            for (auto eid : g[q[i]])
            {
                if (dist[u[eid]] == n && f[eid] < c[eid])
                {
                    dist[u[eid]] = dist[v[eid]] + 1;
                    q.push_back(u[eid]);
                }
            }
        }
        if (dist[to] == n)
            return 0;
        long long z = dfs(from, to, (long long)(1e18));
        long long res = 0;
        while (z)
        {
            res += z;
            z = dfs(from, to, (long long)(1e18));
        }
        return res;
    }
    long long flow(int from, int to)
    {
        fill(f.begin(), f.end(), 0ll);
        long long z = find_flow(from, to);
        long long ans = 0;
        while (z)
        {
            ans += z;
            z = find_flow(from, to);
        }
        return ans;
    }
};

void dfs2(int v, int fl, vector<vector<pii> > &gP, vector<vector<pii> > &gNP, vi &ext, vi &vis)
{
    if (vis[v]) return;
    vis[v] = 1;
    if (fl == 0)
    {
        for (auto e : gNP[v])
        {
            dfs2(e.first, 1 ^ fl, gP, gNP, ext, vis);
        }
    }
    else
    {
        for (auto e : gP[v])
        {
            ext[e.first] = 1;
            dfs2(e.first, 1 ^ fl, gP, gNP, ext, vis);
        }
    }
}

void solve()
{
    int n1, n2, m, q;
    cin >> n1 >> n2 >> m >> q;
    vector<int> f(m), t(m);
    max_flow G(1 + n1 + n2 + 1);
    vector<vector<int> > g(1 + n1 + n2 + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> f[i] >> t[i];
        t[i] += n1;
        G.add_edge(f[i], t[i], 1);
        g[f[i]].push_back(i);
        g[t[i]].push_back(i);
    }
    for (int i = 0; i < n1; i++)
    {
        G.add_edge(0, i + 1, 1);
    }
    for (int i = 0; i < n2; i++)
    {
        G.add_edge(1 + i + n1, 1 + n1 + n2, 1);
    }

    int cur = G.flow(0, n1 + n2 + 1);
    dbg(cur);

    vector<int> inp(m);
    vector<int> mark(g.size());
    vector<pii> vv;
    vi ee;
    ll sum = 0;
    int pi = 0;
    for (int i = 0; i < m; i++)
    {
        if (G.f[2 * i] == 1)
        {
            mark[G.v[2 * i]] = 1;
            mark[G.u[2 * i]] = 1;
            inp[i] = 1;
            vv.push_back({G.v[2 * i], G.u[2 * i]});
            ee.push_back(i);
            sum += i + 1;
        }
    }

    vector<vector<pii> > gP(g.size()), gNP(g.size());
    for (int i = 0; i < m; i++)
    {
        if (inp[i])
        {
            gP[f[i]].push_back({t[i], i});
            gP[t[i]].push_back({f[i], i});
        }
        else
        {
            gNP[f[i]].push_back({t[i], i});
            gNP[t[i]].push_back({f[i], i});
        }
    }

    vector<int> vis(g.size());
    vector<int> extendable(1 + n1 + n2 + 1);

    for (int i = 1; i < 1 + n1 + n2; i++)
    {
        if (mark[i] == 0)
        {
            dfs2(i, 0, gP, gNP, extendable, vis);
        }
        if (i == n1)
        {
            fill(all(vis), 0);
        }
    }

    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            cur--;
            cout << 1 << "\n";
            int x = vv[pi].first, y = vv[pi].second;

            dbg(extendable);
            if (!extendable[y])
            {
                swap(x, y);
            }

            if (x <= n1)
            {
                cout << x << "\n";
            }
            else
            {
                x -= n1;
                cout << -x << "\n";
            }

            sum -= ee[pi] + 1;
            pi++;
            cout << sum << "\n";
        }
        else
        {
            cout << cur << "\n";
            for (int i = pi; i < ee.size(); i++)
            {
                cout << ee[i] + 1 << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}