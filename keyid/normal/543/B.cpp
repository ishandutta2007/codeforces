#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;

queue <int> q;
vector <int> G[MAXN];
int d[MAXN][MAXN];
bool vis[MAXN];

void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    d[s][s]=0;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if (!vis[v])
            {
                vis[v]=true;
                d[s][v]=d[s][u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n,m,s1,t1,l1,s2,t2,l2;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    for (int i=1;i<=n;i++) bfs(i);
    if (d[s1][t1]>l1||d[s2][t2]>l2)
    {
        printf("-1");
        return 0;
    }
    int ans=max(0,m-d[s1][t1]-d[s2][t2]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            int d1=d[s1][i]+d[i][j]+d[j][t1],d2=min(d[s2][i]+d[j][t2],d[s2][j]+d[i][t2])+d[i][j];
            if (d1<=l1&&d2<=l2) ans=max(ans,m-d1-d2+d[i][j]);
        }
    printf("%d",ans);
    return 0;
}