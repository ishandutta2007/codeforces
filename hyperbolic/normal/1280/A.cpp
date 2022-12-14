#include <stdio.h>
#include <string.h>
#define MOD 1000000007
char x[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		long long int L = strlen(x+1);
		int control = 0;
		for(int i=1;i<=a;i++)
		{
			if(control==1)
			{
				L += (L-i+MOD)*(x[i]-'0'-1);
				L %= MOD;
			}
			else
			{
				long long int p = L+1;
				for(int j=1;j<=(x[i]-'0'-1);j++)
				{
					for(int k=i+1;k<=L;k++)
					{
						if(p>a)
						{
							control = 1;
							goto u;
						}
						x[p++] = x[k];
					}
				}
				
				u:;
				L += (L-i+MOD)*(x[i]-'0'-1);
				L %= MOD;
			}
		}
		printf("%lld\n",L);
	}
}