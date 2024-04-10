#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
using namespace std;
const int N=3010,mod=1e9+7;
int n,m,dp[N][N];
char s[N][N];
int chg(int x){return x<0?x+mod:x>=mod?x-mod:x;}
long long get(int xl,int yl,int xr,int yr){
	if(s[xl][yl]=='#'||s[xr][yr]=='#')return 0;
	memset(dp,0,sizeof dp),dp[xl][yl]=1;
	FOR(i,xl,xr)FOR(j,yl,yr)if(s[i][j]!='#'){
		dp[i][j]+=chg(dp[i-1][j]+dp[i][j-1]);
	}
	return dp[xr][yr];
}
signed main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%s",s[i]+1);
	printf("%d",chg((get(1,2,n-1,m)*get(2,1,n,m-1)-get(1,2,n,m-1)*get(2,1,n-1,m))%mod));
	return 0;
}