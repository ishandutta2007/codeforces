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
		for(int i=1;i<=a;i++) if(x[i]<0) x[i]*=-1;
		for(int i=2;i<=a;i+=2) x[i]*=-1;
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}