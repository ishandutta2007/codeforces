#include <stdio.h>

int p[100010],x[100010];
long long int max[100010],sum[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) max[i] = max[i-1]>x[i]?max[i-1]:x[i];
		for(int i=1;i<=a;i++)
		{
			if(max[i]==x[i]) p[i] = i;
			else p[i] = p[i-1];
		}
		
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i];
		
		int ans = -1;
		for(int i=1;i<=a;i++) if(sum[i]-max[i]<=b) ans = p[i];
		if(sum[a]<=b) ans = 0;
		printf("%d\n",ans);
	}
}