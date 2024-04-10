#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		int s1 = c-1, s2 = a-c;
		int t1 = d-1, t2 = b-d;
		if(s1<=e&&t1<=e) printf("-1\n");
		else if(s2<=e&&t2<=e) printf("-1\n");
		else if(s1<=e&&s2<=e) printf("-1\n");
		else if(t1<=e&&t2<=e) printf("-1\n");
		else printf("%d\n",a+b-2);
	}
}