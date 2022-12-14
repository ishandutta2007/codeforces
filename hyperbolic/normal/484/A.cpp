#include <stdio.h>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		for(int i=0;i<=60;i++)
		{
			x[i] = a%2;
			y[i] = b%2;
			a/=2, b/=2;
		}
		
		long long int s = 0;
		for(int i=60;i>=0;i--)
		{
			s*=2;
			if(x[i]==y[i]) s += x[i];
			else
			{
				for(int j=i-1;j>=0;j--)
				{
					if(y[j]==0)
					{
						for(int k=i-1;k>=0;k--) s*=2, s++;
						printf("%lld\n",s);
						goto u;
					}
				}
				s++;
				for(int j=i-1;j>=0;j--) s*=2, s++;
				printf("%lld\n",s);
				goto u;
			}
		}
		printf("%lld\n",s);
		u:;
	}
}