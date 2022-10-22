#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
int h[M],maxx,p,ma[M];
ll ans;
vector<int>g[M];
void dfs(int u,int fa){
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			ma[u]=max(ma[u],ma[v]);
		}
	}
	if(ma[u]<h[u]&&u!=p)ans+=h[u]-ma[u],ma[u]=h[u];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&h[i]);
		if(maxx<h[i])maxx=h[i],p=i;
	}
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(p,0);
	vector<int>f;
	for(auto v:g[p])f.emplace_back(ma[v]);
	if(g[p].size()==1)ans+=maxx,f.emplace_back(maxx);
	sort(f.begin(),f.end(),[&](const int l,const int r){return l>r;});
	ans+=1ll*maxx-f[0]+maxx-f[1];
	printf("%lld\n",ans);
	return 0;
}