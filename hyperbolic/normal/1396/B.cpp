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
		
		int max = x[1];
		for(int i=2;i<=a;i++) max = max>x[i]?max:x[i];
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		if(max>sum-max) printf("T\n");
		else if((sum-max-max)%2==0) printf("HL\n");
		else printf("T\n");
	}
}