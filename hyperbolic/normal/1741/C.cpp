#include <stdio.h>

int x[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		
		int ans = a;
		for(int i=1;i<=a;i++)
		{
			if(sum%i==0)
			{
				int val = sum/i;
				int count = 0, max = 0;
				int s = 0, t = 0;
				for(int j=1;j<=a;j++)
				{
					s += x[j], t++;
					if(s>val) goto u;
					if(s==val)
					{
						max = max>t?max:t;
						count++;
						s = t = 0;
					}
				}
				if(count==i) ans = ans<max?ans:max;
			}
			u:;
		}
		printf("%d\n",ans);
	}
}