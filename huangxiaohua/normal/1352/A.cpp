#include<stdio.h>
int n,i,j,num,num1,k;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		k=0;
		scanf("%d",&num);
		num1=num;
		while(num1!=0){
			if(num1%10!=0){
				k++;
			}
			num1/=10;
		}
		printf("%d\n",k);k=0;
		while(num!=0){
			if(num%10!=0){
				printf("%d",num%10);
				for(j=1;j<=k;j++){
					printf("0");
				}
				printf(" ");
			}
			num/=10;
			k++;
		}
		printf("\n");
	}
	
	return 0;
}