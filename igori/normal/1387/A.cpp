#include <bits/stdc++.h>

const int N = 100020;

using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

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

int ans[N];
vector<int> edges;
vector<int> vertices;
int vis[N];
int w[N];

void dfs(int v, vvi & gr, vi &a, vi &b, vi&c, int here, int rt)
{
	vertices.pb(v);
	vis[v] = rt;
	w[v] = here;
	for (auto i : gr[v]) {
		int u = a[i] + b[i] - v;
	    edges.pb(i);
	    //cout << v << " " << u << endl;
		if (vis[u] != rt)
		{
			dfs(u, gr, a, b, c, c[i] - here, rt);
		}
	}
}

void solve(int v, vvi &gr, vi &a, vi &b, vi &c, vi &col)
{
	edges.clear();
	vertices.clear();
    int X = 1000000000;
	dfs(v, gr, a, b, c, X, X);
	int limits = 0, tt = 0;
	for (auto e : edges)
    {
        if (w[a[e]] + w[b[e]] == c[e]) continue;
        limits = 1;
        int xs = 0, other = 0;
        if (w[a[e]] < 0)
        {
            xs--;
            other += w[a[e]] + X;
        }
        else
        {
            xs++;
            other += w[a[e]] - X;
        }
        if (w[b[e]] < 0)
        {
            xs--;
            other += w[b[e]] + X;
        }
        else
        {
            xs++;
            other += w[b[e]] - X;
        }
        if (xs == 0)
        {
            cout << "NO\n";
            exit(0);
        }
        tt = (c[e] - other) / xs;
    }
    if (limits == 0)
    {
        vector<int> val;
        for (auto v : vertices)
        {
            if (w[v] > 0)
            {
                int z = w[v] - X;
                val.push_back(-z);
            }
            else
            {
                int z = w[v] + X;
                val.push_back(z);
            }
        }
        sort(all(val));
        int z = val[val.size() / 2];
        //cout << z << endl;
        vertices.clear();
        edges.clear();
        dfs(v, gr, a, b, c, z, z);
        int ok = 1;
        for (auto e : edges)
        {
            if (w[a[e]] + w[b[e]] != c[e])
            {
                ok = 0;
            }
        }
        for (auto v : vertices) col[v] = 1;
        assert(ok);
    }
    else
    {
        vertices.clear();
        edges.clear();
        dfs(v, gr, a, b, c, tt, tt);
        int ok = 1;
        for (auto e : edges)
        {
            if (w[a[e]] + w[b[e]] != c[e])
            {
                ok = 0;
            }
        }
        for (auto v : vertices) col[v] = 1;
        if (!ok)
        {
            cout << "NO\n";
            exit(0);
        }
    }
}

signed main()
{
	int n, m;
	cin >> n >> m;
	vvi graph(n);
	vi a(m), b(m), c(m);
	forn(i, m)
	{
		cin >> a[i] >> b[i] >> c[i];
		c[i] *= 2, a[i]--, b[i]--;
		graph[a[i]].pb(i);
		graph[b[i]].pb(i);
	}
	vector<int> col(n);
	forn(i, n)
	{
		if (col[i] == 0)
		{
			solve(i, graph, a, b, c, col);
		}
	}
	printf("YES\n");
	forn(i, n) printf("%.9f ", w[i] / 2.0);
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/