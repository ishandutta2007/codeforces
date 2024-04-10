#include <stdio.h>

int count1[400010],count2[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) count1[i] = count2[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int d;
			scanf("%d",&d);
			count1[d]++;
		}
		for(int i=1;i<=c;i++)
		{
			int d;
			scanf("%d",&d);
			count2[d]++;
		}
		for(int i=1;i<=a;i++)
		{
			int t = count1[i]<count2[i]?count1[i]:count2[i];
			count1[i] -= t, count2[i] -= t;
		}
		
		int sum1 = 0, sum2 = 0;
		for(int i=1;i<=a;i++) sum1 += count1[i];
		for(int i=1;i<=a;i++) sum2 += count2[i];
		
		int ans = 0;
		if(sum1>=sum2)
		{
			int S = (sum1-sum2)/2;
			for(int i=1;i<=a;i++)
			{
				int t = count1[i]/2<S?count1[i]/2:S;
				ans += t, S -= t, count1[i] -= 2*t;
			}
			ans += 2*S + sum2;
		}
		else
		{
			int S = (sum2-sum1)/2;
			for(int i=1;i<=a;i++)
			{
				int t = count2[i]/2<S?count2[i]/2:S;
				ans += t, S -= t, count2[i] -= 2*t;
			}
			ans += 2*S + sum1;
		}
		printf("%d\n",ans);
	}
}