#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e,f;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(a==c&&c==e)
		{
			if(b<d && b<=f&&f<=d) printf("%d\n",abs(b-d)+2);
			else if(b>=d && d<=f&&f<=b) printf("%d\n",abs(b-d)+2);
			else printf("%d\n",abs(b-d));
		}
		else if(b==d&&d==f)
		{
			if(a<c&&a<=e&&e<=c) printf("%d\n",abs(a-c)+2);
			else if(a>=c&&c<=e&&e<=a) printf("%d\n",abs(a-c)+2);
			else printf("%d\n",abs(a-c));
		}
		else printf("%d\n",abs(a-c)+abs(b-d));
	}
}