#include <stdio.h>
#define MAX (long long int)1e16

long long int count1[200010],count2[200010];
int x[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) count1[i] = count2[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int min = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		long long int ans = 0, C = 0;
		if(min<0)
		{
			C -= min;
			for(int i=1;i<=a;i++) x[i] -= min;
		}
		for(int i=1;i<=a;i++)
		{
			count1[i] += x[i];
			count2[i] += x[i];
			C+=x[i];
		}
		count1[0] = count2[a+1] = MAX;
		for(int i=0;i<=a;i++)
		{
			long long int min = count1[i]<count2[i+1]?count1[i]:count2[i+1];
			min = min<C?min:C;
			C -= min;
			count1[i] -= min;
			count2[i+1] -= min;
		}
		for(int i=1;i<=a;i++) ans += count1[i];
		for(int i=1;i<=a;i++) ans += count2[i];
		ans += C;
		
		printf("%lld\n",ans);
	}
}