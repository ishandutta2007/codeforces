#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
char s[N],ans[N];
int n,dp[N][2],cur[N][2];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=n;i;i--){
		if(s[i]=='0'){
			dp[i][0]=max(dp[i+1][1],dp[i+1][0])+1;
			dp[i][1]=dp[i+1][1];
		}else{
			dp[i][0]=max(dp[i+1][1],dp[i+1][0]);
			dp[i][1]=dp[i+1][1]+1;
		}
	}
	//do dp
	for(int i=n;i;i--){
		cur[i][1]=cur[i+1][1];
		cur[i][0]=max(cur[i+1][1],cur[i+1][0])+1;
		if(max(cur[i][0],cur[i][1])==max(dp[i][0],dp[i][1]))ans[i]='0';
		else{
			ans[i]='1';
			cur[i][0]=max(cur[i+1][1],cur[i+1][0]);
			cur[i][1]=cur[i+1][1]+1;
		}
	}
	printf("%s",ans+1);
}