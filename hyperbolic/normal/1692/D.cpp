#include <stdio.h>

int count[10010],check[10010];
int main()
{
	for(int i=0;i<1440;i++)
	{
		int s = i/60;
		int t = i%60;
		if(s/10==t%10 && s%10==t/10) count[i] = 1;
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=1440;i++) check[i] = 0;
		int a,b,c;
		scanf("%d:%d %d",&a,&b,&c);
		int start = 60*a+b;
		int ans = 0;
		while(check[start]==0)
		{
			check[start] = 1;
			ans += count[start];
			start += c, start %= 1440;
		}
		printf("%d\n",ans);
	}
}