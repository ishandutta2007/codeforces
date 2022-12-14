#include <stdio.h>
#include <string.h>

char x[5010];

int main()
{
	scanf("%s",x);
	int a = strlen(x);
	for(int i=0;i<a;i++) if(x[i]!=x[0]) goto u;
	printf("Impossible");
	return 0;
	
	u:;
	
	for(int i=0;i<a;i++)
	{
		for(int j=i;j<a+i;j++)
		{
			if(x[j%a]!=x[(2*i-(j%a)-1+2*a)%a]) goto v;
		}
		for(int j=i;j<a+i;j++)
		{
			if(x[j%a]!=x[j-i])
			{
				printf("1");
				return 0;
			}
		}
		v:;
	}
	if(a%2==1)
	{
		for(int i=0;i<a/2;i++)
		{
			if(x[i]!=x[0])
			{
				printf("2");
				return 0;
			}
		}
		printf("Impossible");
		return 0;
	}
	printf("2");
}

//i -> i-1
// i+1 -> i-2