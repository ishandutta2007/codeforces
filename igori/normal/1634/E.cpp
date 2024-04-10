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
    vector<vector<int> > a(n);
    vector<int> small;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i] = vector<int>(k);
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            small.push_back(a[i][j]);
        }
    }
    uniq(small);
    map<int, int> mm;
    for (int i = 0; i < small.size(); i++) mm[small[i]] = i;

    vector<vector<pair<int, int> > > g(small.size() + n);
    vector<int> vis;
    vector<pair<int, int> > where;
    vector<string> s(n);
    vector<int> pnt(g.size());
    for (int i = 0; i < n; i++)
    {
        s[i] = string(a[i].size(), '.');
        for (int j = 0; j < a[i].size(); j++)
        {
            a[i][j] = mm[a[i][j]];
            g[i].push_back({n + a[i][j], vis.size()});
            g[n + a[i][j]].push_back({i, vis.size()});
            vis.push_back(0);
            where.push_back({i, j});
        }
    }
    for (int i = 0; i < g.size(); i++)
    {
        if (g[i].size() % 2 == 1)
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < g.size(); i++)
    {
        if (g[i].size() && vis[g[i][0].second] == 0)
        {
            vector<int> path;
            vector<int> st = {i};
            while (st.size())
            {
                int t = 0;
                int v = st.back();
                while (pnt[v] < g[v].size())
                {
                    //cout << v << " " << pnt[v] << " " << g[v].size() << endl;
                    if (vis[g[v][pnt[v]].second] == 0)
                    {
                        path.push_back(g[v][pnt[v]].second);
                        vis[g[v][pnt[v]].second] = 1;
                        //cout << "! " << g[v][pnt[v]].first << endl;
                        st.push_back(g[v][pnt[v]].first);
                        t = 1;
                        break;
                    }
                    pnt[v]++;
                }
                if (t == 0)
                    st.pop_back();
            }
            for (int j = 0; j < path.size(); j++)
            {
                s[where[path[j]].first][where[path[j]].second] = j % 2 ? 'L' : 'R';
            }
        }
    }
    cout << "YES\n";
    for (auto e : s) cout << e << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}