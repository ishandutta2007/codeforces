#include <stdio.h>

int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=100;i++) count[i] = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[b]++;
		}
		for(int i=0;i<=100;i++) ans += count[i]<b?count[i]:b;
		printf("%d\n",ans);
	}
}