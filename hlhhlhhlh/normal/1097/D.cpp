// user:halahen
#include<bits/stdc++.h>
using namespace std;
const long long maxn=53;
const long long mod=1e9+7;
long long i,j,k,opt;
long long n,m;
long long r,a[maxn],b[maxn],dp[maxn][10010],ni[(int)1e6+10],c[110];
long long ans,anss;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=2;i*i<=n;i++){
		if (n%i==0){
			r++;
			b[r]=i;
		}
		while (n%i==0){
			a[r]++;
			n=n/i;
		}
	}
	ni[1]=1; ni[0]=1;
	for (i=2;i<=1e6;i++){
		ni[i]=mod-((mod/i)*ni[mod%i])%mod;
	}
	if (n!=1){
		r++; a[r]=1; b[r]=n;
	}
	anss=1;
	for (opt=1;opt<=r;opt++){
		memset(dp,0,sizeof(dp));
		dp[a[opt]][0]=1;
		for (i=0;i<=m;i++){
			for (j=0;j<=a[opt];j++){
				for (k=0;k<=j;k++){
					dp[k][i+1]=(dp[k][i+1]+dp[j][i]*ni[j+1])%mod;
				}
			}
		}
		c[0]=1; for (i=1;i<=a[opt];i++) c[i]=(c[i-1]*b[opt])%mod;
		ans=0;
		for (i=0;i<=a[opt];i++){
			ans=(ans+(dp[i][m]*anss%mod*c[i])%mod)%mod;
		}
		anss=ans;
	}
	printf("%I64d\n",anss);
	return 0;
}