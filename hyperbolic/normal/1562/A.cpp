#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int t = (b+1)/2;
		if(a<=t) printf("%d\n",t-1);
		else printf("%d\n",b-a);
		
	}
}