#include <stdio.h>

int a;
char x[100010],z[100010],y[10];
int func()
{
	int count = 0;
	for(int i=1;i<=a-6;i++)
	{
		for(int j=i;j<=i+6;j++) if(z[j]!=y[j-i+1]) goto u;
		count++;
		u:;
	}
	return count;
}
int main()
{
	y[1] = 'a', y[2] = 'b', y[3] = 'a', y[4] = 'c';
	y[5] = 'a', y[6] = 'b', y[7] = 'a';
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int count = 0;
		for(int i=1;i<=a-6;i++)
		{
			for(int j=1;j<=a;j++) z[j] = x[j];
			for(int p=i;p<=i+6;p++) if(x[p]!='?'&&x[p]!=y[p-i+1]) goto u;
			for(int j=i;j<=i+6;j++) z[j] = y[j-i+1];
			for(int j=1;j<=a;j++) if(z[j]=='?') z[j] = 'z';
			if(func()==1)
			{
				printf("Yes\n");
				for(int j=1;j<=a;j++) printf("%c",z[j]);
				printf("\n");
				goto v;
			}
			u:;
		}
		printf("No\n");
		v:;
	}
}