#include <stdio.h>
#include <string.h>

char x[100010];
int check[100010];
int func(int k)
{
	for(int i=0;i<26;i++)
	{
		for(int j=k;j>=1;j--)
		{
			if(x[j]==i+'a')
			{
				if(j==k) return k-1;
				else
				{
					check[j] = 1;
					check[k] = 1;
					return j-1;
				}
			}
		}
	}
}
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	int max;
	for(int i=0;i<26;i++)
	{
		for(int j=a;j>=1;j--)
		{
			if(x[j]==i+'a')
			{
				max = j-1;
				check[j] = 1;
				goto u;
			}
		}
	}
	u:;
	while(max>0)
	{
		max = func(max);
	}
	for(int i=1;i<=a;i++) printf("%d ",check[i]);
}