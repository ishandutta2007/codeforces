#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,k,sum;
int id[M],b[M],sz;
int f[M][23],dep[M];
vector<int>g[M];
map<int,int>mp;
void dfs(int u,int fa){
	id[u]=++sz;
	b[sz]=u;
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<20;++i)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v!=fa)dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;--i){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;--i){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int L(){
	return b[mp.begin()->fi];
}
int R(){
	return b[mp.rbegin()->fi];
}
int val(){
	int u=L(),v=R();
	return dep[u]-dep[lca(u,v)]+1;
}
void add(int x){
	mp[id[x]]=0;
	auto it=mp.lower_bound(id[x]);
	auto ne=next(it);
	if(ne!=mp.end()){
		sum-=ne->se;
		ne->se=dep[b[ne->fi]]-dep[lca(x,b[ne->fi])];
		sum+=ne->se;
	}
	if(it!=mp.begin()){
		auto pr=prev(it);
		mp[id[x]]=dep[x]-dep[lca(b[pr->fi],x)];
		sum+=mp[id[x]];
	}
}
void del(int x){
	auto it=mp.lower_bound(id[x]);
	if(it==mp.begin()){
		auto ne=next(it);
		sum-=ne->se;
		ne->se=0;
	}
	else{
		sum-=it->se;
		auto ne=next(it);
		auto pr=prev(it);
		if(ne!=mp.end()){
			sum-=ne->se;
			ne->se=dep[b[ne->fi]]-dep[lca(b[ne->fi],b[pr->fi])];
			sum+=ne->se;
		}
	}
	mp.erase(it);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	int ans=0;
	for(int r=1,l=1;r<=n;++r){
		add(r);
		while(sum+val()>k){
			del(l);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
23323
1
4
*/