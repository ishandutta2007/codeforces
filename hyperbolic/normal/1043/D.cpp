#include <stdio.h>

int x[100010][20];
int index[100010][20];
int sparse[100010][30];
int a,b;

int func(int s)
{
	int sum = 0;
	for(int j=20;j>=0;j--)
	{
		if(sparse[s][j]==1)
		{
			sum+=(1<<j);
			int C = -1;
			for(int k=1;k<=b;k++)
			{
				if(index[s][k]+(1<<j)>a) return sum;
				else
				{
					if(C == -1) C = x[index[s][k]+(1<<j)][k];
					else if(C!=x[index[s][k]+(1<<j)][k]) return sum;
				}
			}
			s = x[index[s][1]+(1<<j)][1];
		}
	}
	return sum;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) scanf("%d",&x[i][j]);
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) index[x[i][j]][j] = i;
	
	for(int i=1;i<=a;i++) sparse[i][0] = 1;
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=a;i++)
		{
			if(sparse[i][j-1]==-1) sparse[i][j] = -1;
			else
			{
				int C = -1;
				for(int k=1;k<=b;k++)
				{
					if(index[i][k]+(1<<(j-1))>a)
					{
						sparse[i][j] = -1;
						goto u;
					}
					else
					{
						if(C==-1) C = x[index[i][k]+(1<<(j-1))][k];
						else if(C!=x[index[i][k]+(1<<(j-1))][k])
						{
							sparse[i][j] = -1;
							goto u;
						}
					}
				}
				if(sparse[C][j-1]==-1) sparse[i][j] = -1;
				else sparse[i][j] = 1;
				u:;
			}
		}
	}
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += func(i);
	printf("%lld",sum);
}