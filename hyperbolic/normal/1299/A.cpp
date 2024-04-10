#include <stdio.h>
#include <string>
#include <algorithm>

std::string S[100010];

int x[100010],y[100010][40],check[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int s = x[i];
		for(int j=0;j<=31;j++) y[i][j] = s%2, s/=2;
	}
	
	for(int j=0;j<=31;j++)
	{
		int count = 0;
		int c = 0;
		for(int i=1;i<=a;i++) if(y[i][j]==1) count++, c = i;
		if(count==1) check[j] = c;
	}
	
	for(int j=31;j>=0;j--)
	{
		if(check[j]!=0)
		{
			printf("%d ",x[check[j]]);
			for(int k=1;k<=a;k++)
			{
				if(k==check[j]) continue;
				printf("%d ",x[k]);
			}
			return 0;
		}
	}
	for(int i=1;i<=a;i++) printf("%d ",x[i]);
}