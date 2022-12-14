#include <stdio.h>

int a;
int x[5002];
short check[5002][5002];

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int j=0;j<=a+1;j++) check[a+1][j] = 0;
	for(int i=1;i<=a;i++) check[i][a+1] = 12345678;
	
	for(int i=a;i>=1;i--)
	{
		for(int j=a;j>=0;j--)
		{
			short s1 = check[i][j+1]+1;
			short s2 = 0;
			if(j>=x[i]) s2 = check[i+1][x[i]];
			else s2 = check[i+1][j]+1;
			check[i][j] = s1<s2?s1:s2;
		}
	}
	
	printf("%d",check[1][0]);
}