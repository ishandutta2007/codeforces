#include<stdio.h>
#include<math.h>
#define LL long long int

int main(){
	LL n,a,j,i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a);
		j=pow(2,a/2+1)-2;
		printf("%lld\n",j);
	}
}