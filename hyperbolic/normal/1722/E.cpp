#include <stdio.h>

long long int count[1010][1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) count[i][j] = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			count[c][d]+= c*d;
		}
		for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) count[i][j] += count[i][j-1];
		for(int j=1;j<=1000;j++) for(int i=1;i<=1000;i++) count[i][j] += count[i-1][j];
		
		while(b--)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%lld\n",count[x2-1][y2-1] - count[x2-1][y1] - count[x1][y2-1] + count[x1][y1]);
		}
	}
}