#include <stdio.h>

char x[200010];
int ans1[200010],ans2[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%s",&a,x+1);
		
		int p = 1;
		x[a] = '<';
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='<')
			{
				for(int j=p;j<=i;j++) ans1[j] = (i+p-j);
				p = i+1;
			}
		}
		
		p = 1;
		x[a] = '>';
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='>')
			{
				for(int j=p;j<=i;j++) ans2[j] = (a+j-i-p+1); // a-i ~ a-p
				p = i+1;
			}
		}
		
		for(int i=1;i<=a;i++) printf("%d ",ans2[i]);
		printf("\n");
		for(int i=1;i<=a;i++) printf("%d ",ans1[i]);
		printf("\n");
	}
}