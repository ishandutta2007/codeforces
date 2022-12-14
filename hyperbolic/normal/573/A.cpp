#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		while(x[i]%2==0) x[i]/=2;
		while(x[i]%3==0) x[i]/=3;
	}
	for(int i=1;i<a;i++)
	{
		if(x[i]!=x[i+1])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}