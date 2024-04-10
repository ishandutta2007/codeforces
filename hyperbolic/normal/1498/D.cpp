#include <stdio.h>

long long int next(long long int k)
{
	if(k%100000==0) return k;
	else return (k/100000)*100000 + 100000;
}

long long int check[100010];
long long int left[100010];
int main()
{
	long long int d;
	long long int e;
	scanf("%lld%lld",&d,&e);
	e*=100000;
	for(long long int j=1;j<=e/100000;j++) check[j] = -1;
	check[0] = 0;
	for(long long int i=1;i<=d;i++)
	{
		long long int a,c;
		long long int b;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==1)
		{
			for(long long int j=0;j<=e;j+=100000)
			{
				if(check[j/100000]!=-1)
				{
					if(check[j/100000]==i)
					{
						if(left[j/100000]>=1)
						{
							long long int s = next(j+b);
							if(s>e) continue;
							if(check[s/100000]==-1)
							{
								check[s/100000] = i;
								left[s/100000] = left[j/100000] -1;
							}
						}
					}
					else
					{
						long long int s = next(j+b);
						if(s>e) continue;
						if(check[s/100000]==-1)
						{
							check[s/100000] = i;
							left[s/100000] = c-1;
						}
					}
				}
			}
		}
		else
		{
			for(long long int j=0;j<=e;j+=100000)
			{
				if(check[j/100000]!=-1)
				{
					if(check[j/100000]==i)
					{
						if(left[j/100000]>=1)
						{
							long long int s = next(b*(j/100000));
							if(s>e) continue;
							if(check[s/100000]==-1)
							{
								check[s/100000] = i;
								left[s/100000] = left[j/100000] -1;
							}
						}
					}
					else
					{
						long long int s = next(b*(j/100000));
						if(s>e) continue;
						if(check[s/100000]==-1)
						{
							check[s/100000] = i;
							left[s/100000] = c-1;
						}
					}
				}
			}
		}
	}
	
	for(long long int i=1;i<=e/100000;i++) printf("%d ",check[i]);
}