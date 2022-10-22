#include<bits/stdc++.h>
using namespace std;
long long T,u,v,n;
vector<long long> e[100010];
long long siz[100010],maxs[100010],node,t;
void dfs1(long long p,long long f){
	siz[p]=1,maxs[p]=0;
	for(long long i=0;i<e[p].size();i++){
		if(e[p][i]!=f){
			dfs1(e[p][i],p),siz[p]+=siz[e[p][i]],maxs[p]=max(maxs[p],siz[e[p][i]]);
		}
	}
	maxs[p]=max(maxs[p],n-siz[p]);
	if(maxs[p]==maxs[node]){
		t=p;
	}
	if(maxs[p]<maxs[node]){
		node=p;
		t=0;
	}
}

pair<long long,long long> dfs2(long long p,long long f){
	if(e[p].size()==1){
		return make_pair(p,f);
	}
	for(long long i=0;i<e[p].size();i++){
		if(e[p][i]!=f)return dfs2(e[p][i],p);
	}
}
int main(){
	cin>>T;
	while(T--) {
		cin>>n;
		for(long long i=1;i<=n;i++){
			e[i].clear();
		}
		for(long long i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		maxs[node=t=0]=1000000009;
		dfs1(1,1);
		if(!t){
			cout<<node<<' '<<e[node][0]<<'\n'<<node<<' '<<e[node][0]<<'\n';
		}
		else {
			pair<long long,long long>ans=dfs2(node,t);
			cout<<ans.first<<' '<<ans.second<<'\n'<<ans.first<<' '<<t<<'\n';
		}
	}
	return 0;
}