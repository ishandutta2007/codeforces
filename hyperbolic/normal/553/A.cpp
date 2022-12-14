#include <stdio.h>
#define MOD 1000000007

long long int check[1010][1010];

long long int comb(int a, int b)
{
	if(b==0) return 1;
	if(a==b) return 1;
	if(check[a][b]) return check[a][b];
	
	return check[a][b] = (comb(a-1,b-1)+comb(a-1,b)) % MOD;
}

int x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int s = 0;
	for(int i=1;i<=a;i++) s += x[i];
	
	long long int ans = 1;
	for(int i=a;i>=1;i--)
	{
		ans *= comb(s-1,x[i]-1);
		ans %= MOD;
		s -= x[i];
	}
	printf("%lld",ans);
}