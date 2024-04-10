#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,ans;
int a[M];
vector<int>g[M];
set<int>s[M];
void dfs(int u,int fa,int w){
	s[u].insert(w);
	bool flag=0;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u,w^a[v]);
			if(s[u].size()<s[v].size())swap(s[u],s[v]);
			for(auto o:s[v]){
				if(s[u].count(o^a[u])){
					flag=1;
				}
			}
			for(auto o:s[v])s[u].insert(o);
		}
	}
	if(flag)s[u].clear();
	ans+=flag;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0,a[1]);
	cout<<ans<<endl;
	return 0;
}
/*
1
??????
*/