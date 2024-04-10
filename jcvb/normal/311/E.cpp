#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
#define INF 1000000000
#define MAXE 500000
#define MAXV 20050
using namespace std;
struct edge{
       int v,f,next;
}e[MAXE];int etot=0;
int g[MAXV];int s,t;
void ae(int u,int v,int f){
     e[etot].f=f;e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
     e[etot].f=0;e[etot].v=u;e[etot].next=g[v];g[v]=etot++;
}
int qu[MAXV],p,q;
int d[MAXV];
int label(){
     p=q=0;
     qu[q++]=s;
     for (int i=1;i<=t;i++)d[i]=0;
     d[s]=1;
     int u,v;
     while(p!=q){
                 u=qu[p++];
                 for (int i=g[u];~i;i=e[i].next)
                     if(e[i].f && !d[v=e[i].v]){
                               d[v]=d[u]+1;
                               if(v==t)return 1;
                               qu[q++]=v;
                     }
     }
     return 0;
}
int aug(int u,int mi=INF){
    if(u==t)return mi;
    int sum=0,v,del;
    for (int i=g[u];~i;i=e[i].next)
        if(e[i].f && d[v=e[i].v]==d[u]+1)
                  if(del=aug(v,min(mi,e[i].f))){
                          e[i].f-=del;
                          e[i^1].f+=del;
                          mi-=del;
                          sum+=del;
                          if(!mi)break;
                  }
    if(!sum)d[u]=-1;
    return sum;
}
int dinic(){
 	int flow=0;
     while(label()){
                    int tmp=aug(s,INF);
                    flow+=tmp;
     }
     return flow;
}
int gen[10005];
int tmp[15];
int main()
{
	memset(g,-1,sizeof(g));
	int n,m,g;scanf("%d%d%d",&n,&m,&g);
	s=n+m+1;t=s+1;
	for (int i=1;i<=n;i++)scanf("%d",&gen[i]);
	for (int i=1;i<=n;i++){
		int v;scanf("%d",&v);
		if(gen[i])ae(i,t,v);
		else ae(s,i,v);
	}
	int su=0;
	for (int i=n+1;i<=n+m;i++){
		int ge,w,k;scanf("%d%d%d",&ge,&w,&k);su+=w;
		for (int j=1;j<=k;j++)scanf("%d",&tmp[j]);
		int tm;scanf("%d",&tm);
		if(tm==1)w+=g;
		if(ge){
			for (int j=1;j<=k;j++)ae(tmp[j],i,INF);
			ae(i,t,w);
		}else{
			for (int j=1;j<=k;j++)ae(i,tmp[j],INF);
			ae(s,i,w);
		}
	}
	printf("%d\n",su-dinic());
	return 0;
}