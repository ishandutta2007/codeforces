#include <stdio.h>

char x[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		int c = a+b;
		for(int i=1;i<=c;i++)
		{
			int t = (c-i+1);
			if(x[i]=='?'&&x[t]=='?');
			else if(x[i]=='?') x[i] = x[t];
			else if(x[t]=='?') x[t] = x[i];
			else if(x[i]!=x[t])
			{
				printf("-1\n");
				goto u;
			}
		}
		
		for(int i=1;i<=c;i++)
		{
			if(x[i]=='0') a--;
			if(x[i]=='1') b--;
		}
		if(a<0 || b<0)
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=c;i++)
		{
			if(x[i]=='?')
			{
				if(i==c-i+1)
				{
					if(a>=1)
					{
						x[i] = '0';
						a--;
					}
					else
					{
						x[i] = '1';
						b--;
					}
				}
				else
				{
					if(a>=2)
					{
						x[i] = x[c-i+1] = '0';
						a-=2;
					}
					else
					{
						x[i] = x[c-i+1] = '1';
						b-=2;
					}
				}
			}
		}
		if(a<0 || b<0) printf("-1\n");
		else
		{
			for(int i=1;i<=c;i++) printf("%c",x[i]);
			printf("\n");
		}
		u:;
	}
}