#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[2000500],a[2000500],f[2000500],sb;
bool vis[2000500];
vector<pair<int,int> >v[2000500];

void dfs(int x,int fa,int y){
	vis[x]=1;
	for(auto [i,j]:v[x]){
		if(i==fa||vis[i])continue;
		res[j]=1;
		f[i]^=1;f[x]^=1;
		dfs(i,x,j);
	}
	//printf("NMSL%d %d %d %d\n",x,fa,y,f[x]);
	if(a[x]==-1)return;
	if(a[x]!=f[x]){
		if(x==1){exit(1);}
		f[x]^=1;f[fa]^=1;
		res[y]=0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=-1)sb+=a[i];
	}
	if(sb&1){
		for(i=1;i<=n;i++){
			if(a[i]==-1){
				a[i]=1;goto aaa;
			}
		}
		cout<<-1;return 0;
	}
	aaa:;
	for(i=1;i<=n;i++){
		if(a[i]==-1)a[i]=0;
	}
	for(i=1;i<=m;i++){
		cin>>j>>k;
		v[j].push_back({k,i});
		v[k].push_back({j,i});
	}
	dfs(1,0,0);
	k=0;
	for(i=1;i<=m;i++)k+=res[i];
	cout<<k<<'\n';
	for(i=1;i<=m;i++)if(res[i])cout<<i<<' ';
}