#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,id[300500],in[300500],res[300500],it2;
vector<int> v[300500],v2[300500];
bool vis[300500];
map<pair<int,int>,int >mp;

void dfs(int x,int fa){
	res[x]=++it2;
	if(v2[x].size()>2){
		cout<<"NO";exit(0);
	}
	for(auto i:v2[x]){
		if(i==fa)continue;
		if(vis[i]){
			cout<<"NO";exit(0);
		}
		dfs(i,x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	for(i=1;i<=n;i++){
		if(id[i])continue;
		id[i]=++it;
		if(v[i].size()>=2000)continue;
		for(auto j:v[i]){
			vis[j]=1;
		}
		vis[i]=1;
		for(auto j:v[i]){
			if(v[j].size()!=v[i].size())continue;
			for(auto k:v[j]){
				if(!vis[k])goto aaa;
			}
			id[j]=it;
			aaa:;
		}
		vis[i]=0;
		for(auto j:v[i]){
			vis[j]=0;
		}
	}
	if(it==1){
		cout<<"YES\n";
		for(i=1;i<=n;i++){
			cout<<1<<' ';
		}return 0;
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		if(vis[id[i]])continue;
		vis[id[i]]=1;
		for(auto j:v[i]){
			if(!vis[id[j]]&&!mp.count({id[i],id[j]})&&!mp.count({id[j],id[i]})){
				mp[{id[i],id[j]}]=mp[{id[j],id[i]}]=1;
				v2[id[i]].push_back(id[j]);
				v2[id[j]].push_back(id[i]);
				continue;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(i=1;i<=it;i++){
		if(v2[i].size()==1){
			dfs(i,0);break;
		}
	}
	
	for(i=1;i<=it;i++){
		if(!res[i]){
			cout<<"NO";return 0;
		}
	}
	cout<<"YES\n";
	for(i=1;i<=n;i++){
		cout<<res[id[i]]<<' ';
	}
}