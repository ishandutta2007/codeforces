#include <stdio.h>

int a[210],b[210];
int check[210][210];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	
	int ans = 0;
	for(int k=9;k>=0;k--)
	{
		int C = 0;
		for(int i=1;i<=n;i++)
		{
			int D = 4095; // 2^k-1 = 1111...111(2)
			for(int j=1;j<=m;j++)
			{
				if(check[i][j]==1) continue; // deleted case
				D&=(a[i]&b[j]);
			}
			C|=D;
		}
		if((C&(1<<k))!=0) // k-bit of C = 1
		{
			ans += (1<<k); // k-bit of ans = 1;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(check[i][j]==1) continue; //deleted case
					if(((a[i]&b[j])&(1<<k))!=0) check[i][j] = 1; //delete
				}
			}
		}
	}
	printf("%d",ans);
}