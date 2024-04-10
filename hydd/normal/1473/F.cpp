#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,s,t,a[3100],dis[3100]; bool vis[3100];
int edgenum=1,V[210000],F[210000],Next[210000],Head[3100],cur[3100];
queue<int> que;
void addedge(int u,int v,int f){
	V[++edgenum]=v;
	F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Addedge(int u,int v,int f){
	addedge(u,v,f);
	addedge(v,u,0);
}
bool bfs(){
	for (int i=s;i<=t;i++) dis[i]=INF;
	que.push(t); dis[t]=0;
	while (!que.empty()){
		int u=que.front(); que.pop();
		for (int e=Head[u];e;e=Next[e])
			if (F[e^1]&&dis[V[e]]>dis[u]+1){
				dis[V[e]]=dis[u]+1;
				que.push(V[e]);
			}
	}
	return dis[s]<INF;
}
int dfs(int u,int flow){
	if (u==t) return flow;
	int used=0;
	for (int &e=cur[u];e;e=Next[e])
		if (F[e]&&dis[V[e]]+1==dis[u]){
			int tmp=dfs(V[e],min(F[e],flow-used));
			used+=tmp; F[e]-=tmp; F[e^1]+=tmp;
			if (used==flow) break;
		}
	return used;
}
int dinic(){
	int flow=0;
	while (bfs()){
		for (int i=s;i<=t;i++) cur[i]=Head[i];
		flow+=dfs(s,INF);
	}
	return flow;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=100;j++) vis[j]=false;
		for (int j=i-1;j>=1;j--)
			if (a[i]%a[j]==0&&!vis[a[j]]){
				vis[a[j]]=true;
				Addedge(i,j,INF);
			}
	}
	s=0; t=n+1; int x,sum=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x<0) Addedge(i,t,-x);
		else Addedge(s,i,x),sum+=x;
	}
	printf("%d\n",sum-dinic());
	return 0;
}