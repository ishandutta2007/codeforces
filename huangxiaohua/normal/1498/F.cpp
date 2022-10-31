#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,f[100500][2][22],res[100500],x,y,tmp[2][22];
vector<int> v[100500];

void dfs(int x,int fa){
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x);
		for(j=1;j<m;j++){
			f[x][0][j]^=f[i][0][j-1];
			f[x][1][j]^=f[i][1][j-1];
		}
		f[x][1][0]^=f[i][0][m-1];
		f[x][0][0]^=f[i][1][m-1];
	}
}

void dfs2(int x,int fa){
	int i,j,k;
	if(!fa){goto aaa;}
	for(i=0;i<m;i++){
		tmp[0][i]=f[fa][0][i];
		tmp[1][i]=f[fa][1][i];
	}
	for(i=1;i<m;i++){
		tmp[0][i]^=f[x][0][i-1];
		tmp[1][i]^=f[x][1][i-1];
	}
	tmp[0][0]^=f[x][1][m-1];
	tmp[1][0]^=f[x][0][m-1];
	
	for(i=1;i<m;i++){
		f[x][0][i]^=tmp[0][i-1];
		f[x][1][i]^=tmp[1][i-1];
	}
	f[x][1][0]^=tmp[0][m-1];
	f[x][0][0]^=tmp[1][m-1];
	aaa:;
	for(i=0;i<m;i++){
		res[x]^=f[x][1][i];
	}
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs2(i,x);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&f[i][0][0]);
	}
	dfs(1,0);
	dfs2(1,0);
	for(i=1;i<=n;i++){
		printf("%d ",res[i]?1:0);
	}
}