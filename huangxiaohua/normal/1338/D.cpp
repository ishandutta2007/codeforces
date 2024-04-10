#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500],g[200500],res=1;
vector<int> v[200500];

void dfs(int x,int fa){
	int sb=v[x].size();
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		res=max(res,f[x]+g[i]+1);
		res=max(res,g[x]+max(f[i],g[i])+sb-2);
		g[x]=max({g[x],f[i],g[i]});
		f[x]=max(f[x],g[i]);
	}
	f[x]++;
	g[x]+=sb-1-(fa>0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	cout<<res;
}