#include <stdio.h>

int count[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			count[c]++;
		}
		
		int ans = 0;
		while(1)
		{
			int h = b;
			int control = 0;
			for(int i=524288;i>=1;i/=2)
			{
				while(count[i]>0 && h>=i) control = 1,count[i]--, h-=i;
			}
			if(control==0)
			{
				printf("%d\n",ans);
				break;
			}
			ans++;
		}
		
	}
}