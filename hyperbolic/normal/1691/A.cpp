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
		
		int count = 0;
		for(int i=1;i<=a;i++) if(x[i]%2==0) count++;
		printf("%d\n",count<a-count?count:a-count);
	}
}