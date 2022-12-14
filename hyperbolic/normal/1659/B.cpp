#include <stdio.h>

char x[200010];
int check[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		if(b%2==0)
		{
			for(int i=1;i<=a;i++)
			{
				if(x[i]=='0'&&b>=1)
				{
					x[i] = '1';
					check[i] = 1;
					b--;
				}
			}
			check[a] += b;
			if(b%2==1) x[a] = '0'+'1'-x[a];
			for(int i=1;i<=a;i++) printf("%c",x[i]);
			printf("\n");
			for(int i=1;i<=a;i++) printf("%d ",check[i]);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				if(x[i]=='1'&&b>=1)
				{
					x[i] = '0';
					check[i] = 1;
					b--;
				}
			}
			check[a] += b;
			if(b%2==1) x[a] = '0'+'1'-x[a];
			
			for(int i=1;i<=a;i++) printf("%c",'0'+'1'-x[i]);
			printf("\n");
			for(int i=1;i<=a;i++) printf("%d ",check[i]);
			printf("\n");
		}
	}
}