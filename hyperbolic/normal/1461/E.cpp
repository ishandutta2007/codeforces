#include <stdio.h>

int check[1000010];
int main()
{
	long long int k,l,r,t,x,y;
	scanf("%lld%lld%lld%lld%lld%lld",&k,&l,&r,&t,&x,&y);
	if(x>y)
	{
		if(k+y>r)
		{
			if((double)(k-l-x)/(x-y)<(t-1)) printf("No");
			else printf("Yes");
		}
		else
		{
			if((double)(k-l)/(x-y)<t) printf("No");
			else printf("Yes");
		}
	}
	else
	{
		if((l-1)+x<=r-y) printf("Yes");
		else
		{
			long long int sum = (k-l)/x;
			long long int state = (k-l)%x;
			
			if(sum>=t) printf("Yes");
			else
			{
				check[state] = 1;
				long long int S1 = y/x;
				long long int S2 = y%x;
				while(1)
				{
					if(state+l+y>r)
					{
						printf("No");
						return 0;
					}
					
					sum += S1;
					state += S2;
					if(state>x)
					{
						state-=x;
						sum++;
					}
					
					if(sum>=t)
					{
						printf("Yes");
						return 0;
					}
					else if(check[state]==1)
					{
						printf("Yes");
						return 0;
					}
					else check[state] = 1;
				}
			}
			
		}
	}
}