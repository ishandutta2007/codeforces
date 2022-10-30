#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,res,vis[1005000];
vector<int >v[1005000];
void dfs(int x){
	vis[x]=1;
	for(auto i:v[x]){
		if(vis[i])continue;
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	res=n;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			res--;
			dfs(i);
		}
	}
	cout<<m-res;
}