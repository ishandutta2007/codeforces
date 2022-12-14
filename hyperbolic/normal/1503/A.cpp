#include <stdio.h>

char x[200010],y[200010],z[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='0')
			{
				if(count%2==0) y[i] = '(', z[i] = ')';
				else y[i] = ')', z[i] = '(';
				count++;
			}
		}
		if(count%2==1)
		{
			printf("NO\n");
			continue;
		}
		
		count/=2;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='1')
			{
				if(count<a/2)
				{
					count++;
					y[i] = '(', z[i] = '(';
				}
				else y[i] = ')', z[i] = ')';
			}
		}
		
		int count1 = 0, count2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(y[i]=='(') count1++;
			else count1--;
			if(z[i]=='(') count2++;
			else count2--;
			if(count1<0 || count2<0)
			{
				printf("NO\n");
				goto u;
			}
		}
		if(count1==0&&count2==0)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%c",y[i]);
			printf("\n");
			for(int i=1;i<=a;i++) printf("%c",z[i]);
			printf("\n");
		}
		else printf("NO\n");
		u:;
	}
}