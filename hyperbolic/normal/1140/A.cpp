#include <stdio.h>

int x[10010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int p = 1;
	int max = 0;
	int count = 0;
	while(p<=a)
	{
		max = max>x[p]?max:x[p];
		if(max==p) count++;
		p++;
	}
	printf("%d",count);
}