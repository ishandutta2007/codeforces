#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=209;
int n;
ll dp[M][M],a[M][M],s[M][M];
int id[M][M],f[M];
void dfs(int l,int r){
	int p=id[l][r];
	if(l<p){
		dfs(l,p-1);
		f[id[l][p-1]]=p;
	}
	if(r>p){
		dfs(p+1,r);
		f[id[p+1][r]]=p;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)scanf("%lld",&a[i][j]);
		ll t=0;
		for(int j=1;j<=n;++j){
			t+=a[i][j];
		}
		for(int j=1;j<=i;++j){
			s[j][i]=s[j][i-1]+t;
			dp[j][i]=1e18;
			for(int k=j;k<=i;++k)s[j][i]-=2ll*a[k][i];
		}
	}
	for(int i=1;i<=n;++i)dp[i][i]=0,id[i][i]=i;
	for(int k=2;k<=n;++k){
		for(int i=1;i<=n;++i){
			int j=i+k-1;
			for(int p=i;p<=j;++p){
				ll x=dp[i][p-1]+dp[p+1][j]+s[i][p-1]+s[p+1][j];
				if(dp[i][j]>x)dp[i][j]=x,id[i][j]=p;
			}
		}
	}
	dfs(1,n);
	for(int i=1;i<=n;++i)printf("%d%c",f[i]," \n"[i==n]);
	return 0;
}