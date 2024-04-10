#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e5+9;
int n,m;
vector<pii>g[M];
bool vis[M<<2];
vector<int>ans;
void dfs(int u){
	while(g[u].size()){
		if(vis[g[u].back().se]){
			g[u].pop_back();
			continue;
		}
		auto o=g[u].back();
		g[u].pop_back();
		vis[o.se]=1;
		dfs(o.fi);
	}
	ans.eb(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int sum=m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v,i);
		g[v].eb(u,i);
	}
	for(int i=1,la=0;i<=n;++i){
		if(g[i].size()%2==1){
			if(la==0)la=i;
			else{
				sum++;
				g[i].eb(la,sum);
				g[la].eb(i,sum);
				la=0;
			}
		}
	}
	if(sum&1){
		sum++;
		g[1].eb(1,sum);
		g[1].eb(1,sum);
	}
	dfs(1);
	cout<<sum<<"\n";
	for(int i=1;i<ans.size();++i){
		if(i&1)cout<<ans[i]<<" "<<ans[i-1]<<"\n";
		else cout<<ans[i-1]<<" "<<ans[i]<<"\n";
	}
	return 0;
}
/*
23323
1
4
*/