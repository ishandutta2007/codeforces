#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
const long long INF = 1LL<<61;

bool czy[MAXN];
long long dist[MAXN];
vector <int> better[MAXN];
int wyn;

vector <pair <int, int> > G[MAXN];

priority_queue <pair <long long, int> > Q;

void dijkstra(int v)
{
    Q.push(make_pair(0,v));
    dist[v] = 0;
    while(!Q.empty())
    {
        int v = Q.top().second;
        Q.pop();
        if(czy[v]==1)
            continue;
        czy[v] = 1;
        sort(better[v].begin(), better[v].end());
        for(int i=0; i<better[v].size(); i++)
        {
            if(dist[v] <= better[v][i])
                wyn++;
            else
                dist[v] = better[v][i];
        }
        for(int i=0; i<G[v].size(); i++)
        {
            if(czy[G[v][i].first]==0)
            {
                if(dist[G[v][i].first] > dist[v] + G[v][i].second)
                {
                    dist[G[v][i].first] = dist[v] + G[v][i].second;
                    Q.push(make_pair(-dist[G[v][i].first], G[v][i].first));
                }
            }
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++)
        dist[i] = INF;
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    for(int i=0; i<k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        better[a].push_back(b);
        Q.push(make_pair(-b,a));
    }
    dijkstra(1);
    printf("%d\n", wyn);
    return 0;
}