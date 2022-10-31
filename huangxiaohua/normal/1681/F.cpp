#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,cl[500500],w;
ll res,sz[500500],sz2[500500],f[500500],g[500500];
vector<pair<int,int> >v[500500];
vector<int> s[500500];

void dfs(int x,int fa){
	sz[x]=1;
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		if(!s[cl[j]].empty()){
			f[j]=s[cl[j]].back();
		}
		s[cl[j]].push_back(j);
		dfs(i,x);
		//printf("NMSL%d %d\n",j,sz[i]);
		sz2[j]+=sz[i];
		if(f[j])sz2[f[j]]-=sz[i];
		else g[cl[j]]-=sz[i];
		s[cl[j]].pop_back();
		sz[x]+=sz[i];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k>>w;
		cl[i]=w;
		v[j].push_back({k,i});
		v[k].push_back({j,i});
	}
	for(i=1;i<=n;i++)g[i]+=n;
	dfs(1,0);
	for(i=1;i<n;i++){
		//printf("a%d %d %d %d\n",i,f[i],sz2[i],sz2[f[i]]);
		if(f[i])res+=sz2[i]*sz2[f[i]];
		else res+=sz2[i]*g[cl[i]];
	}
	cout<<res;
}