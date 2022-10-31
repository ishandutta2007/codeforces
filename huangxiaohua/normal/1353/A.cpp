#include<stdio.h>
#define LL long long int
LL a,b,n,i;
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
	scanf("%lld%lld",&a,&b);
	if(a==1){
		printf("0\n");continue;
	}
	if(a==2){
		printf("%lld\n",b);continue;
	}
	printf("%lld\n",2*b);		
	}

}