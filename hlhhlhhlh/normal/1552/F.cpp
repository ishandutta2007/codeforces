#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n;
int i,j,k;
const int maxn=1000010;
const long long mod=998244353;
long long a[maxn],b[maxn],c[maxn];
long long dp[maxn],f[maxn];
int main(){
	
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read(); b[i]=read(); c[i]=read();
	}
	
	f[0]=0;
	for (i=1;i<=n;i++){
		f[i]=(f[i-1]+(a[i]-a[i-1]))%mod;
		 
		j=(lower_bound(a+1,a+n+1,b[i])-a)-1;
		f[i]+=f[i-1]-f[j]-(b[i]-a[j]);
		f[i]+=a[i]-a[i-1];
		f[i]=(f[i]+mod*mod)%mod;
	}
	
	dp[0]=0;
	for (i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1]);
		if (c[i]==1){
			j=(lower_bound(a+1,a+n+1,b[i])-a)-1;
			dp[i]+=f[i-1]-f[j]-(b[i]-a[j]);
			dp[i]+=a[i]-a[i-1];
			dp[i]=(dp[i]+mod*mod)%mod;
		}
	}
	printf("%lld\n",(dp[n]+1)%mod);
	
	return 0;
}