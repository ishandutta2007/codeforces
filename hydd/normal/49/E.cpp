#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,dp[55][55];
int len1,dp1[55][55];
int len2,dp2[55][55];
char s1[55],s2[55],trans[55][55];
void work(char *s,int dp[55][55],int len){
	for (int i=1;i<=len;i++) dp[i][i]=(1<<(s[i]-'a'));
	for (int l=1;l<len;l++)
		for (int i=1;i+l<=len;i++){
			int j=i+l;
			for (int k=i;k<j;k++)
				for (int t=1;t<=n;t++)
					dp[i][j]|=(((dp[i][k]>>(trans[t][3]-'a'))&(dp[k+1][j]>>(trans[t][4]-'a'))&1)<<(trans[t][0]-'a'));
		}
}
int work(){
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=len1;i++)
		for (int j=1;j<=len2;j++)
			for (int x=0;x<i;x++)
				for (int y=0;y<j;y++)
					if (dp1[x+1][i]&dp2[y+1][j]) dp[i][j]=min(dp[i][j],dp[x][y]+1);
	return dp[len1][len2]==INF?-1:dp[len1][len2];
}
int main(){
	scanf("%s",s1+1); len1=strlen(s1+1);
	scanf("%s",s2+1); len2=strlen(s2+1);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",trans[i]);
	work(s1,dp1,len1); work(s2,dp2,len2);
	printf("%d\n",work());
	return 0;
}