//https://codeforces.com/contest/1276/problem/B
#include<bits/stdc++.h>
using namespace std;
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
const int N=200005;
vector<int>E[N],e[N];
int vis[N],sz[N],dfn[N],la[N],low[N],cnt;
void dfs(int v,int f){
//	printf("%d %d\n",v,f);
	vis[v]= sz[v]=1;
	low[v]=dfn[v]=++cnt;
	int s=e[v].size(),i,u;
	for(i=0;i!=s;++i){
		if(!vis[u=e[v][i]]){
			dfs(u,v);
			sz[v]+=sz[u];
			cmin(low[v],low[u]);
			if(low[u]>=dfn[v])E[v].push_back(u);
		}else if(u!=f)cmin(low[v],dfn[u]);
	}
	la[v]=cnt;
}
int main(){
//	freopen("b.txt","r",stdin);
	int t,n,m,a,b,i,k,v,l,r;
	scanf("%d",&t);
	while(t--){
//		printf("t=%d\n",t);
		scanf("%d%d%d%d",&n,&m,&a,&b);l=r=0;
		for(i=1;i<=n;++i)e[i].clear();
		for(i=1;i<=n;++i)E[i].clear();
		while(m--){
			scanf("%d%d",&i,&k);
			e[i].push_back(k);
			e[k].push_back(i);
		}
		for(i=1;i<=n;++i)vis[i]=0;
		cnt=0;dfs(a,0);
//		for(i=1;i<=n;++i)printf("%d %d %d %d\n",dfn[i],la[i],low[i],vis[i]);
		k=E[a].size();
		for(i=0;i!=k;++i){
			v=E[a][i];
			if(dfn[b]<dfn[v]||la[v]<dfn[b])l+=sz[v];
		}
		k=E[b].size();
		for(i=0;i!=k;++i)r+=sz[E[b][i]];
//		for(i=0;i!=E[a].size();++i)printf("%d ",E[a][i]);printf("\n");
//		for(i=0;i!=E[b].size();++i)printf("%d ",E[b][i]);printf("\n");
		printf("%lld\n",((long long)l)*r);
	}
	return 0;
}