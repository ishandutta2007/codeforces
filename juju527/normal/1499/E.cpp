#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
const int maxn=2e5+10;
const int mod=998244353;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
const int N=1e3+5;
int n,m,dp[N][N][2],ans;
char s[2][N];
inline void add(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
int main(){
	scanf("%s%s",s[0]+1,s[1]+1);
	n=strlen(s[0]+1),m=strlen(s[1]+1);
	for(int i=1,lasi=1;i<=n;i++){
		if(s[0][i]==s[0][i-1])lasi=i;
		for(int j=1,lasj=1;j<=m;j++){
			if(s[1][j]==s[1][j-1])lasj=j;
			if(s[0][i]!=s[0][i-1])add(dp[i][j][0],dp[i-1][j][0]);
			if(s[0][i]!=s[1][j])add(dp[i][j][0],dp[i-1][j][1]);
			if(s[1][j]!=s[0][i])add(dp[i][j][1],dp[i][j-1][0]);
			if(s[1][j]!=s[1][j-1])add(dp[i][j][1],dp[i][j-1][1]);
			if(s[0][i]!=s[1][j])add(dp[i][j][0],j-lasj+1),add(dp[i][j][1],i-lasi+1);
			//printf("i=%d j=%d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
			add(ans,dp[i][j][0]);add(ans,dp[i][j][1]);
		}
	}printf("%d\n",ans);
    return 0;
}