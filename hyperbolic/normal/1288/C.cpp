#include <stdio.h>
#define MOD 1000000007

long long int check[2010][2010];
long long int comb(int a, int b)
{
	if(b==0) return 1;
	if(a==b) return 1;
	if(check[a][b]) return check[a][b];
	return check[a][b] = ((comb(a-1,b-1)+comb(a-1,b))%MOD);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b); // aH2b = a+2b-1C2b
	printf("%lld\n",comb(a+2*b-1,2*b));
}