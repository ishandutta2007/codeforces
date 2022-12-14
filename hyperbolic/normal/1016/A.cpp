#include <stdio.h>
int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int sum = 0;
	for(int i=1;i<=a;i++)
	{
		sum += x[i];
		printf("%d ",sum/b);
		sum%=b;
	}
}