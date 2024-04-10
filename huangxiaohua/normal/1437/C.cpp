
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,n,t,res,a[205],dp[405][405],tmp,k
;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<=n*2+1;i++){
			for(j=0;j<=n*2+1;j++){
				for(k=0;k<=n*2+1;k++){
					dp[i][j]=1145141919;
				}
			}
		}
		for(i=0;i<=n;i++){
			dp[i][0]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n*2;i++){
			for(j=1;j<=n;j++){
				for(k=i-1;k>=0;k--){
					dp[i][j]=min(dp[i][j],dp[k][j]);
					dp[i][j]=min(dp[i][j],dp[k][j-1]+abs(i-a[j]));
				}
				//printf("%d %d %d\n",i,j,dp[i][j]);
			}
		}
		res=1145141919;
		for(i=1;i<=n*2;i++){
			res=min(res,dp[i][n]);
		}
		printf("%d\n",res);
	}
}