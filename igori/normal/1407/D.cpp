const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 22;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

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

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

void bfs(int v, vi &dist, vector<vi> &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<vector<int> > g(n);
    vector<int> dist(n);
    {
        vector<pair<int, int> > st;
        st.push_back({-INF, -1});
        for (int i = 0; i < n; i++)
        {
            while (st.back().first > a[i])
                st.pop_back();
            if (st.back().second != -1)
            {
                //g[i].push_back(st.back().second);
                g[st.back().second].push_back(i);
            }
            st.push_back({a[i], i});
        }
        st = {{-INF, n}};
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.back().first > a[i])
                st.pop_back();
            if (st.back().second != n)
            {
                g[i].push_back(st.back().second);
                //g[st.back().second].push_back(i);
            }
            st.push_back({a[i], i});
        }
    }
    {
        vector<pair<int, int> > st;
        st.push_back({INF, -1});
        for (int i = 0; i < n; i++)
        {
            while (st.back().first < a[i])
                st.pop_back();
            if (st.back().second != -1)
            {
                //g[i].push_back(st.back().second);
                g[st.back().second].push_back(i);
            }
            st.push_back({a[i], i});
        }
        st = {{INF, n}};
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.back().first < a[i])
                st.pop_back();
            if (st.back().second != n)
            {
                g[i].push_back(st.back().second);
                //g[st.back().second].push_back(i);
            }
            st.push_back({a[i], i});
        }
    }
    bfs(0, dist, g);
    cout << dist[n - 1];
}

/* Note:
Check constants at the beginning of the code (MOD, INF, INFLL)
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/