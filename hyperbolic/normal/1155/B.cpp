#include <stdio.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int s1 = 0, s2 = 0;
	for(int i=1;i<=a-11;i++)
	{
		if(x[i]=='8')
		{
			s1++;
			if(s1>(a-11)/2)
			{
				printf("YES");
				return 0;
			}
		}
		else
		{
			s2++;
			if(s2>(a-11)/2)
			{
				printf("NO");
				return 0;
			}
		}
	}
	if(x[a-10]=='8') printf("YES");
	else printf("NO");
}