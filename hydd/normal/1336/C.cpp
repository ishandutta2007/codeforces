#include<cstdio>
#include<cstring>
using namespace std;
const int Mod=998244353;
char s[3100],t[3100];
int n,m,ans,dp[3100][3100];
int add(int x,int y){
	return x+y>=Mod?x+y-Mod:x+y;
}
int main(){
	scanf("%s",s+1); scanf("%s",t+1);
	n=strlen(s+1); m=strlen(t+1);
	for (int i=n;i>=1;i--){
		if (i>=m) dp[i+1][0]++;
		for (int j=0;j<=n;j++){
			if (j&&(j>m||t[j]==s[i])) dp[i][j]=add(dp[i+1][j-1],dp[i][j]);
			if (i+j>m||t[i+j]==s[i]) dp[i][j]=add(dp[i][j],dp[i+1][j]);
		}
	}
	for (int i=0;i<=n;i++) ans=add(ans,dp[1][i]);
	printf("%d\n",ans);
	return 0;
}