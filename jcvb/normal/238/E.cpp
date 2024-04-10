#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define inf 1000000000
using namespace std;
int g[105][105];
int n,m,S,T;
int d[105][105],cnt[105][105]={0};
int U[105],V[105];int nu;
int f[105][105];
int lef[105][105]={0};
int vis[105][105]={0};
int on(int u,int s,int t){
    if(d[s][u]+d[u][t]!=d[s][t])return 0;
    if(cnt[s][u]*cnt[u][t]==cnt[s][t])return 2;
    return 1;
}
int qu[10005],qi[10005];int p,q;
int main()
{
    scanf("%d%d%d%d",&n,&m,&S,&T);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)g[i][j]=d[i][j]=inf;
    for (int i=1;i<=n;i++)g[i][i]=d[i][i]=0,cnt[i][i]=1;
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        g[x][y]=d[x][y]=cnt[x][y]=1;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)if(i!=k && k!=j && j!=i){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    cnt[i][j]=cnt[i][k]*cnt[k][j];
                }else if(d[i][k]+d[k][j]==d[i][j])
                    cnt[i][j]+=cnt[i][k]*cnt[k][j];
            }
    scanf("%d",&nu);
    for (int i=1;i<=nu;i++){
        scanf("%d%d",&U[i],&V[i]);
        if(d[U[i]][V[i]]>=inf)nu--,i--;
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<=nu;j++)f[i][j]=inf;
    f[T][0]=0;
    for (int u=1;u<=n;u++)
        for (int i=1;i<=nu;i++)if(on(u,U[i],V[i]))
            for (int v=1;v<=n;v++)if(g[u][v]==1 && on(v,u,V[i]))lef[u][i]++;
    for (int dis=0;dis<=nu;dis++){
        p=q=0;      
        for (int u=1;u<=n;u++)for (int i=0;i<=nu;i++)if(f[u][i]==dis){
            qu[q]=u;qi[q++]=i;
        }
        while(p!=q){
            int v=qu[p],i=qi[p++];
            if(i && on(v,U[i],V[i])==2)f[v][0]=min(f[v][0],f[v][i]+1);
            if(i && !vis[v][0]){
                for (int u=1;u<=n;u++)if(g[u][v]==1 && on(v,u,V[i]) && on(u,U[i],V[i])){
                    lef[u][i]--;
                    if(!lef[u][i]){
                        f[u][i]=dis;
                        qu[q]=u;qi[q++]=i;
                    }
                }
            }else if(!i){
                for (int j=1;j<=nu;j++)if(!vis[v][j]){
                    for (int u=1;u<=n;u++)if(g[u][v]==1 && on(v,u,V[j]) && on(u,U[j],V[j])){
                        lef[u][j]--;
                        if(!lef[u][j]){
                            f[u][j]=dis;
                            qu[q]=u;qi[q++]=j;
                        }
                    }
                }
            }
            vis[v][i]=1;
        }
    }
    if(f[S][0]>=inf)printf("-1\n");
    else printf("%d\n",f[S][0]);
    return 0;
}