#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,t,siz[5050];
ll m,res;
ll f[2][5050][5050];
vector<int> v[5050];
ll min(ll a,ll b){return (a<b)?a:b;}
void dfs(int x){
	int j,k;
	siz[x]++;
	for(auto i:v[x]){
		dfs(i);
		for(j=siz[x];j>=0;j--){
			for(k=0;k<=siz[i];k++){
				f[1][x][j+k]=min(f[1][x][j+k],f[1][x][j]+f[1][i][k]);
				f[1][x][j+k]=min(f[1][x][j+k],f[1][x][j]+f[0][i][k]);
				f[0][x][j+k]=min(f[0][x][j+k],f[0][x][j]+f[0][i][k]);
			}
		}
		siz[x]+=siz[i];
	}
}

int main() {
	memset(f,1,sizeof(f));
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++){
		f[0][i][0]=0;
		scanf("%lld%lld",&f[0][i][1],&f[1][i][1]);
		f[1][i][1]=f[0][i][1]-f[1][i][1];
		if(i>1){scanf("%d",&j);}
		v[j].push_back(i);
	}
	dfs(1);
	for(i=siz[1];i>=0;i--){
		if(min(f[0][1][i],f[1][1][i])<=m){printf("%d",i);return 0;}
	}
	
}