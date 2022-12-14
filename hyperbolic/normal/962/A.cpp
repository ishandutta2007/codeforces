#include <stdio.h>

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int sum = 0, sum2 = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	for(int i=1;i<=a;i++)
	{
		sum2 += x[i];
		if(sum2*2>=sum)
		{
			printf("%d",i);
			return 0;
		}
	}
}