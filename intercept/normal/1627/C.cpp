#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n;
vector<pii>g[M];
int ans[M];
void dfs(int u,int fa,int t){
	for(auto o:g[u]){
		int v=o.fi,w=o.se;
		if(v!=fa){
			ans[w]=t;
			dfs(v,u,t^=1);
		}
	}
}
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v,i);
		g[v].eb(u,i);
	}
	for(int i=1;i<=n;++i){
		if(g[i].size()>2){
			puts("-1");
			return;
		}
	}
	dfs(1,0,0);
	for(int i=1;i<n;++i){
		cout<<(ans[i]?2:3)<<" ";
	}
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/