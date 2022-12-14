#include <stdio.h>

long long int power(long long int a, int b)
{
	long long int ans = 1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}

int count[20000010];
int main()
{
	for(int i=2;i<=20000000;i++) if(count[i]==0) for(int j=i;j<=20000000;j+=i) count[j]++;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		long long int ans = 0;
		for(int i=1;i*i<=c;i++)
		{
			if(c%i==0)
			{
				int d = (c/i)+b;
				if(d%a==0) ans += power(2,count[d/a]);
				if(i*i!=c)
				{
					d = (i)+b;
					if(d%a==0) ans += power(2,count[d/a]);
				}
			}
		}
		printf("%lld\n",ans);
	}
}