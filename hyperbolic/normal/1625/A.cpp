#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int ans = 0;
		for(int j=b-1;j>=0;j--)
		{
			int s = 0;
			for(int i=1;i<=a;i++) s += ((x[i]>>j)&1);
			if(2*s>=a) ans += (1<<j);
		}
		printf("%d\n",ans);
	}
}