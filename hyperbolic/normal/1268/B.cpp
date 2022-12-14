#include <stdio.h>

int a;
long long int count[3];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		count[i%2] += (b/2);
		count[(i+1)%2] += (b+1)/2;
	}
	printf("%lld",count[0]<count[1]?count[0]:count[1]);
}