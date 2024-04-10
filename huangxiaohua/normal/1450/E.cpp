#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[205][205],g[205],x,y,w;
vector<int>v[205];

void dfs(int x){
	for(auto i:v[x]){
		if(g[i]==-1){g[i]=(g[x]^1);dfs(i);}
		else if(g[i]!=(g[x]^1)){
			cout<<"NO";exit(0);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(g,-1,sizeof(g));
	memset(f,1,sizeof(f));
	cin>>n>>m;
	for(i=1;i<=n;i++)f[i][i]=0;
	for(i=1;i<=m;i++){
		cin>>x>>y>>w;
		v[x].push_back(y);
		v[y].push_back(x);
		if(w){
			f[x][y]=1;f[y][x]=-1;
		}
		else{
			f[x][y]=1;f[y][x]=1;
		}
	}
	g[1]=0;
	dfs(1);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	x=-1;y=0;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){
		if(f[i][j]>x){
			x=f[i][j];y=i;
		}
	}
	for(i=1;i<=n;i++){
		if(f[i][i]<0){
			cout<<"NO";return 0;
		}
	}
	cout<<"YES\n"<<x<<'\n';
	for(i=1;i<=n;i++){
		cout<<f[y][i]<<' ';
	}
}