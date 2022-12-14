#include <stdio.h>

int ans[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==2)
		{
			printf("3 1\n");
			continue;
		}
		
		int start = (7*a)/2;
		start--;
		
		for(int i=1;i<=a-1;i++) ans[i] = start+(i-1);
		ans[a] = start + (2*a);
		
		long long int val = (long long int)4*a*a;
		for(int i=1;i<=a;i++) val -= ans[i];
		ans[a-1] += val;
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}