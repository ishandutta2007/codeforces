#include <stdio.h>
#include <algorithm>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

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
		std::sort(x+1,x+a+1);
		if(x[1]<0) printf("NO\n");
		else
		{
			int C = 0;
			if(x[1]==0) C = 1;
			
			int g = 0;
			for(int i=1;i<=a;i++) g = gcd(g,x[i]);
			if(g*(300-C)>=x[a])
			{
				printf("YES\n");
				printf("300\n");
				
				if(C==1) for(int i=0;i<300;i++) printf("%d ",(g)*i);
				else for(int i=1;i<=300;i++) printf("%d ",(g)*i);
				printf("\n");
			}
			else printf("NO\n");
		}
	}
}