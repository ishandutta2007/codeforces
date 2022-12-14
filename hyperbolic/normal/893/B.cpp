#include <stdio.h>
bool func(int k)
{
	for(int i=1;i<100;i++)
	{
		int c = ((1<<i)-1)*(1<<(i-1));
		if(k==c) return true;
		if(k<c) return false;
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=a;i>=1;i--)
	{
		if(a%i==0)
		{
			if(func(i))
			{
				printf("%d",i);
				return 0;
			}
		}
	}
}