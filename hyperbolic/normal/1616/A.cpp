#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=100;i++) count[i] = 0;
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[abs(b)]++;
		}
		
		int ans = 0;
		for(int i=1;i<=100;i++) ans += (count[i]<2?count[i]:2);
		ans += (count[0]<1?count[0]:1);
		printf("%d\n",ans);
	}
}