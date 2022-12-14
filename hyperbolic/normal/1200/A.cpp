#include <stdio.h>
#include <string.h>

char x[100010];
int check[20];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='L')
		{
			for(int j=0;j<=9;j++)
			{
				if(check[j]==0)
				{
					check[j] = 1;
					break;
				}
			}
		}
		else if(x[i]=='R')
		{
			for(int j=9;j>=0;j--)
			{
				if(check[j]==0)
				{
					check[j] = 1;
					break;
				}
			}
		}
		else check[x[i]-'0'] = 0;
	}
	for(int j=0;j<=9;j++) printf("%d",check[j]);
}