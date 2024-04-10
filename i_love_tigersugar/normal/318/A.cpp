#include<cstdio>
typedef long long ll;
ll n,k;
int main(void) {
	scanf("%I64d",&n);
	scanf("%I64d",&k);
	if (k<=n-n/2) printf("%I64d",2*k-1);
	else printf("%I64d",2*(k-n+n/2));
	return 0;
}