// user:halahen
#include<bits/stdc++.h>
using namespace std;
const long long maxn=5010;
long long dp[maxn][maxn],mp[maxn][maxn],a[maxn];
long long i,j,k,n,m,x,y;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read();
	}
	for (i=1;i<=n;i++){
		dp[1][i]=a[i];
		mp[1][i]=a[i];
	}
	for (i=2;i<=n;i++){
		for (j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
			mp[i][j]=max(mp[i-1][j],mp[i-1][j+1]);
			mp[i][j]=max(mp[i][j],dp[i][j]);
		}
	}
	m=read();
	for (i=1;i<=m;i++){
		x=read(); y=read();
		if (x>y){
			printf("0\n"); continue;
		}
		printf("%I64d\n",mp[y-x+1][x]);
	}
	return 0;
}