#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int val = x[a];
		int ans = 0;
		for(int i=a-1;i>=1;i--)
		{
			if(x[i]>val)
			{
				val = x[i];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}