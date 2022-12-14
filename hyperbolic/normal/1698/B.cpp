#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(b==1) printf("%d\n",(a-2+1)/2);
		else
		{
			int sum = 0;
			for(int i=2;i<=a-1;i++)
			{
				if(x[i]>x[i-1]+x[i+1]) sum++;
			}
			printf("%d\n",sum);
		}
	}
}