#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%s",&a,x+1);
		
		int s = a+1, t = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='1')
			{
				s = i;
				break;
			}
		}
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='0')
			{
				t = i;
				break;
			}
		}
		
		if(s<t)
		{
			for(int i=1;i<s;i++) printf("%c",x[i]);
			for(int i=t;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
		else
		{
			for(int i=1;i<s;i++) printf("%c",x[i]);
			for(int i=t+1;i<=a;i++) printf("%c",x[i]);
			printf("\n");
		}
	}
}