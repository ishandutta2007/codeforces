#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int min = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		if(min==x[1]) printf("Bob\n");
		else printf("Alice\n");
	}
}