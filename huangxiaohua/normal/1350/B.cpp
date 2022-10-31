#include<stdio.h>
int i,m,n,k,j,a[100005],dp[100005],max,tmp,max2,x;
int min(int x,int y){
	return (x>=y)?x:y;
}
int main(){
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&n);max=1;
		for(j=1;j<=n;j++){
			scanf("%d",&a[j]);
			dp[j]=1;
		}
		if(n==1){
			printf("1\n");continue;
		}
		for(j=1;j<=n;j++){
			for(k=2;k*j<=n;k++){
				if(a[j*k]>a[j]&dp[j]+1>dp[j*k]){
					dp[j*k]=dp[j]+1;
				}
			}
		}
		for(j=1;j<=n;j++){
			//printf("%d ",dp[j]);
			if(max<dp[j]){
				max=dp[j];
			}
		}
		printf("%d\n",max);
	}
}