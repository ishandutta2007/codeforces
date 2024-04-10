#include <cstdio>
#include <iostream>

long long x,bin=1,tem;
int S(long long x){
	int tot=0;
	while(x){
		tot+=x%10;
		x/=10;
	}
	return tot;
}
int main(){
	std::cin>>x;
	tem=x;
	while(x){
		x/=10;
		bin*=10;
	}
	bin/=10;
	x=tem-(tem%bin)-1;
	printf("%d\n",S(x)+S(tem-x));
}