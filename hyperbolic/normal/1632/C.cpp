#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ans = b-a;
		for(int i=a;i<b;i++)
		{
			int c = (i|b);
			ans = ans<(i-a)+(c-b)+1?ans:(i-a)+(c-b)+1;
		}
		for(int i=b+1;i<=a+b;i++)
		{
			int c = (a|i);
			ans = ans<(i-b)+(c-i)+1?ans:(i-b)+(c-i)+1;
		}
		printf("%d\n",ans);
	}
}