#include <stdio.h>

char x[1010][1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int min1 = 123456, max1 = 0, min2 = 123456, max2 = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='B')
			{
				min1 = min1<i?min1:i;
				max1 = max1>i?max1:i;
				min2 = min2<j?min2:j;
				max2 = max2>j?max2:j;
			}
		}
	}
	printf("%d %d",(min1+max1)/2,(min2+max2)/2);
}