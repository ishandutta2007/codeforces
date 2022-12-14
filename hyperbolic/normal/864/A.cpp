#include <stdio.h>
int x[110];
int main()
{
	int s,t;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=2;i<=a;i++)
	{
		if(x[i]!=x[1])
		{
			s = x[i];
			t = x[1];
			goto u;
		}
	}
	printf("NO");
	return 0;
	
	u:;
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=s&&x[i]!=t)
		{
			printf("NO");
			return 0;
		}
	}
	
	int c1=0,c2=0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==s) c1++;
		if(x[i]==t) c2++;
	}
	if(c1==c2) printf("YES\n%d %d",s,t);
	else printf("NO");
}