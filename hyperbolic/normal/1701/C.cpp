#include <stdio.h>


int count[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			count[c]++;
		}
		
		int ans = 0;
		int min = 1, max = 2*b;
		while(min<=max)
		{
			long long int s1 = 0;
			long long int s2 = 0;
			int h = (min+max)/2;
			for(int i=1;i<=a;i++)
			{
				if(count[i]>=h) s2 += (count[i]-h);
				else s1 += (h-count[i])/2;
			}
			if(s1>=s2)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%d\n",ans);
	}
}