#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int rmax = 12;

struct pt
{
    ll x, y;
};

struct circle
{
    pt c;
    ll r;
};

ll dist2(const pt& a, const pt& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool inside(const circle& a, const circle& b)
{
    ll d2 = dist2(a.c, b.c);
    return b.r > a.r && d2 < b.r * b.r;
}

vector<vector<int> > g;
vector<vector<int> > parent;
vector<int> t_in, t_out;
int timer = 0;

void dfs(int v, int p)
{
    parent[v][0] = p;
    t_in[v] = timer++;
    for (int to : g[v]) {
        dfs(to, v);
    }
    t_out[v] = timer++;
}

bool ancestor(int u, int v)
{
    return t_in[u] <= t_in[v] && t_out[u] >= t_out[v];
}

int lca(int u, int v)
{
    if (ancestor(u, v)) {
        return u;
    }
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(parent[u][r], v)) {
            u = parent[u][r];
        }
    }
    return parent[u][0];
}

int len(int u, int w)
{
    if (u == w) {
        return 0;
    }
    int ans = 0;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(parent[u][r], w)) {
            ans += (1 << r);
            u = parent[u][r];
        }
    }
    return ans + 1;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m, tt;
    scanf("%d%d%d", &n, &m, &tt);

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }

    vector<circle> c(m + 1);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld%lld%lld", &c[i].r, &c[i].c.x, &c[i].c.y);
    }

    g.resize(m + 1);
    vector<int> cnt(m + 1);
    vector<vector<int> > in(m + 1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == j) {
                continue;
            }
            if (inside(c[j], c[i])) {
                in[i].pb(j);
                ++cnt[j];
            }
        }
    }

    queue<int> q;

    for (int i = 1; i <= m; ++i) {
        if (cnt[i] == 0) {
            q.push(i);
            g[0].pb(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : in[v]) {
            --cnt[u];
            if (!cnt[u]) {
                g[v].pb(u);
                q.push(u);
            }
        }
    }

    /*for (int i = 0; i <= m; ++i) {
        for (int to : g[i]) {
            cout << i << " -> " << to << "\n";
        }
    }*/

    parent.resize(m + 1);
    for (int i = 0; i <= m; ++i) {
        parent[i].resize(rmax);
    }
    t_in.resize(m + 1);
    t_out.resize(m + 1);

    dfs(0, 0);

    for (int r = 1; r < rmax; ++r) {
        for (int i = 0; i <= m; ++i) {
            int t = parent[i][r - 1];
            parent[i][r] = parent[t][r - 1];
        }
    }

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        circle tmp = {p[i], 0};
        for (int j = 1; j <= m; ++j) {
            if (inside(tmp, c[j]) && t_in[j] > t_in[pos[i]]) {
                pos[i] = j;
            }
        }
    }

    while (tt--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        int u = pos[x], v = pos[y];
        int w = lca(u, v);
        printf("%d\n", len(u, w) + len(v, w));
    }

}