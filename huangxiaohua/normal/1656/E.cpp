#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[100500],p[100500];
vector<int> v[100500];

void dfs(int x,int fa,int sb){
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x,-sb);
		f[x]+=-sb;
	}
	if(x!=1){
		f[x]=sb-f[x];
	}
	else{
		f[x]=-f[x];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			f[i]=p[i]=0;
			v[i].clear();
		}
		for(i=1;i<n;i++){
			cin>>j>>k;
			v[j].push_back(k);
			v[k].push_back(j);
		}
		dfs(1,0,1);
		for(i=1;i<=n;i++)cout<<f[i]<<' ';
		cout<<'\n';
	}
}