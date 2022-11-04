#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=3030;
set<int>g[N],cg[N],dg[N];
int vis[N];
int n,m;
vector<int>ms,res;

int dfs(int u){
	while(dg[u].size()){
		int v=*dg[u].begin();
		dg[u].erase(v);
		dg[v].erase(u);
		dfs(v);
	}
	res.push_back(u);
}

bool hasE(int start,int end){
	vector<int>vis(n);
	function<void(int)>dfs2=[&](int u){
		if(vis[u])return;
		vis[u]=true;
		for(auto v:cg[u])dfs2(v);
	};
	dfs2(start);
	for(int i=0;i<n;++i)if(vis[i]&&((start==i||end==i)!=(cg[i].size()&1)))return false;
	for(int i=0;i<n;++i)if(vis[i])dg[i]=cg[i];
	res.clear();
	dfs(start);
	return (res.size()+ms.size()/2==m+1)&&res[0]==end;
}

bool solve(int u){
	// me->me
	for(int i=0;i<n;++i)cg[i]=g[i];
	ms.clear();
	for(auto v:g[u])if(g[v].size()&1){
		cg[u].erase(v);
		cg[v].erase(u);
		ms.push_back(v);
		ms.push_back(u);
	}
	if(hasE(u,u))return 1;
	// other->me
	for(int i=0;i<n;++i)if(i!=u&&cg[i].size()&1){
		if(hasE(i,u))return 1;
		break;
	}
	// neighbor->me
	for(auto v:g[u]){
		for(int i=0;i<n;++i)cg[i]=g[i];
		ms.clear();
		for(auto w:g[u])
			if((v!=w)==(cg[w].size()&1)){
				cg[u].erase(w);
				cg[w].erase(u);
				ms.push_back(w);
				ms.push_back(u);
			}
		if(hasE(v,u))return 1;
	}
	return 0;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i=0;i<n;++i)if(solve(i)){
		cout<<res.size()+1+ms.size()<<endl;
		reverse(res.begin(),res.end());
		for(auto r:res)cout<<r+1<<" ";
		cout<<-1<<" ";
		for(auto r:ms)cout<<r+1<<" ";
		cout<<endl;
		return 0;
	}
	cout<<0<<endl;
}