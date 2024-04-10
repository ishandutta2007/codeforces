#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

const int MAXN = 1e6+6;

struct edge {int v, r, c;};

int t, c;
int pre[MAXN];
vector<edge> E[MAXN];
stack<edge*> S;

inline void add_edge(int u, int v)
{
    E[u].push_back(edge({v, E[v].size(), -1}));
    E[v].push_back(edge({u, E[u].size()-1, -1}));
}

int dfs(int u, int p = -1) 
{
    pre[u] = ++t;
    int lu = pre[u], lv;

    for(edge &e : E[u]) 
    {
        if(e.c == -1)
        {
            S.push(&e);
        }

        if(!pre[e.v])
        {
            lv = dfs(e.v, u);
            lu = min(lu, lv);
            if(lv >= pre[u] || p < 0)
            {
                edge* f;
                do {
                    (f=S.top())->c=c;
                    E[f->v][f->r].c = c;
                    S.pop();
                } while(f != &e);
                ++c;
            }
        }

        else if(e.v != p)
        {
            lu = min(lu, pre[e.v]);
        }
    }
    return lu;
}

const int L = 21;

vector<int> G[MAXN];
int depth[MAXN];
int parent[MAXN][L];

void calc_parents(int v, int p)
{
    parent[v][0] = p;
    for(auto z : G[v])
    {
        if(z == parent[v][0])
        {
            continue;
        }

        depth[z] = depth[v] + 1;
        calc_parents(z, v);
    }
}

int find_dist(int a, int b)
{
    int res = 0;
    if(depth[a] > depth[b])
    {
        swap(a, b);
    }

    for(int i=L-1;i>=0;i--)
    {
        if(depth[a] <= depth[parent[b][i]])
        {
            res += depth[b] - depth[parent[b][i]];
            b = parent[b][i];
        }
    }

    if(a == b)
    {
        return res; 
    }

    for(int i=L-1;i>=0;i--)
    {
        if(parent[a][i] != parent[b][i])
        {
            res += 2*(depth[a] - depth[parent[a][i]]);
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return res + 2;
}

int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    for(int i=1;i<=m;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b);
    }

    dfs(1);

    int new_n = n;
    for(int i=1;i<=n;i++)
    {
        for(auto z : E[i])
        {
            G[i].push_back(n + 1 + z.c);
            G[n + 1 + z.c].push_back(i);
            new_n = max(new_n, n + 1 + z.c);
        }
    }

    n = new_n;

    for(int i=1;i<=n;i++)
    {
        sort(G[i].begin(), G[i].end());
        G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
    }

    depth[1] = 0;
    calc_parents(1, 1);

    for(int k=1;k<L;k++)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }

    while(q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", find_dist(a, b)/2);
    }
}