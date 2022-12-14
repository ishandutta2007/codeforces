#include <stdio.h>

char x[1010],y[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=b;i++)
		{
			int control = 0;
			for(int j=1;j<=a;j++) y[j] = x[j];
			for(int j=1;j<=a;j++)
			{
				if(x[j]=='1') continue;
				int count = 0;
				if(x[j-1]=='1') count++;
				if(x[j+1]=='1') count++;
				if(count==1) control = 1, y[j] = '1';
			}
			if(control==0) break;
			for(int j=1;j<=a;j++) x[j] = y[j];
		}
		
		for(int i=1;i<=a;i++) printf("%c",x[i]);
		printf("\n");
	}
}