#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	d = b-a;
	if(c==0)
	{
		if(d==0) printf("YES");
		else printf("NO");
		return 0;
	}
	else if(c>0)
	{
		if(d>=0&&d%c==0) printf("YES");
		else printf("NO");
		return 0;
	}
	else
	{
		if(d<=0&&(-d)%(-c)==0) printf("YES");
		else printf("NO");
		return 0;
	}
}