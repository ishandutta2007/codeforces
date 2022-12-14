#include <stdio.h>
#include <string.h>
 
char x[1000010];
int main()
{
	int a;
	scanf("%d\n",&a);
	scanf("%[^\n]",x+1);
	int b = strlen(x+1);
	
	int min = 1, max = b;
	int ans = b;
	while(min<=max)
	{
		int h = (min+max)/2;
		int count = 0, sum1 = 0, sum2 = 0;
		for(int i=1;i<=b;i++)
		{
			sum2++;
			if('a'<=x[i]&&x[i]<='z');
			else if('A'<=x[i]&&x[i]<='Z');
			else
			{
				if(sum1+sum2>h)
				{
					count++;
					sum1 = 0;
				}
				if(sum2>h)
				{
					min = h+1;
					goto u;
				}
				sum1 += sum2;
				sum2 = 0;
			}
		}
		
		if(sum1+sum2>h)
		{
			count++;
			sum1 = 0;
		}
		if(sum2>h)
		{
			min = h+1;
			goto u;
		}
		count++;
		
		if(count<=a)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
		u:;
	}
	printf("%d",ans);
}