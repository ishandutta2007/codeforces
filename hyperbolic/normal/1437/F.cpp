#include <stdio.h>
#include <algorithm>
#define MOD 998244353

int a;
int x[5010],next[5010];
long long int check[5010];
long long int func(int k)
{
	if(k==0) return 1;
	if(check[k]!=-1) return check[k];
	long long int S = 1;
	for(int i=k-1;i>next[k];i--)
	{
		S *= (a-i-1);
		//S *= (a-prev) + (k-i) + (next[prev]-k);
		S %= MOD;
	}
	long long int ans = 0;
	for(int i=next[k];i>=0;i--)
	{
		ans += (func(i)*S);
		ans %= MOD;
		S *= (a-i);
		S %= MOD;
	}
	return check[k] = ans;
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=0;i<=a;i++) check[i] = -1;
	std::sort(x+1,x+a+1);
	next[1] = 0;
	int p = 0;
	for(int i=2;i<=a;i++)
	{
		while(2*x[p+1]<=x[i]) p++;
		next[i] = p;
	}
	next[a+1] = a;
	printf("%lld",func(a));
}