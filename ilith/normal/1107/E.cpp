#include<bits/stdc++.h>
#define rgi register int
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
using namespace std;
const int N=110;
int n,su[N];
char s[N];
long long dp[N][N][N],v[N];
signed main(){
	scanf("%d%s",&n,s+1);
	FOR(i,1,n){
		scanf("%lld",v+i);
		FOR(j,1,i-1)v[i]=max(v[i],v[j]+v[i-j]);
	}
	FOR(i,1,n){
		FOR(j,i+1,n)su[i]+=(s[i]==s[j]);
		FOR(j,0,su[i])dp[i][i][j]=v[j+1];
	}
	FOR(len,2,n)FOR(i,1,n-len+1){
		rgi j=i+len-1,x=j;
		while(s[x-1]==s[j]&&x>i)--x;
		FOR(k,0,su[j]){
			dp[i][j][k]=dp[i][x-1][0]+v[k+j-x+1];
			FOR(l,i,x-1)if(s[l]==s[j]){
				dp[i][j][k]=max(dp[i][j][k],dp[i][l][k+j-x+1]+dp[l+1][x-1][0]);
			}
		}
	}
	printf("%lld",dp[1][n][0]);
	return 0;
}