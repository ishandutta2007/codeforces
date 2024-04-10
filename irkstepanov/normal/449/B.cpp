#include <fstream>
#include <iostream>
#include <vector>
#include <set>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll inf = 1000000000ll * 1000000000ll;

vector <ll> dist;

struct comp
{
    bool operator() (int a, int b)
    {
        return dist[a] < dist[b] || (dist[a] == dist[b] && a < b);
    }
};

struct edge
{
    int v;
    ll cost;
};

int main()
{

    int n, m, k;
    int ans = 0;
    cin >> n >> m >> k;

    vector <vector <edge> > g(n);
    dist.resize(n);
    for (int i = 0; i < n; i++)
        dist[i] = inf;

    while (m--)
    {
        int u, v;
        ll x;
        cin >> u >> v >> x;
        --u, --v;
        edge e1 = {v, x};
        edge e2 = {u, x};
        g[u].pb(e1);
        g[v].pb(e2);
    }

    set <int, comp> q;

    vector <bool> rail(n, false);
    dist[0] = 0;
    q.insert(0);

    while (k--)
    {
        int s;
        ll y;
        cin >> s >> y;
        --s;
        if (dist[s] != inf)
        {
            ++ans;
            if (dist[s] > y)
            {
                q.erase(s);
                dist[s] = y;
                q.insert(s);
            }
        }
        else
        {
            dist[s] = y;
            q.insert(s);
            rail[s] = true;
        }
    }

    while (!q.empty())
    {
        set <int, comp> :: iterator it = q.begin();
        int u = *it;
        q.erase(u);
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].v;
            ll len = dist[u] + g[u][i].cost;
            if (dist[v] >= len)
            {
                if (rail[v]) ++ans;
                rail[v] = false;
                q.erase(v);
                dist[v] = len;
                q.insert(v);
            }
        }
    }

    cout << ans;

}

/*if we see l and r both for the first time then call make_new_set
    if l has been senn but not r then we need to push r to l's conditions
    the same stuff here about r
    if we have seen both l and r
    {
        if they are in the same tree then we just need to check the query
        otherwise we need to unite two big trees
    }*/