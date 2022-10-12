const long long MOD = 1e9 + 7;
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];

    map<int, int> mm;
    forn(i, n) mm[a[i]] = i;

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
            long long able = 0;
            for (; pnt[V] < g[V].size() && want > 0; pnt[V]++)
            {
                int id = g[V][pnt[V]];
                int U = u[id];
                if (dist[U] == dist[V] + 1 && f[id] < c[id])
                {
                    long long go = dfs(U, to, min(want, c[id] - f[id]));
                    f[id] += go;
                    f[id ^ 1] -= go;
                    want -= go;
                    able += go;
                }
            }
            return able;
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

    vector<vector<int> > g(2 * n);
    max_flow F(4 * n + 2);

    for (int i = 0; i < n; i++)
    {
        vector<int> divs;
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                divs.push_back(j);
                if (j * j != a[i]) divs.push_back(a[i] / j);
            }
        }
        for (auto e : divs)
        {
            if (e == a[i]) continue;
            if (mm.find(e) == mm.end()) continue;
            g[i].push_back(mm[e]);
            g[i + n].push_back(mm[e] + n);
        }
        g[i].push_back(i + n);
    }

    for (int i = 0; i < 2 * n; i++) F.add_edge(0, i + 1, 1);
    for (int i = 0; i < 2 * n; i++) F.add_edge(i + 2 * n + 1, 4 * n + 1, 1);
    for (int i = 0; i < 2 * n; i++) for (auto e : g[i]) F.add_edge(i + 1, e + 2 * n + 1, 1);

    int cur = F.flow(0, 4 * n + 1);
    cout << cur - n << "\n";
    #define tests
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}