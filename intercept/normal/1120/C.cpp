#include<bits/stdc++.h>
using namespace std;
const int M=5009;
int n,a,b;
int dp[M],sa[M][M];
char s[M];
int main(){
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1]+a;
		for(int j=1;j<i;++j){
			sa[i][j]=s[i]==s[j]?sa[i-1][j-1]+1:0;
			int len=min(sa[i][j],i-j);
			dp[i]=min(dp[i],dp[i-len]+b);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}