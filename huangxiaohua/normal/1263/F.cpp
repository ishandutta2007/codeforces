#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m[3],sb[3][2050],t,dep[3][2050],fa[3][2050][22],f[2050][2050];

vector<int> v[3][2050];

void dfs(int t,int x,int NMSL){
	int i,j,k;
	fa[t][x][0]=NMSL;
	for(i=1;i<=20;i++){
		fa[t][x][i]=fa[t][fa[t][x][i-1]][i-1];
		if(!fa[t][x][i])fa[t][x][i]=1;
	}
	for(auto i:v[t][x]){
		if(i==NMSL)continue;
		dep[t][i]=dep[t][x]+1;
		dfs(t,i,x);
	}
	
}

int get(int t,int x,int y){
	int i,j,k;
	if(dep[t][x]>dep[t][y])swap(x,y);
	for(i=20;i>=0;i--){
		k=fa[t][y][i];
		if(dep[t][k]>=dep[t][x])y=k;
	}
	if(x==y)return x;
	for(i=20;i>=0;i--){
		j=fa[t][x][i];
		k=fa[t][y][i];
		if(j!=k){
			x=j;y=k;
		}
	}
	return fa[t][x][0];
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(t=1;t<=2;t++){
		cin>>m[t];
		for(i=2;i<=m[t];i++){
			cin>>k;
			v[t][k].push_back(i);
			v[t][i].push_back(k);
		}
		for(i=1;i<=n;i++){
			cin>>sb[t][i];
		}
		dfs(t,1,1);
	}
	memset(f,1,sizeof(f));
	f[0][0]=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			k=max(i,j)+1;
			f[k][j]=min(f[k][j],f[i][j]+dep[1][sb[1][k]]-dep[1][get(1,sb[1][i],sb[1][k])]);
			f[i][k]=min(f[i][k],f[i][j]+dep[2][sb[2][k]]-dep[2][get(2,sb[2][j],sb[2][k])]);
		}
	}
	int res=1e9;
	for(i=0;i<n;i++){
		res=min({res,f[n][i],f[i][n]});
	}
	cout<<m[1]+m[2]-res-2;
}