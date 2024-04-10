#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n,i,k;
	bool b=true;
	scanf("%d",&n);
	k=1;
	i=0;
	while(k<=n){
		k*=2;
		i++;
	}
	while(k!=1 && n>0){
		k/=2;
		if(n>=k){
			if(!b) printf(" ");
			printf("%d",i);
			b=false;
			n-=k;
		}
		--i;
	}
	return 0;
}