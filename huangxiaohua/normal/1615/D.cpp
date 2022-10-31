#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,w,f[200500],no;
vector<int>v[200500];
vector<pair<int,int> >v2[200500];
map<int,map<int,int> > mp;

void dfs(int x){
	for(auto [i,j]:v2[x]){
		if(-1==f[i]){
			f[i]=(f[x]^j);
		}
		else{
			if(f[i]!=(f[x]^j)){
				no=1;return;
			}
			continue;
		}
		dfs(i);
	}
}

void dfs2(int x,int fa){
	if(fa){
		if(mp[x][fa]!=-1){
			cout<<x<<' '<<fa<<' '<<mp[x][fa]<<'\n';
		}
		else{
			cout<<x<<' '<<fa<<' '<<(f[x]^f[fa])<<'\n';
		}
		
	}
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs2(i,x);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	
	while(t--){mp.clear();
		cin>>n>>m;
		for(i=1;i<=max(n,m);i++){
			v[i].clear();
			v2[i].clear();
			f[i]=-1;
		}
		for(i=1;i<n;i++){
			cin>>j>>k>>w;
			v[j].push_back(k);
			v[k].push_back(j);
			mp[j][k]=mp[k][j]=w;
			if(w==-1){
				
			}
			else{
				v2[j].push_back({k,__builtin_popcount(w)&1});
				v2[k].push_back({j,__builtin_popcount(w)&1});
				
			}
		}
		for(i=1;i<=m;i++){
			cin>>j>>k>>w;
			v2[j].push_back({k,w});
			v2[k].push_back({j,w});
		}
		no=0;
		for(i=1;i<=n;i++){
			if(f[i]==-1){
				f[i]=0;
				dfs(i);
			}
		}
		if(no){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			dfs2(1,0);
		}
	}
}