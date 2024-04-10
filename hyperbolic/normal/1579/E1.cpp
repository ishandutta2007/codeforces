#include <stdio.h>

int x[200010],min[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		min[0] = 12345678;
		for(int i=1;i<=a;i++) min[i] = min[i-1]<x[i]?min[i-1]:x[i];
		
		for(int i=a;i>=1;i--) if(min[i]!=min[i-1]) printf("%d ",x[i]);
		for(int i=1;i<=a;i++) if(min[i]==min[i-1]) printf("%d ",x[i]);
		printf("\n");
	}
}