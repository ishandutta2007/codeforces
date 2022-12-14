#include <stdio.h>

long long int x[100010];
int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	for(int i=1;i<=b;i++) scanf("%lld",&x[i]);
	
	int p = 1;
	long long int s = 0;
	int ans = 0;
	while(p<=b)
	{
		long long int limit = ((x[p] - s-1)/c + 1)*c;
		for(int j=p+1;j<=b;j++)
		{
			if(x[j]-s>limit)
			{
				ans++;
				s += (j-p);
				p = j;
				goto u;
			}
		}
		ans++;
		p = b+1;
		u:;
	}
	printf("%d",ans);
}