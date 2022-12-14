#include <stdio.h>

long long int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	if(a==1)
	{
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("%lld",-x[1]);
		return 0;
	}
	printf("1 1\n");
	printf("%lld\n",-x[1]);
	x[1] = 0;
	
	printf("2 %d\n",a);
	for(int i=2;i<=a;i++) printf("%lld ",x[i]*(a-1));
	printf("\n");
	
	printf("1 %d\n",a);
	for(int i=1;i<=a;i++) printf("%lld ",-x[i]*a);
}