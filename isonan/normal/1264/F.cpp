#include <cstdio>

unsigned long long n,a,d;
int main(){
	scanf("%llu%llu%llu",&n,&a,&d);
	printf("%llu %llu\n",(368131125ull*a%1000000000ull)*12000000000ull+1ull,(368131125ull*d%1000000000ull)*12000000000ull);
}