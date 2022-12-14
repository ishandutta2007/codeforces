#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int e,f,g,h,i;
		scanf("%d%d%d%d%d",&e,&f,&g,&h,&i);
		a-=e;
		b-=f;
		c-=g;
		if(a<0) printf("NO\n");
		else if(b<0) printf("NO\n");
		else if(c<0) printf("NO\n");
		else
		{
			if(h<a) h = 0;
			else h-= a;
			if(i<b) i = 0;
			else i-=b;
			if(h+i<=c) printf("YES\n");
			else printf("NO\n");
		}
	}
}