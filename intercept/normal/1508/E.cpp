#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+9;
ll ans;
int n,num,lim;
int a[M],b[M],c[M],d[M],p[M],f[M],t[M],dep[M];
vector<int>g[M];
bool vis[M],in[M];
void pre(int u,int fa){
	f[u]=fa;
	b[u]=a[u];
	if(u!=1)remove(g[u].begin(),g[u].end(),fa),g[u].pop_back();
	for(auto v:g[u])pre(v,u);
	sort(g[u].begin(),g[u].end(),[&](const int&l,const int&r){return b[l]<b[r];});
	if(g[u].size())b[u]=min(b[u],b[g[u][0]]);
	d[u]=g[u].size();
}
void dfs(int u,int s){
	p[a[u]]=u;
	dep[u]=s;
	c[u]=++num;
	for(auto v:g[u])dfs(v,s+1);
}
void sol(int u){
	vis[a[u]]=1;
	for(auto v:g[u])sol(v);
	if(num<=lim)++num;
	if((a[u]!=num&&num<lim)||(num==lim&&!vis[num])){
		puts("NO");
		exit(0);
	}
	vis[a[u]]=0;
}
void so(int u){
	if(!in[u]&&a[u]!=num){
		puts("NO");
		exit(0);
	}
	if(!in[u])++num;
	for(auto v:g[u])so(v);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	pre(1,0);
	dfs(1,0);
	for(int i=1;i<=n;++i){
		ans+=dep[p[i]];
		lim=i;
		in[p[i]]=1;
		if(d[p[i]])break;
		d[f[p[i]]]--;
	}
	num=0;
	sol(1);
	so(1);
	puts("YES");
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		printf("%d ",c[i]);
	}
	return 0;
}