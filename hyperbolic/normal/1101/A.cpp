#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c<a) printf("%d\n",c);
		else
		{
			int d = ((b/c)+1)*c;
			printf("%d\n",d);
		}
	}
}