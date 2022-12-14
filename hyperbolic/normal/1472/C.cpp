#include <stdio.h>

int x[200010];
int a;
long long int check[200010];
long long int func(int k)
{
	if(k>a) return 0;
	if(check[k]!=-1) return check[k];
	return check[k] = func(k+x[k])+x[k];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = -1;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		long long int max = 0;
		for(int i=1;i<=a;i++)
		{
			long long int t = func(i);
			max = max>t?max:t;
		}
		printf("%lld\n",max);
	}
}