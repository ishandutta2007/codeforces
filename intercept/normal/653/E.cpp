#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=3e5+9;
int n,m,k;
vector<int>g[M];
bool vis[M],in[M];
int f[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	if(find(x)==find(y))return;
	f[find(y)]=find(x);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	if(n-1-g[1].size()<k){
		cout<<"impossible\n";
		return 0;
	}
	int p=2;
	for(int i=2;i<=n;++i){
		if(g[i].size()<g[p].size())p=i;
	}
	memset(vis,0,sizeof(vis));
	for(auto v:g[p]){
		vis[v]=1;
	}
	in[p]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i])merge(p,i),in[i]=1;
	}
	for(int i=2;i<=n;++i){
		if(!in[i]){
			memset(vis,0,sizeof(vis));
			for(auto v:g[i]){
				vis[v]=1;
			}
			for(int j=2;j<=n;++j){
				if(!vis[j])merge(i,j);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	for(auto v:g[1]){
		vis[v]=1;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(find(i)!=find(1))k--;
			merge(1,i);
		}
	}
	for(int i=1;i<=n;++i){
		if(find(1)!=find(i)){
			cout<<"impossible\n";
			return 0;
		}
	}
	if(k>=0)cout<<"possible\n";
	else cout<<"impossible\n";
	return 0;
}
/*
1
5 7

2 3

4 5

2 4

1 4

1 2

3 5

3 4


*/