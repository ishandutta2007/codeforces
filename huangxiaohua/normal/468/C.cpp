#include <stdio.h> 
long long p,l=1,r=1e18,sb;

int main(){
	scanf("%lld",&p);
	sb=((r/10)%p*2%p*9%p*5%p*9%p+1)%p;
	printf("%lld %lld",l+p-sb,r+p-sb);
}