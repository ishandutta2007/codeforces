#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=c;i++) scanf("%d",&x[i]);
		
		// case 1
		int control = 0;
		long long int sum = 0;
		for(int i=1;i<=c;i++) if(x[i]>=2*a) sum += (x[i]/a);
		for(int i=1;i<=c;i++) if(x[i]>=3*a) control = 1;
		if(sum>=b)
		{
			if(control==1 || b%2==0)
			{
				printf("YES\n");
				continue;
			}
		}
		
		control = 0;
		sum = 0;
		for(int i=1;i<=c;i++) if(x[i]>=2*b) sum += (x[i]/b);
		for(int i=1;i<=c;i++) if(x[i]>=3*b) control = 1;
		if(sum>=a)
		{
			if(control==1 || a%2==0)
			{
				printf("YES\n");
				continue;
			}
		}
		
		printf("NO\n");
	}
}