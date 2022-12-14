#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int ans = a;
	for(int i=0;;i++)
	{
		int s = a-i*b;
		if(s<0) break;
		s %= (5*c);
		ans = ans<s?ans:s;
	}
	printf("%d",ans);
}