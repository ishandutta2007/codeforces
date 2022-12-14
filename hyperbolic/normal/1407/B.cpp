#include <stdio.h>
#include <algorithm>
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[1010];
int check[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int S = x[a];
		for(int i=1;i<=a;i++)
		{
			int max = 1;
			int ind = 0;
			for(int j=1;j<=a;j++)
			{
				if(check[j]==0&&gcd(S,max)<=gcd(S,x[j]))
				{
					max = x[j];
					ind = j;
				}
			}
			
			printf("%d ",max);
			check[ind] = 1;
			S = gcd(S,max);
		}
		printf("\n");
	}
}