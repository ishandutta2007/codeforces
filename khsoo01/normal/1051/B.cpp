#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b;
	scanf("%lld%lld",&a,&b);
	puts("YES");
	for(long long i=a;i<=b;i+=2) {
		printf("%lld %lld\n",i,i+1);
	}
}