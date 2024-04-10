#include<cstdio>
typedef long long ll;
ll n;
int main(void) {
	scanf("%I64d",&n);
	while (n%3==0) n=n/3;
	printf("%I64d",n/3+1);
	return 0;
}