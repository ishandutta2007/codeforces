#include <iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int n,a[3000][3000],t,topo;
bool mark[3000],mark2[3000];

void dfs2(int v)
{
    t++;
    mark2[v]=true;
    for(int u=1;u<=n;u++)
    {
        if(!mark2[u] && a[u][v]>0)
            dfs2(u);
    }
}

void dfs(int v)
{
    mark[v]=true;
    for(int u=1;u<=n;u++)
    {
        if(!mark[u] && a[v][u]>0)
            dfs(u);
    }
    topo=v;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        if(!mark[i])
            dfs(i);
    dfs2(topo);
    if(t!=n)
        printf("NO\n");
    else
        printf("YES\n");
}