#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int dp[maxn][maxn],i,j,k,mp[maxn][maxn],r[maxn],mp2[maxn][maxn],ans;
int n,m,k1,k2;
char c;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read(); k=read();
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			scanf("%c",&c);
			if (c=='1'){
				r[i]++; mp[i][r[i]]=j;
			}
		}
		scanf("%c",&c);
	}
	for (i=1;i<=n;i++){
		for (j=0;j<=r[i];j++){
			mp2[i][j]=1e9;
			if (j==r[i]){
				mp2[i][j]=0; break;
			}
			for (k1=0;k1<=j;k1++){
				mp2[i][j]=min(mp2[i][j],mp[i][r[i]-(j-k1)]-mp[i][k1+1]+1);
			}
		}
	}
	for (i=0;i<=n;i++){
		for (j=0;j<=k;j++){
			dp[i][j]=1e9;
		}
	}
	dp[0][0]=0;
	for (i=0;i<=n-1;i++){
		for (j=0;j<=k;j++){
			for (k1=0;k1<=r[i+1];k1++){
				dp[i+1][j+k1]=min(dp[i+1][j+k1],dp[i][j]+mp2[i+1][k1]);
			}
		}
	}
	ans=1e9;
	for (i=0;i<=k;i++){
		ans=min(ans,dp[n][i]);
	}
	printf("%d\n",ans);
	return 0;
}