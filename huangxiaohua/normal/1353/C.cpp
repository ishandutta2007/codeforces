#include<stdio.h>
#define LL long long int
LL t,i,a;
int main(){
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		scanf("%lld",&a);a/=2;
		printf("%lld\n",a*(a+1)*(2*a+1)/3*4);
	}

}