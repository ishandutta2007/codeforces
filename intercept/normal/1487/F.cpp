#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,A=100,B=165,dp[59][209][330];
char s[59];
int dfs(int st,int ud,int nu){
	if(ud>A||ud<-A)return INF;
	if(st==n)return ud==0?0:INF;
	if(dp[st][ud+A][nu+B]!=-1)return dp[st][ud+A][nu+B];
	int ans=INF;
	for(int i=-6;i<=6;++i)
		ans=min(ans,dfs(st+1,ud*10+nu+i-s[st+1]+'0',nu+i)+abs(i)*(n-st));
	return dp[st][ud+A][nu+B]=ans;
}
int main(){
	scanf("%s",s+2);s[1]='0';
	n=strlen(s+1);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(0,0,0));
	return 0;
}