#include <stdio.h>
int check[10];
int posNum(int k)
{
	int count = 0;
	do
	{
		count++;
		k/=7;
	}while(k);
	return count;
}
void clear()
{
	for(int i=0;i<=7;i++) check[i] = 0;
}
void func(int k, int count)
{
	for(int i=1;i<=count;i++)
	{
		check[k%7]++;
		k/=7;
	}
}
int main()
{
	int a,b;
	int count=0,k;
	scanf("%d%d",&a,&b);
	if(posNum(a-1)+posNum(b-1)>=8)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			clear();
			func(i,posNum(a-1));
			func(j,posNum(b-1));
			for(k=0;k<7;k++)
			{
				if(check[k]>1) break;
			}
			if(k==7)
			{
				 count++;
			}
		}
	}
	printf("%d",count);
}