#include <stdio.h>
#include <algorithm>
#define MOD 998244353

struct str{
	int x0;
	int y0;
}z[200010];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}

int x[200010],y[200010],left[200010],right[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	y[b+1] = 1234567890;
	
	for(int i=1;i<=a;i++) z[i] = {x[i],i};
	std::sort(z+1,z+a+1,cmp);
	if(z[1].x0!=y[1])
	{
		printf("0");
		return 0;
	}
	
	int p = 0;
	for(int i=1;i<=a;i++)
	{
		if(z[i].x0>y[p+1])
		{
			printf("0");
			return 0;
		}
		else if(z[i].x0==y[p+1]) p++;
		if(z[i].x0==y[p]) left[p] = left[p] > z[i].y0?left[p] : z[i].y0;
		right[p] = right[p] > z[i].y0?right[p] : z[i].y0;
	}
	
	
	long long int ans = 1;
	for(int i=1;i<b;i++)
	{
		if(right[i]>left[i+1])
		{
			printf("0");
			return 0;
		}
		ans *= (left[i+1]-right[i]);
		ans %= MOD;
	}
	printf("%lld",ans);
}