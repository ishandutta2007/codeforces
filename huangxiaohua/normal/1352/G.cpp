#include<stdio.h>
int i,j,n,t;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		if(t<=3){
			printf("-1\n");continue;
		}
		if(t==4){
			printf("3 1 4 2\n");continue;
		}
		if(t%2==0){
			for(j=t;j>=6;j-=2){
				printf("%d ",j);
			}
			printf("2 4 1 3 ");
			for(j=5;j<=t-1;j+=2){
				printf("%d ",j);
			}
			printf("\n");continue;
		}
		if(t%2==1){
			for(j=t;j>=5;j-=2){
				printf("%d ",j);
			}
			printf("3 1 4 2 ");
			for(j=6;j<=t-1;j+=2){
				printf("%d ",j);
			}
			printf("\n");continue;
		}
	}	
}