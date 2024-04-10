#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n;
int p[M][2],dp[M];
char s[M],t[M];
void work(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='0'||t[i]=='0')p[i][0]=i;
		else p[i][0]=p[i-1][0];
		if(s[i]=='1'||t[i]=='1')p[i][1]=i;
		else p[i][1]=p[i-1][1];
		dp[i]=dp[i-1];
		if(p[i][0]){
			dp[i]=max(dp[i],dp[p[i][0]-1]+1);
		}
		if(p[i][0]&&p[i][1]){
			dp[i]=max(dp[i],dp[min(p[i][0],p[i][1])-1]+2);
		}
	}
	printf("%d\n",dp[n]);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}