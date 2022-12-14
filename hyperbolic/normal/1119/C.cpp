#include <stdio.h>

int x[510][510],y[510][510];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&y[i][j]);
	
	for(int i=1;i<a;i++)
	{
		for(int j=1;j<b;j++)
		{
			if(x[i][j]==1)
			{
				x[i][j] = 0;
				x[a][j]++;
				x[i][b]++;
				x[a][b]++;
			}
		}
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j]%=2;
	
	for(int i=1;i<a;i++)
	{
		for(int j=1;j<b;j++)
		{
			if(y[i][j]==1)
			{
				y[i][j] = 0;
				y[a][j]++;
				y[i][b]++;
				y[a][b]++;
			}
		}
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j]%=2;

	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]!=y[i][j])
			{
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");
}