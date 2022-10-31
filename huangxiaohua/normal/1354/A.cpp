#include<stdio.h>
#define LL long long int
LL a,b,c,d,i,j,sum,n;
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b>=a){printf("%lld\n",b);continue;}
		if(d>=c){printf("-1\n");continue;}
		printf("%lld\n",(a-b)/(c-d)*c+((a-b)%(c-d)!=0)*c+b);
	}
}