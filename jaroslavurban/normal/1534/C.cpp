#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int mod=1e9+7;
vector<int>a[2],pos[2],vis[2];

void dfs(int u){
	if(vis[0][u])return;
	vis[0][u]=true;
	dfs(pos[0][a[1][u]]);
}

void ProGamerMove(){
	int n;cin>>n;
	for(int it=0;it<2;++it){
		a[it].resize(n);
		pos[it].resize(n);
		vis[it].assign(n,0);
		for(int i=0;i<n;++i){
			cin>>a[it][i];
			--a[it][i];
			pos[it][a[it][i]]=i;
		}
	}
	ll res=1;
	for(int i=0;i<n;++i)if(!vis[0][i]){
		dfs(i);
		res=2*res%mod;
	}
	cout<<res<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}