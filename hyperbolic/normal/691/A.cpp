#include <stdio.h>

int main()
{
	int a,b,s=0;
	scanf("%d",&a);
	if(a==1)
	{
		scanf("%d",&b);
		if(b==1) printf("YES");
		else printf("NO");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		s+=b;
	}
	if(s==a-1) printf("YES");
	else printf("NO");
}