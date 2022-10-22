#include<bits/stdc++.h>
#define bp(x) __builtin_popcountll(x)
#define ll long long
using namespace std;
ll one;
int n,k;
ll b[11],g[11][49];
void dfs(int d,ll s,ll t){
	if(d>k){
		int c=bp(s);
		if(bp(s>>(n-c))!=c||t!=one){
			puts("REJECTED");
			exit(0);
		}
		return;
	}
	int l=bp(s&b[d]),r=l+bp((t|b[d])^t);
	for(int i=l;i<=r;++i){
		dfs(d+1,(s&(b[d]^one))|g[d][i],t|b[d]);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	if(n==1){
		puts("ACCEPTED");
		return 0;
	}
	one=(1ll<<n)-1;
	for(int i=1,m;i<=k;++i){
		scanf("%d",&m);
		for(int j=1,x;j<=m;++j){
			scanf("%d",&x),b[i]|=1ll<<x-1;
		}
		g[i][m]=b[i];
		for(int j=m-1;j>=1;--j){
			g[i][j]=g[i][j+1]^(g[i][j+1]&-g[i][j+1]);
		}
	}
	dfs(1,0,0);
	puts("ACCEPTED");
	return 0;
}