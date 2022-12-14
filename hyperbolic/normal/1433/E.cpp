#include <stdio.h>

long long int fact[30];
long long int check[110][110];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	if(check[s][t]) return check[s][t];
	
	else return check[s][t] = comb(s-1,t-1)+comb(s-1,t);
}
int main()
{
	fact[0] = 1;
	for(int i=1;i<=20;i++) fact[i] = fact[i-1]*i;
	int a;
	scanf("%d",&a);
	a/=2;
	printf("%lld\n",comb(2*a-1,a-1)*fact[a-1]*fact[a-1]);
}