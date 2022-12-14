#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",x+1);
		
		if(c>=0) printf("%d\n",(b+c)*a);
		else
		{
			int count = 0;
			for(int i=1;i<=a;i++)
			{
				if(x[i]!=x[i-1]) count++;
			}
			printf("%d\n",a*b+c*(count/2+1));
		}
	}
}