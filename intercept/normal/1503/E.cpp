#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=4050;
int n,ans;
int c[M][M],w[M][M],s[M][M];
void solve(int n,int m,int x){
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j){
			w[i][j]=1ll*c[i+j-1][j]*c[n-i+j-1][j-1]%mod;
			s[i][j]=(s[i-1][j]+w[i][j])%mod;
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			ans=(ans+1ll*w[i][j]*s[n-i-x][m-j]%mod)%mod;
		}
	}
}
int main(){
	for(int i=0;i<M;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	int n,m;
	scanf("%d%d",&n,&m);
	solve(n,m,1);
	solve(m,n,0);
	ans=(ans<<1)%mod;
	printf("%d\n",ans);
	return 0; 
}