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

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
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

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

void dfs(int v, int p, int &n, int &c, vvi &g, vi &sz)
{
    sz[v] = 1;
    for (auto u : g[v]) if (u != p)
        dfs(u, v, n, c, g, sz), sz[v] += sz[u];
    if (c == -1 && sz[v] * 2 >= n) c = v;
}

const int N = 5e5;
vector<int> child[N];

void dfs2(int v, int p, int pnt, vector<set<pii, greater<pii> > > &Vertices, vvi &g, vi &dist)
{
    child[p].pb(v);
    dist[v] = dist[p] + 1;
    Vertices[pnt].insert({dist[v], v});
    for (auto u : g[v]) if (u != p)
        dfs2(u, v, pnt, Vertices, g, dist);
}

void dfs3(int v, int p, vi &used, vi &order, vvi &g)
{
    if (!used[v]) order.pb(v);
    for (auto u : g[v]) if (u != p)
        dfs3(u, v, used, order, g);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL

    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int> > g(n);
    vector<int> sz(n);
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b), g[b].pb(a);
    }
    int c = -1, d = -1;
    dfs(0, 0, n, c, g, sz);
    dfs(c, c, n, d, g, sz);
    ll cap = accumulate(all(sz), -1ll * n);
    ll mn = 0;
    forn(i, n) mn += sz[i] % 2;
    mn -= sz[c] % 2;
    if (k % 2 == cap % 2 && mn <= k && k <= cap)
    {
        cout << "YES\n";
        int m = g[c].size();
        set<pii, greater<pii> > S;
        int pnt = 0;
        for (auto u : g[c])
            S.insert({sz[u], pnt}), pnt++;
        vector<set<pii, greater<pii> > > Vertices(m);
        vector<int> dist(n);
        pnt = 0;
        for (auto u : g[c])
            dfs2(u, c, pnt, Vertices, g, dist), pnt++;
        vector<int> used(n);
        while (cap > k)
        {
            ll rem = cap - k;
            auto it = *(S.begin());
            S.erase(S.begin());
            it.first -= 2;
            S.insert(it);
            int tree = it.second;
            auto &Set = Vertices[tree];
            while (Set.size())
            {
                auto it = *Set.begin();
                if (2 * it.first > rem)
                {
                    Set.erase(Set.begin());
                    continue;
                }
                int v = it.second;
                int alpha = -1, beta = -1;
                while (child[v].size())
                {
                    int u = child[v].back();
                    if (!used[u])
                    {
                        used[u] = 1;
                        if (alpha == -1) alpha = u;
                        else beta = u;
                        child[v].pop_back();
                    }
                    else
                    {
                        child[v].pop_back();
                    }
                    if (beta != -1) break;
                }
                if (alpha != -1 && beta != -1)
                {
                    cap -= 2 * it.first;
                    cout << alpha + 1 << " " << beta + 1 << "\n";
                    break;
                }
                else if (alpha != -1)
                {
                    cap -= 2 * it.first;
                    cout << alpha + 1 << " " << v + 1 << "\n";
                    used[v] = 1;
                    break;
                }
                else
                {
                    Set.erase(Set.begin());
                }
            }
        }
        vector<int> order;
        dfs3(c, c, used, order, g);
        int D = order.size() / 2;
        for (int i = 0; i < D; i++)
            cout << order[i] + 1 << " " << order[i + D] + 1 << "\n";
    }
    else
    {
        cout << "NO";
    }
}