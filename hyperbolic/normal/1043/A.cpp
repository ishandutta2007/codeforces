#include <stdio.h>

int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int sum = 0;
	int max = x[1];
	for(int i=2;i<=a;i++) max = max>x[i]?max:x[i];
	for(int i=1;i<=a;i++) sum += x[i];
	for(int i=max;;i++)
	{
		if(a*i-sum>sum)
		{
			printf("%d",i);
			return 0;
		}
	}
}