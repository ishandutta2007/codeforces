const int LG = 21;
const int N = 500005;
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

void dfs(int v, int paint, vector<int> &col, vector<vector<pii> > &graph, vector<int> &need, int &cnt0, int &cnt1, int &fl)
{
    col[v] = paint;
    if (paint == -1) cnt0++;
    else cnt1++;
    if (need[v] != 0)
    {
        if (paint == need[v]) fl = 1;
        else fl = -1;
    }
    for (auto p : graph[v])
    {
        if (col[p.first] == 0)
        {
            dfs(p.first, p.second * paint, col, graph, need, cnt0, cnt1, fl);
        }
    }
}

int root[N];
vector<int> suns[N];
int cntsame[N]; // cntother[i] = suns[i].size() - cntsame[i]
int sametoroot[N];
int fl[N];
int ans;

int Root(int x)
{
    return root[x] == x ? x : Root(root[x]);
}

void complete_data(int v, int FL)
{
    int x = Root(v);
    if (fl[x] != 0)
        return;
    FL *= sametoroot[v];
    int took_before = min(cntsame[x], (int)suns[x].size() - cntsame[x]);
    ans -= took_before;
    //cout << v << " " << FL << " " << x << " " << cntsame[x] << endl;
    fl[x] = FL;
    if (FL == 1) ans += cntsame[x];
    else ans += suns[x].size() - cntsame[x];
}

void Merge(int v, int u, int w)
{
    int x = Root(v), y = Root(u);
    if (x == y) return;
    if (suns[x].size() > suns[y].size())
    {
        swap(v, u);
        swap(x, y);
    }
    // Root = y
    w *= sametoroot[v];
    w *= sametoroot[u];
    if (fl[x] == 0 && fl[y] == 0)
    {
        ans -= min(cntsame[x], (int)suns[x].size() - cntsame[x]);
        ans -= min(cntsame[y], (int)suns[y].size() - cntsame[y]);
    }
    if (fl[x] == 0 && fl[y] != 0)
    {
        complete_data(x, fl[y] * w);
    }
    if (fl[x] != 0 && fl[y] == 0)
    {
        complete_data(y, fl[x] * w);
    }
    for (auto u : suns[x])
    {
        suns[y].push_back(u);
        sametoroot[u] *= w;
        if (sametoroot[u] == 1) cntsame[y]++;
    }
    if (fl[x] == 0 && fl[y] == 0)
    {
        ans += min(cntsame[y], (int)suns[y].size() - cntsame[y]);
    }
    root[x] = y;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int> > contains(n);
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int x = 0;
            cin >> x;
            x--;
            contains[x].push_back(i);
        }
    }
    vector<vector<pii> > graph(k);
    vector<int> need(k, 0);

    for (int i = 0; i < k; i++) root[i] = i;
    for (int i = 0; i < k; i++) suns[i].push_back(i);
    for (int i = 0; i < k; i++) cntsame[i] = 1;
    for (int i = 0; i < k; i++) sametoroot[i] = 1;

    for (int i = 0; i < n; i++)
    {
        if (contains[i].size() == 1)
        {
            if (s[i] == '1')
            {
                need[contains[i][0]] = -1;
                complete_data(contains[i][0], -1);
            }
            else
            {
                need[contains[i][0]] = 1;
                complete_data(contains[i][0], 1);
            }
        }
        if (contains[i].size() == 2)
        {
            if (s[i] == '0')
            {
                graph[contains[i][0]].pb({contains[i][1], -1});
                graph[contains[i][1]].pb({contains[i][0], -1});
                Merge(contains[i][0], contains[i][1], -1);
            }
            else
            {
                graph[contains[i][0]].pb({contains[i][1], 1});
                graph[contains[i][1]].pb({contains[i][0], 1});
                Merge(contains[i][0], contains[i][1], 1);
            }
        }
        /*int ans = 0;
        vector<int> col(k);
        for (int j = 0; j < k; j++)
        {
            if (col[j] == 0)
            {
                int cnt0 = 0, cnt1 = 0, fl = 0;
                dfs(j, -1, col, graph, need, cnt0, cnt1, fl);
                if (fl == 0) ans += min(cnt0, cnt1);
                if (fl == 1) ans += cnt1;
                if (fl == -1) ans += cnt0;
            }
        }*/
        cout << ans << endl;
    }
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