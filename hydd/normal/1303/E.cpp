#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,nxt[410][31],dp[410][410];
bool vis[410];
char s[410],t[410];
void init(){
	for (int j=0;j<26;j++) nxt[n+1][j]=n+1;
	for (int i=n;i>=0;i--){
		for (int j=0;j<26;j++)
			nxt[i][j]=nxt[i+1][j];
		if (i<n) nxt[i][s[i+1]-'a']=i+1;
	}
}
bool work(){
	for (int i=1;i<=m;i++){
		for (int j=0;j<=m+1;j++)
			for (int k=0;k<=m+1;k++)
				dp[j][k]=n+1;
		dp[0][i]=0;
		for (int j=0;j<=i;j++)
			for (int k=i;k<=m;k++)
				if (dp[j][k]<n+1){
					if (j<i) dp[j+1][k]=min(dp[j+1][k],nxt[dp[j][k]][t[j+1]-'a']);
					if (k<m) dp[j][k+1]=min(dp[j][k+1],nxt[dp[j][k]][t[k+1]-'a']);
				}
		if (dp[i][m]<n+1) return true;
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		scanf("%s",t+1);
		m=strlen(t+1);
		init();
		if (work()) puts("YES");
		else puts("NO");
	}
	return 0;
}