#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, ll> pil;

const ll inf = 1000000000ll * 1000000000ll;
const int N = 2005;

struct edge
{
    int from, to;
    ll cost;
};

int n;
vector <ll> price;
vector <vector <pil> > g;

void bfs (int v)
{
    int q[N];
    int qh = 0, qt = 0;
    q[qt++] = v;
    while (qh < qt)
    {
        int u = q[qh++];
        for (int i = 0; i < g[u].size(); i++)
        {
            int to = g[u][i].first;
            if (price[to] == inf) {price[to] = price[u] + g[u][i].second; q[qt++] = to;}
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    vector <vector <ll> > d(n, vector <ll> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        scanf("%I64d", &d[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
        if (i == j && d[i][j]) {printf("NO\n"); return 0;}
        if (d[i][j] != d[j][i]) {printf("NO\n"); return 0;}
    }

    vector <vector <bool> > predok(n, vector <bool> (n, false));
    vector <int> kol(n, 0);
    /**kol[i] - amount of unused ancestors**/
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        if (i != j && d[0][i] + d[i][j] == d[0][j]) {predok[j][i] = true; ++kol[j];}
    /**predok[j][i] - is i an ancestor to j and i is unused**/

    vector <edge> edges;
    queue <int> q;
    /**if the element if the son of one of used people then it is in q**/
    vector <bool> met(n, false);
    met[0] = true;

    for (int i = 1; i < n; i++)
        if (!kol[i]) {met[i] = true; q.push(i); edge tmp = {0, i, d[0][i]}; edges.pb(tmp);}

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 1; i < n; i++)
            if (!met[i] && predok[i][v])
        {
            predok[i][v] = false;
            --kol[i];
            if (!kol[i]) {met[i] = true; q.push(i); edge tmp = {v, i, d[v][i]}; edges.pb(tmp);}
        }
    }

    if ((int) edges.size() != n - 1) {printf("NO\n"); return 0;}
    g.resize(n);

    for (int i = 0; i < edges.size(); i++)
    {
        g[edges[i].from].pb(mp(edges[i].to, edges[i].cost));
        g[edges[i].to].pb(mp(edges[i].from, edges[i].cost));
        if (edges[i].cost <= 0) {printf("NO\n"); return 0;}
    }

    for (int i = 0; i < n; i++)
    {
        price.assign(n, inf);
        price[i] = 0;
        bfs(i);
        for (int j = 0; j < n; j++)
            if (d[i][j] != price[j]) {printf("NO\n"); return 0;}
    }
    
    printf("YES\n");
    return 0;

}