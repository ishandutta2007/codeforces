#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,s,t,S,T,r,b,cnt,a[310000],vis[310000],dep[310000],mn[310000],tot[310000],num[310000],maxflow; bool flag,isy[310000];
int edgenum=1,F[810000],V[810000],Next[810000],Head[310000],cur[310000]; map<int,int> mapx,mapy;
void addedge(int u,int v,int f){
	V[++edgenum]=v; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f){
//	cerr<<"edge: "<<u<<' '<<v<<' '<<f<<endl;
	addedge(u,v,f);
	addedge(v,u,0);
}
void Add2(int u,int v,int L,int R){
	num[v]+=L; num[u]-=L;
	Add(u,v,R-L);
}
queue<int> que;
bool bfs(int s,int t){
	for (int i=0;i<=cnt+3;i++) vis[i]=false,dep[i]=INF;
	dep[s]=0; vis[s]=true;
	que.push(s);
	while (!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			int v=V[e];
			if (dep[v]>dep[u]+1&&F[e]){
				dep[v]=dep[u]+1;
				if (!vis[v]){
					que.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return dep[t]!=INF;
}
int dfs(int u,int flow,int s,int t){
	if (u==t){ 
		maxflow+=flow;
		return flow;
	}
	int used=0;
	for (int &e=cur[u];e;e=Next[e]){
		int v=V[e];
		if (F[e]&&dep[v]==dep[u]+1){
			int minflow=dfs(v,min(flow-used,F[e]),s,t);
			F[e]-=minflow; F[e^1]+=minflow; used+=minflow;
			if (used==flow) break;
		}
	}
	return used;
}
int dinic(int s,int t){
	maxflow=0;
	while (bfs(s,t)){
		for (int i=0;i<=cnt+3;i++) cur[i]=Head[i];
		while (dfs(s,INF,s,t));
	}
	return maxflow;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&b);
	if (r>b) swap(r,b),flag=true;
	int x,y;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if (!mapx[x]){ mapx[x]=++cnt; mn[cnt]=INF;}
		if (!mapy[y]){ mapy[y]=++cnt; mn[cnt]=INF; isy[cnt]=true;}
		x=mapx[x]; y=mapy[y];
		Add(x,y,1); tot[x]++; tot[y]++;
	}
	int op,d;
	for (int i=1;i<=m;i++){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d",&x,&d);
			x=mapx[x]; if (!x) continue;
			mn[x]=min(mn[x],d);
		} else{
			scanf("%d%d",&y,&d);
			y=mapy[y]; if (!y) continue;
			mn[y]=min(mn[y],d);			
		}
	}
	int s=cnt+1,t=cnt+2;
	int S=0,T=cnt+3;
	for (int i=1;i<=cnt;i++){
		mn[i]=min(mn[i],tot[i]);
		int L=(tot[i]-mn[i]+1)>>1,R=(tot[i]+mn[i])>>1;
		if (L>R){ puts("-1"); return 0;}
		if (isy[i]) Add2(i,t,L,R);
		else Add2(s,i,L,R);
	}
	int tmp=0;
	for (int i=1;i<=cnt+2;i++){
		if (num[i]<0) Add(i,T,-num[i]);
		if (num[i]>0) Add(S,i,num[i]),tmp+=num[i];
	}
	Add(t,s,INF);
	if (dinic(S,T)!=tmp){ puts("-1"); return 0;}
	int ans=dinic(s,t);
	printf("%lld\n",1ll*ans*r+1ll*(n-ans)*b);
	for (int i=1;i<=n;i++){
		if (F[i<<1]==flag) putchar('r');
		else putchar('b');
	}
	return 0;
}