#include <stdio.h>

char x[200010],y[110];
int check[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<26;i++) check[i] = 0;
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			scanf("%s",y+1);
			check[y[1]-'a'] = 1;
		}
		
		int p = 1;
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[x[i]-'a']==1)
			{
				ans = ans>i-p?ans:i-p;
				p = i;
			}
		}
		printf("%d\n",ans);
	}
}