#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int j=1;j<=(b%2)+2;j++)
		{
			int max = -1234567890;
			for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
			for(int i=1;i<=a;i++) x[i] = max-x[i];
		}
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}