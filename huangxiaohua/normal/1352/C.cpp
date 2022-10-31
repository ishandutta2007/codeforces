#include<stdio.h>
int i,j,n,a,b;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",(b/(a-1)-(b%(a-1)==0))*a+b%(a-1)+(a-1)*(b%(a-1)==0));
	}
	
	return 0;
}