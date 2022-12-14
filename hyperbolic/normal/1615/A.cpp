#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		int b = sum/a;
		if(sum==b*a) printf("0\n");
		else printf("1\n");
	}
}