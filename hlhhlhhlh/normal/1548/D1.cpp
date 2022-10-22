#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=100010;
int n;
int a[maxn],b[maxn];
long long dp[2][2],ans;
int main(){
	
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read(); b[i]=read(); 
		a[i]=a[i]/2; b[i]=b[i]/2;
		a[i]=a[i]%2; b[i]=b[i]%2;
		dp[a[i]][b[i]]++;
	}
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
			ans=ans+(dp[i][j]*(dp[i][j]-1)/2)*(n-dp[i][j])+(dp[i][j]*(dp[i][j]-1)*(dp[i][j]-2)/6);
	printf("%lld\n",ans);
	
	return 0;
}