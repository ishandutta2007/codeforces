#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int ans = x[1];
		int s = 0;
		for(int i=2;i<=a;i++)
		{
			if(s+x[i]*(i-1)<=b)
			{
				ans += x[i];
				s += x[i]*(i-1);
			}
			else
			{
				ans += (b-s)/(i-1);
				break;
			}
		}
		printf("%d\n",ans);
	}
}