#include<bits/stdc++.h>

using namespace std;
#define LL long long
const int N=3e5+10;
const LL INF=1e18;
int P;
int add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
LL gcd(LL x,LL y){
	if(x==0) return y;
	return gcd(y%x,x);
}
int n,m;
struct edge{
	int r,nxt;
	LL v;
}e[N];
int cnt,dfn,blo;
int DFN[N],low[N],hed[N];
int top=0;
int q[N],g[N];
LL res[N];
void tarjan(int x){
	DFN[x]=low[x]=++dfn;
	q[++top]=x;
	for(int i=hed[x];i;i=e[i].nxt)
		if(!DFN[e[i].r]){
			tarjan(e[i].r);
			low[x]=min(low[x],low[e[i].r]);
		}
		else if(!g[e[i].r]) low[x]=min(low[x],DFN[e[i].r]);
	if(DFN[x]==low[x]){
		blo=x;
		while(q[top]!=x&&top){
			g[q[top]]=blo;top--;
		}
		g[q[top]]=blo;top--;
	}
}
void insert(int u,int v,LL w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].v=w;
}
LL dis[N];
int vis[N];
void dfs(int x,LL y,int z){
	vis[x]=1;dis[x]=y;
	for(int i=hed[x];i;i=e[i].nxt){
		if(g[e[i].r]!=z) continue;
		if(vis[e[i].r]==0){
			dfs(e[i].r,y+e[i].v,z);
		}
		else{
			res[z]=gcd(res[z],abs(y+e[i].v-dis[e[i].r]));
		}
	}
	return;
}
void MAIN(){
	scanf("%d%d",&n,&m);
	int u,v;
	LL w,s,t;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&u,&v,&w);
		insert(u,v,w); 
	}
	for(int i=1;i<=n;++i){
		if(!DFN[i]) tarjan(i);
	}
	for(int i=1;i<=n;++i){
		if(g[i]==i){
			dfs(i,0,i);
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%lld%lld",&u,&s,&t);
		s=t-s;
		u=g[u];
		w=gcd(res[u],t);
		if(s%w==0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return;
}

int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;
}