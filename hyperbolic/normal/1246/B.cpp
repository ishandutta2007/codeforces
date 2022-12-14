#include <stdio.h>
#include <map>
#define MAX (long long int)1e10

std::map<long long int,int> count;
int x[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(b==2)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=400;j>=1;j--)
			{
				if(x[i]%(j*j)==0)
				{
					x[i] /= (j*j);
					break;
				}
			}
		}
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			ans += count[x[i]];
			count[x[i]]++;
		}
		printf("%lld",ans);
	}
	else
	{
		long long int ans =0;
		for(int i=1;i<=a;i++)
		{
			long long int C = 1;
			for(int j=50;j>=1;j--)
			{
				long long int C = 1;
				for(int k=1;k<=b;k++)
				{
					if(C*j>MAX) goto u;
					C*=j;
				}
				if(x[i]%C==0)
				{
					x[i]/=C;
					break;
				}
				u:;
			}
			
			long long int s = x[i];
			long long int t = 1;
			
			for(int j=2;j<=400;j++)
			{
				if(s%j==0)
				{
					int count = 0;
					while(s%j==0) s/=j, count++;
					for(int k=1;k<=b-count;k++)
					{
						if(t*j>MAX) goto v;
						t*=j;
					}
				}
			}
			if(s>0)
			{
				for(int k=1;k<=b-1;k++)
				{
					if(t*s>MAX) goto v;
					t*=s;
				}
			}
			ans += count[t];
			count[x[i]]++;
			v:;
		}
		printf("%lld",ans);
	}
}