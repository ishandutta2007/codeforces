// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
long long i,j,k;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long dp[maxn][2],a[maxn];
long long n,r1,r2,r3,d,ans,t00,t01,t10;
int main(){
	
	n=read(); r1=read(); r2=read(); r3=read(); d=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=0;i<=n;i++){
		dp[i][0]=1e18;
		dp[i][1]=1e18;
	}
	dp[1][0]=0;
	for (i=1;i<n;i++){
		t01=r2+d; t01=min(t01,a[i]*r1+r1+d);
		t00=r2+d+d+r1+d; t00=min(t00,a[i]*r1+r1+d+d+r1+d); t00=min(t00,a[i]*r1+r3+d);
		t10=min(min(r2+r1+r1,a[i]*r1+r1+r1+r1),a[i]*r1+r3+r1)+d+d+d;
		dp[i+1][1]=dp[i][0]+t01;
		dp[i+1][0]=min(dp[i][0]+t00,dp[i][1]+t10);
	}
	ans=1e18;
	ans=min(ans,min(min(a[n]*r1+r3,a[n]*r1+r1+d+d+r1),r2+d+d+r1)+dp[n][0]);
	ans=min(ans,min(min(r2+d+r1+d+r1,a[i]*r1+r1+d+r1+d+r1),a[i]*r1+r3+d+r1)+dp[n][1]);
	printf("%lld\n",ans);
	
	return 0;
}