#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		if(b>c)
		{
			int t = b;
			b = c;
			c = t;
		}
		
		if(d+e<=b) printf("%d\n",c-b);
		else if(c<=d-e) printf("%d\n",c-b);
		else
		{
			int s1 = (d-e)-b>0?(d-e)-b:0;
			int s2 = c-(d+e)>0?c-(d+e):0;
			printf("%d\n",s1+s2);
		}
	}
}