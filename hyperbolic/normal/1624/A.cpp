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
		int min = x[1], max = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		printf("%d\n",max-min);
	}
}