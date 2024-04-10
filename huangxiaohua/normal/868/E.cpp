#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,l,n,m,t,f[66][66][66][66],w,g[66][66][66],it,tmp,sb,b[66],res=1e9,st,rt,su;

vector<pair<int,int> >v[66];

int dfs(int x,int fa,int num,int t){
	if(~f[fa][x][num][t]){
		return f[fa][x][num][t];
	}
	if(!t)return f[fa][x][num][t]=0;
	if(!num)return f[fa][x][num][t]=1e8;
	if(x!=rt&&v[x].size()==1){
		return f[fa][x][num][t]=dfs(x,0,t-num,t-num);
	}
	int it=0;
	g[x][0][0]=1e8;
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		it++;
		for(int k=0;k<=t;k++){
			g[x][it][k]=0;
			for(int l=0;l<=k;l++){
				g[x][it][k]=max(g[x][it][k],min(g[x][it-1][k-l],j+dfs(i,x,l,t)));
			}
		}
	}
	for(int i=1;i<=t;i++){
		f[fa][x][i][t]=g[x][it][i];
	}
	return f[fa][x][num][t];
}

void dfs1(int x,int fa){
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		dfs1(i,x);b[x]+=b[i];
		if(x==st){
			res=min(res,j+dfs(i,st,b[i],su));
		}
	}
}

int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&j,&k,&w);
		v[j].push_back({k,w});
		v[k].push_back({j,w});
	}
	scanf("%d%d",&st,&t);su=t;
	for(i=1;i<=t;i++){
		scanf("%d",&k);b[k]++;
	}
	for(t=1;t<=su;t++){
		for(i=1;i<=n;i++){
			rt=i;dfs(i,0,t,t);
		}
	}
	dfs1(st,0);
	printf("%d",res);
}