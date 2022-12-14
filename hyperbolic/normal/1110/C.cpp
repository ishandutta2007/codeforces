#include <stdio.h>

int func(int k)
{
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0) return (k/i);
	}
	return 1;
}
int table[50];
int main()
{
	table[1] = 1; // 2^1-1
	for(int i=2;i<=27;i++) table[i] = table[i-1]*2+1;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=25;j++)
		{
			if(b==table[j])
			{
				printf("%d\n",func(table[j]));
				goto u;
			}
		}
		for(int j=1;j<=26;j++)
		{
			if(b<=table[j])
			{
				printf("%d\n",table[j]);
				break;
			}
		}
		u:;
	}
}