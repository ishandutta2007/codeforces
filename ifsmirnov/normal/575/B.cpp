#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 2e5;
const int maxk = 1e6 + 100;

vector<pair<int, int>> g[maxn];
vector<int> ord;

int col[maxk];

int get(int u)
{
    if (col[u] == u)
        return u;
    return col[u] = get(col[u]);
}

void join(int u, int v)
{
    u = get(u), v = get(v);
    col[v] = u;
}

bool usedq[maxk];
vector<pair<int, int>> q[maxn];

int cnt[maxn][2];
int delta[maxn][2];
int lca[maxk];

void dfs(int u, int prev = -1)
{
    for (auto p: q[u])
    {
        int id = p.first, v = p.second;
        if (usedq[id])
        {
            int w = get(v);
//            cerr << u + 1 << ' ' << v + 1 << ' ' << w + 1 << '\n';
            delta[w][0]--;
            delta[w][1]--;
        }
        else
            usedq[id] = true;
    }
    for (auto p: g[u])
        if (p.first != prev)
        {
            dfs(p.first, u);
            join(u, p.first);
        }
}

const int mod = int(1e9) + 7;

int pow2[maxk];
int ans;

void dfs2(int u, int prev = -1)
{
    cnt[u][0] = delta[u][0];
    cnt[u][1] = delta[u][1];
    for (auto p: g[u])
        if (p.first != prev)
        {
            dfs2(p.first, u);
            cnt[u][0] += cnt[p.first][0];
            cnt[u][1] += cnt[p.first][1];
        }
    for (auto p: g[u])
        if (p.first != prev)
        {
            if (p.second == 1)
            {
                int diff = cnt[p.first][0];
                ans = (ans + pow2[diff]) % mod;
                ans = (ans + mod - 1) % mod;
            }
            else if (p.second == -1)
            {
                int diff = cnt[p.first][1];
                ans = (ans + pow2[diff]) % mod;
                ans = (ans + mod - 1) % mod;
            }
        }
}

int solve()
{
    pow2[0] = 1;
    forab (i, 1, maxk)
        pow2[i] = (pow2[i - 1] * 2) % mod;
    int n;
    cin >> n;
    forn (i, n)
        col[i] = i;
    forn (i, n - 1)
    {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        --u, --v;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, -t);
    }
    int k;
    cin >> k;
    ord.push_back(0);
    forn (i, k)
    {
        int u;
        scanf("%d", &u);
        --u;
        int from = ord.back();
        ord.push_back(u);
        q[u].emplace_back(i, from);
        q[from].emplace_back(i, u);
        delta[from][0]++;
        delta[u][1]++;
    }
    dfs(0);
    dfs2(0);
//    forn (i, n)
//        cerr << cnt[i][0] << ' ' << cnt[i][1] << '\n';
    cout << ans << '\n';
    return 0;
}