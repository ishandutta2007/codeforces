#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 300030
int n,P,ansv[N],anse[N];
vector<pair<int,int> > G[N];
int cnt;
void dfs(int u,int fa,int opt){
	for(auto [v,id]:G[u]){
		if(v==fa)continue;
		++cnt;
		if(!opt)anse[id]=cnt|n,ansv[v]=cnt;
		else anse[id]=cnt,ansv[v]=cnt|n;
		dfs(v,u,opt^1);
	}
}
void Solve(){
	cin>>P;
	n=1<<P;
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);	
	}
	ansv[1]=n;
	cnt=0;
	dfs(1,0,0);
	cout<<1<<'\n';
	for(int i=1;i<=n;++i){
		cout<<ansv[i]<<' ';
	}
	cout<<'\n';
	for(int i=1;i<n;++i){
		cout<<anse[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}