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
		if(a%2==1) printf("Mike\n");
		else
		{
			int ans1 = 1, ans2 = 2;
			for(int i=1;i<=a;i+=2) if(x[i]<x[ans1]) ans1 = i;
			for(int i=2;i<=a;i+=2) if(x[i]<x[ans2]) ans2 = i;
			long long int sum1 = (long long int)x[ans1]*a+ans1;
			long long int sum2 = (long long int)x[ans2]*a+ans2;
			if(sum1<=sum2) printf("Joe\n");
			else printf("Mike\n");
		}
	}
}