#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m,t;
vector<pii>g[M];
int vis[M],ans[M],dep[M],in[M];
void dfs(int u,int fa){
	vis[u]=1;
	vector<pii>p;
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(!vis[v]){
			ans[w]=1;
			dep[v]=dep[u]+1;
			dfs(v,w);
		}
		else {
			if(w!=fa&&dep[v]<dep[u]){
				p.eb(v,w);
			}
		}
	}
	sort(p.begin(),p.end(),[&](const pii&l,const pii&r){return dep[l.fi]>dep[r.fi];});
	if(p.size()){
		int w=p[0].se;
		ans[w]=1;
		ans[fa]=0;
	}
}
void work(){
	t=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)g[i].clear(),vis[i]=0,in[i]=0;
	for(int i=1;i<=m;++i)ans[i]=0;
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].eb(v,i);
		g[v].eb(u,i);
	}
	if(m<n){
		for(int i=1;i<=m;++i)printf("1");
		puts("");
		return;
	}
	dfs(1,0);
	for(int i=1;i<=m;++i){
		printf("%d",ans[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5


*/