const int MOD = 998244353;
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

void dfs(int v, int p, vi &dist, vvi &g)
{
    if (v != p) dist[v] = dist[p] + 1;
    for (auto u : g[v]) if (u != p)
        dfs(u, v, dist, g);
}

void solve()
{
    #define tests

    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;

    if (max({d12, d23, d31}) * 2 > d12 + d23 + d31)
    {
        cout << "NO\n";
        return;
    }
    if ((d12 + d23 + d31) % 2 != 0 || (d12 + d23 + d31) / 2 > n - 1)
    {
        cout << "NO\n";
        return;
    }
    vector<int> lens = {d12, d23, d31};
    sort(rall(lens));

    vector<int> path;
    vector<int> path2;

    int allowed = 3;
    path.push_back(0);
    for (int i = 1; i < lens[0]; i++)
    {
        path.push_back(allowed++);
    }
    path.push_back(1);

    int di = (lens[1] + lens[2] - lens[0]) / 2;

    if (di == 0)
    {
        path[lens[1]] = 2;
        for (int i = lens[1] + 1; i + 1 < path.size(); i++)
            path[i]--;
        allowed--;
    }
    else
    {
        path2.push_back(path[lens[1] - di]);
        for (int i = 1; i < di; i++)
            path2.push_back(allowed++);
        path2.push_back(2);
    }
    while (allowed < n)
    {
        path.push_back(allowed++);
    }

    vector<int> perm(3);
    iota(all(perm), 0);
    while (1)
    {
        vector<vector<int> > g(n);

        auto connect = [&](int v, int u)
        {
            if (v < 3) v = perm[v];
            if (u < 3) u = perm[u];
            g[v].pb(u);
            g[u].pb(v);
        };

        for (int i = 0; i + 1 < path.size(); i++)
        {
            connect(path[i], path[i + 1]);
        }
        for (int i = 0; i + 1 < path2.size(); i++)
        {
            connect(path2[i], path2[i + 1]);
        }

        //for (int i = 0; i < path.size(); i++) cerr << path[i] << " "; cerr << "\n";
        //for (int i = 0; i < path2.size(); i++) cerr << path2[i] << " "; cerr << "\n";
        //for (int i = 0; i < n; i++) for (auto e : g[i]) cerr << i << " -> " << e << "\n";

        vvi dist(3, vi(n));
        for (int i = 0; i < 3; i++)
        {
            dfs(i, i, dist[i], g);
        }

        if (dist[0][1] == d12 && dist[1][2] == d23 && dist[2][0] == d31)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                for (auto e : g[i])
                    if (i < e) cout << i + 1 << " " << e + 1 << "\n";
            return;
        }

        if (!next_permutation(all(perm)))
        {
            break;
        }
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