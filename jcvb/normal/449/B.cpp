#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#define inf 100000000000000000ll
using namespace std;
typedef long long ll;
int n,m,k;
struct edge{int v,next,w,id;}e[2000005];int etot=0;
int g[500005];
void ae(int u,int v,int w,int id){
	e[etot].id=id;e[etot].v=v;e[etot].w=w;e[etot].next=g[u];g[u]=etot++;
}
struct node{
	int u;ll w;
};
int operator<(const node&a,const node&b){
	return a.w>b.w;
}
int v1[500005],w1[500005];
ll dis[500005];
int vis[500005]={0};
priority_queue<node> qu;
int cnt[500005]={0};
int main(){
	memset(g,-1,sizeof(g));
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		ae(u,v,w,0);ae(v,u,w,0);
	}
	for (int i=1;i<=k;i++){
		scanf("%d%d",&v1[i],&w1[i]);
		ae(1,v1[i],w1[i],1);
	}
	for (int i=1;i<=n;i++)dis[i]=inf;
	dis[1]=0;
	qu.push((node){1,0});
	while(!qu.empty()){
		node tm=qu.top();qu.pop();
		int u=tm.u;
		if(vis[u])continue;
		vis[u]=1;
		for (int i=g[u];~i;i=e[i].next){
			if(dis[u]+e[i].w<dis[e[i].v]){
				dis[e[i].v]=dis[u]+e[i].w;
				qu.push((node){e[i].v,dis[e[i].v]});
			}
		}
	}
	for (int u=1;u<=n;u++){
		for (int i=g[u];~i;i=e[i].next)if(dis[u]+e[i].w==dis[e[i].v])cnt[e[i].v]++;
	}	
	int ans=0;
	for (int u=1;u<=n;u++){
		for (int i=g[u];~i;i=e[i].next)if(e[i].id){
			if(dis[u]+e[i].w!=dis[e[i].v])ans++;
			else{
				if(cnt[e[i].v]>1){
					cnt[e[i].v]--;
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}