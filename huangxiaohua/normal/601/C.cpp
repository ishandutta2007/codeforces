#include <stdio.h>
double dp[105][202500];
int i,j,k,n,m,sb;

int main(){
	scanf("%d%d",&n,&m);
	if(m==1){goto aaa;}
	for(i=2000;i<=202000;i++){
		dp[0][i]=m-1;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);sb+=k;
		for(j=2000;j<=202000;j++){
			dp[i][j]=(dp[i-1][j-1]-dp[i-1][j-m-1]-(dp[i-1][j-k]-dp[i-1][j-k-1]))/(m-1)+dp[i][j-1];
		}
	}
	aaa:printf("%.20lf",dp[n][sb+1999]+1);
}