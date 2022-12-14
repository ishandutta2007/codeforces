#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans = 0;
	for(int i=1;i<=a-1;i++)
	{
		int s = i, t = a-i;
		if(s>b) continue;
		if(t>c) continue;
		int min = (b/s)<(c/t)?(b/s):(c/t);
		ans = ans>min?ans:min;
	}
	printf("%d",ans);
}