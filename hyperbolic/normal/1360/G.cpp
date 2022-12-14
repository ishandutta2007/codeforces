#include <stdio.h>

int check[110][110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a*c==b*d)
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] = 0;
			int s = 1, t = 1;
			int sum = 0;
			while(s<=a)
			{
				if(t>b) t = 1;
				check[s][t] = 1;
				t++;
				sum++;
				if(sum==c) s++, sum = 0;
			}
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=b;j++) printf("%d",check[i][j]);
				printf("\n");
			}
		}
		else printf("NO\n");
	}
}