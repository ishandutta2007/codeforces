#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[1005000],g[1005000],son[1005000];
vector<int> v[1005000];

void dfs(int x){
	for(auto i:v[x]){
		dfs(i);
		g[x]+=g[i];
		f[x]=max(f[x],f[i]);
	}
	f[x]++;
	g[x]=max(g[x],f[x]);
	//printf("NMSL%d %d %d\n",x,f[x],g[x]);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=2;i<=n;i++){
		cin>>j;
		v[j].push_back(i);
		son[j]++;
	}
	dfs(1);
	cout<<g[1];
}