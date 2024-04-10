#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,s,t,x[2100],y[2100],lst[2100];
int edgenum=1,V[510000],F[510000],Next[510000],Head[2100]; double C[510000];
double dis[2100]; bool vis[2100]; double ans; int flow;
queue<int> que;
int sqr(int x){ return x*x;}
double dist(int a,int b){
	return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
}
void addedge(int u,int v,int f,double c){
	V[++edgenum]=v;
	F[edgenum]=f;
	C[edgenum]=c;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Addedge(int u,int v,int f,double c){
	addedge(u,v,f,c);
	addedge(v,u,0,-c);
}
bool SPFA(){
	for (int i=s;i<=t;i++) dis[i]=INF,vis[i]=false;
	que.push(s); dis[s]=0;
	while (!que.empty()){
		int u=que.front(); que.pop();
		for (int e=Head[u];e;e=Next[e])
			if (F[e]&&dis[V[e]]>dis[u]+C[e]){
				dis[V[e]]=dis[u]+C[e];
				lst[V[e]]=e;
				if (!vis[V[e]]) que.push(V[e]),vis[V[e]]=true;
			}
		vis[u]=false;
	}
	return (dis[t]<1e9);
}
int MCMF(){
	int u,tmp;
	while (SPFA()){
		u=t; tmp=INF;
		while (u!=s) tmp=min(tmp,F[lst[u]]),u=V[lst[u]^1];
		u=t; flow+=tmp;
		while (u!=s){
			F[lst[u]]-=tmp; F[lst[u]^1]+=tmp;
			ans+=C[lst[u]]*tmp; u=V[lst[u]^1];
		}
	}
	return flow;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	s=0; t=n+n+1;
	for (int i=1;i<=n;i++){
		Addedge(s,i,2,0);
		Addedge(i+n,t,1,0);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (y[j]<y[i]) Addedge(i,j+n,1,dist(i,j));
	if (MCMF()==n-1) printf("%.8lf\n",ans);
	else puts("-1");
	return 0;
}