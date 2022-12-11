#include <bits/stdc++.h>

#define mp std::make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

int max(int a, int b)
{
    return (a > b ? a : b);
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

typedef long long ll;
typedef long double ld;
typedef std::vector <int> vi;

const ll inf = 1000000000ll * 1000000000ll;

int n, m, s, t;

struct edge
{
    int from, to;
    ll cost;
};

std::vector <edge> edges;
std::vector <std::vector <int> > g;
std::vector <ll> dist_s, dist_t;

struct comp_s
{
    bool operator () (int a, int b)
    {
        return dist_s[a] < dist_s[b] || dist_s[a] == dist_s[b] && a < b;
    }
};

struct comp_t
{
    bool operator () (int a, int b)
    {
        return dist_t[a] < dist_t[b] || dist_t[a] == dist_t[b] && a < b;
    }
};

std::vector <bool> good;
std::vector <bool> yes, used;
std::vector <int> tin, fup;
int timer = 0;

void dfs(int v, int e_num)
{
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int i = 0; i < sz(g[v]); i++)
        if (good[g[v][i]])
    {
        edge e = edges[g[v][i]];
        if (e_num != -1 && g[v][i] % m == e_num % m) continue;
        if (used[e.to]) fup[v] = min(fup[v], tin[e.to]);
        else
        {
            dfs(e.to, g[v][i]);
            fup[v] = min(fup[v], fup[e.to]);
            if (fup[e.to] > tin[v])
            {
                if (g[v][i] < m) yes[g[v][i]] = true;
                else yes[g[v][i] - m] = true;
            }
        }
    }
}

int main()
{

    scanf("%d%d%d%d", &n, &m, &s, &t);
    --s, --t;

    edges.resize(2 * m);
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        edge e;
        scanf("%d%d%I64d", &e.from, &e.to, &e.cost);
        --e.from, --e.to;
        g[e.from].pb(i);
        edges[i] = e;
        std::swap(e.to, e.from);
        g[e.from].pb(i + m);
        edges[i + m] = e;
    }

    dist_s.assign(n, inf);
    std::set <int, comp_s> q_s;
    dist_s[s] = 0;
    q_s.insert(s);

    while (!q_s.empty())
    {
        std::set <int, comp_s> :: iterator it = q_s.begin();
        int u = *it;
        q_s.erase(u);
        for (int i = 0; i < sz(g[u]); i++)
            if (g[u][i] < m)
        {
            edge e = edges[g[u][i]];
            if (dist_s[e.to] > dist_s[e.from] + e.cost)
            {
                q_s.erase(e.to);
                dist_s[e.to] = dist_s[e.from] + e.cost;
                q_s.insert(e.to);
            }
        }
    }

    dist_t.assign(n, inf);
    std::set <int, comp_t> q_t;
    dist_t[t] = 0;
    q_t.insert(t);

    while (!q_t.empty())
    {
        std::set <int, comp_t> :: iterator it = q_t.begin();
        int u = *it;
        q_t.erase(u);
        for (int i = 0; i < sz(g[u]); i++)
            if (g[u][i] >= m)
        {
            edge e = edges[g[u][i]];
            if (dist_t[e.to] > dist_t[e.from] + e.cost)
            {
                q_t.erase(e.to);
                dist_t[e.to] = dist_t[e.from] + e.cost;
                q_t.insert(e.to);
            }
        }
    }

    good.assign(2 * m, false);
    for (int i = 0; i < m; i++)
    {
        edge e = edges[i];
        if (dist_s[e.from] + e.cost + dist_t[e.to] == dist_s[t])
        {
            good[i] = true;
            good[i + m] = true;
        }
    }

    yes.assign(m, false);
    used.assign(2 * m, false);
    tin.resize(n);
    fup.resize(n);

    dfs(s, -1);

    for (int i = 0; i < m; i++)
    {
        if (yes[i])
        {
            printf("YES\n");
            continue;
        }
        ll sum = dist_s[edges[i].from] + edges[i].cost + dist_t[edges[i].to];
        if (edges[i].cost - sum + dist_s[t] >= 2) printf("CAN %I64d\n", sum - (dist_s[t] - 1));
        else printf("NO\n");
    }

}