#include <iostream>
#include <cstdio>

long long n,m,k,area,on,om;
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	std::cin>>n>>m>>k;
	on=n,om=m;
	if((n*m*2)%k){
		puts("NO");
		return 0;
	}
	if(k%2==0)k>>=1;
	else n<<=1;
	long long tem=gcd(n,k);
	n/=tem;
	k/=tem;
	m/=k;
	if(on<n)n>>=1,m<<=1;
	if(om<m){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("0 0\n0 %I64d\n%I64d 0",m,n);
}