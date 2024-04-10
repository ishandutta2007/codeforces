#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define inf 1050000000000000ll
using namespace std;
typedef long long ll;
int n;
int w[2005][2005];
int d[2005],con[2005];
int vis[2005];
struct edge{
       int v,next,w;
}e[4005];int etot=0;int g[2005];
void ae(int u,int v){
     int w=::w[u][v];
     e[etot].v=v;e[etot].next=g[u];e[etot].w=w;g[u]=etot++;
 //    printf("%d %d\n",u,v);
}
ll dis[2005];
int qu[2005],p,q,pre[2005];
int check(int rt){
     for (int i=1;i<=n;i++)dis[i]=inf;
     dis[rt]=0;
     p=q=0;pre[rt]=0;
     qu[q++]=rt;
     while(p!=q){
                 int u=qu[p++];
                 for (int i=g[u];~i;i=e[i].next)if(e[i].v!=pre[u]){
                     qu[q++]=e[i].v;
                     dis[e[i].v]=dis[u]+e[i].w;
                     pre[e[i].v]=u;
                 }
     }
     for (int i=1;i<=n;i++)if(dis[i]!=w[rt][i])return 0;
     return 1;
     }
int main()
{
    memset(g,-1,sizeof(g));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x;scanf("%d",&x);
			w[i][j]=x;
		}
	for (int i=1;i<=n;i++)
	    for (int j=1;j<=n;j++)
            if(w[i][j]!=w[j][i] || w[i][i]!=0 || (i!=j && w[i][j]<=0)){
                                printf("NO\n");
                                return 0;
            }
	for (int i=0;i<=n;i++)d[i]=2000000000;
	d[1]=0;
	for (int i=1;i<=n;i++){
		int u=0;
		for (int j=1;j<=n;j++)if(!vis[j] && d[j]<d[u])u=j;
		vis[u]=1;
		if(u!=1)ae(u,con[u]),ae(con[u],u);
		for (int j=1;j<=n;j++)if(d[j]>w[u][j]){
            d[j]=w[u][j];
            con[j]=u;
        }
	}
	for (int i=1;i<=n;i++){
        if(!check(i)){
                      printf("NO\n");
                      return 0;
        }
 }
  printf("YES\n");
	return 0;
}