#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200002];
int visited[200002];
int pai[200002];
int dist[200002];
int anc[200002][20];
int maxd = -1;


void dfs(int v)
{
    visited[v] = 1;
    for(int x : adj[v])
    {
        if(visited[x]) continue;
        pai[x] = v;
        dist[x] = dist[v] + 1;
        dfs(x);
    }
    if(dist[v] > maxd)
        maxd = dist[v];
}

void ancestral(int n)
{
    for (int v = 1; v <= n; v++)
        anc[v][0] = pai[v];
    for (int i = 1; i <= (int)floor(log2(maxd)); i++)
        for(int v = 1; v <= n; v++)
            anc[v][i] = anc[anc[v][i-1]][i-1];
}

int lca(int v, int u)
{
    if (dist[v] < dist[u])
        swap(v,u);
    for(int i = (int)floor(log2(maxd)); i >= 0; i--)
        if((dist[v] - (int)pow(2,i)) >= dist[u])
            v = anc[v][i] ;
    if (u == v)
        return u;
    for (int i = (int)floor(log2(maxd)); i >= 0; i--)
        if(anc[v][i] != anc[u][i])
        {  
            v = anc[v][i];
            u = anc[u][i];
        }
    return pai[v];
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    char res[200000];
    cin >> n >> m;
    for(int i = 0; i < n-1; i++)
    {
        int a , b;
        cin >> a >> b;
        //Montando a Arvore, com o vetor de adjacencias
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < 200002; i++)
        dist[i] = -1;
    dist[1] = 0;
    dfs(1);
    ancestral(n);
    for (int i = 0; i < m; i++)
    {
        int k,ki, aux,ite_m;
        cin >> ki;
        vector<int> que;
        int max_dist = -2;
        for (int j = 0; j < ki; j++)
        {
            cin >> aux;
            que.push_back(aux);
        }
        for(int ite = ki-1; ite >= 0; ite--)
        {
            if(dist[que[ite]] > max_dist)
            {

                ite_m = ite;
                k = que[ite];
                max_dist = dist[que[ite]];
                if(max_dist == maxd)
                    break;
            }
        }
        que.erase(que.begin()+ite_m);
        int it = 0;
        while(it < que.size())
        {
            int rlca = lca(k,que[it]);
            if (rlca == que[it] || rlca == pai[que[it]])
            {
                que.erase(que.begin()+it);
            }
            else
                it++;
            
        }
        if (que.size() == 0)
        {
            res[i] = 'y';
        }
        else
            res[i] = 'n';
    }
    for (int i = 0; i < m; i++)
    {
        if(res[i] == 'y')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
        
}