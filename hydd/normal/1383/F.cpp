#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n,m,k,q,s,t,lg[11000],num[11000],sum[11000]; int u[11],v[11],w[11];
int head,tail,que[11000],dep[11000],lst[11000]; bool vis[11000];
int edgenum,vet[41000],val[41000],Next[41000],Head[11000];
void addedge(int u,int v,int c){
	vet[++edgenum]=v; val[edgenum]=c;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int x,int y=0){
	addedge(u,v,x);
	addedge(v,u,y);
}
bool bfs(){
	for (int i=s;i<=t;i++) dep[i]=-INF;
	head=1; tail=1; que[1]=t; dep[t]=0;
	int u;
	while (head<=tail){
		u=que[head++];
		for (int e=Head[u];e;e=Next[e])
			if (dep[vet[e]]==-INF&&val[e^1]){
				dep[vet[e]]=dep[u]+1;
				que[++tail]=vet[e];
			}
	}
	return dep[s]!=-INF;
}
bool bfs2(){
	for (int i=s;i<=t;i++) dep[i]=-INF;
	head=1; tail=1; que[1]=t; dep[t]=0;
	if (t==s) return true;
	int u;
	while (head<=tail){
		u=que[head++];
		for (int e=Head[u];e;e=Next[e])
			if (dep[vet[e]]==-INF&&val[e^1]){
				dep[vet[e]]=dep[u]+1;
				lst[vet[e]]=e^1;
				que[++tail]=vet[e];
				if (vet[e]==s) return true;
			}
	}
	return false;
}
int maxflow;
int dfs(int u,int flow){
	vis[u]=true;
	if (u==t){
		maxflow+=flow;
		return flow;
	}
	int used=0,v;
	for (int e=Head[u];e;e=Next[e]){
		v=vet[e];
		if ((!vis[v]||v==t)&&val[e]&&dep[v]+1==dep[u]){
			int tmp=dfs(v,min(val[e],flow-used));
			val[e]-=tmp; val[e^1]+=tmp; used+=tmp;
			if (used==flow) break;
		}
	}
	return used;
}
void dinic(){
	while (bfs()){
		vis[t]=1;
		while (vis[t]){
			for (int i=s;i<=t;i++) vis[i]=false;
			dfs(s,INF);
		}
	}
}
int top; pii st[1100000];
void augment(){
	int flow;
	while (bfs2()){
		flow=INF;
		for (int u=s;u!=t;u=vet[lst[u]]) flow=min(flow,val[lst[u]]);
		for (int u=s;u!=t;u=vet[lst[u]]) val[lst[u]]-=flow,val[lst[u]^1]+=flow,st[++top]=pii(lst[u],flow);
		maxflow+=flow;
	}
}
void re_augment(int now){
	while (top>now){
		val[st[top].first]+=st[top].second;
		val[st[top].first^1]-=st[top].second;
		top--;
	}
}
void findall(int i,int sta){
	if (i==k+1){
		num[sta]=maxflow;
		return;
	}
	findall(i+1,sta|(1<<(i-1)));
	int tmp=maxflow,lu=Head[u[i]],lv=Head[v[i]],now=top;
	
	Add(u[i],v[i],25);
	
	augment(); findall(i+1,sta); re_augment(now);
	
	edgenum-=2;
	Head[u[i]]=lu; Head[v[i]]=lv;
	maxflow=tmp;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1;i<=k;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]);
	s=1; t=n; edgenum=1;
	int u,v,c;
	for (int i=k+1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c);
		Add(u,v,c);
	}
	dinic(); findall(1,0);
	for (int i=0;i<k;i++) lg[1<<i]=i;
	int upperlim=(1<<k),ans;
	while (q--){
		for (int i=1;i<=k;i++) scanf("%d",&w[i]);
		sum[0]=0; ans=INF;
		for (int i=1;i<upperlim;i++) sum[i]=sum[i^(i&-i)]+w[lg[i&-i]+1];
		for (int i=0;i<upperlim;i++) ans=min(ans,sum[i]+num[i]);
		printf("%d\n",ans);
	}
	return 0;
}