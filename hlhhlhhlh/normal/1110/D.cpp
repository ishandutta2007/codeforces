// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,kk;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int dp[maxn][3][3],n,m,a[maxn],ha[maxn];
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		a[i]=read(); ha[a[i]]++;
	}
	for (i=0;i<=m;i++){
		for (j=0;j<3;j++){
			for (k=0;k<3;k++){
				dp[i][j][k]=-1e9;
			}
		}
	}
	dp[0][0][0]=0;
	for (i=0;i<m;i++){
		for (j=0;j<3;j++){
			for (k=0;k<3;k++){
				for (kk=0;kk<3;kk++){
					if (j+k+kk<=ha[i+1]) dp[i+1][k][kk]=max(dp[i+1][k][kk],dp[i][j][k]+kk+(ha[i+1]-j-k-kk)/3);
				}
			}
		}
	}
	printf("%d\n",dp[m][0][0]);
	return 0;
}