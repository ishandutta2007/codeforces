#include <stdio.h>
#include <vector>
#include <string.h>
#define MOD 998244353

std::vector<int> V[20];
std::vector<int> V2[100010];
char x[100010];

long long int sum[20][20];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		V[b].push_back(i);
		
		for(int j=1;j<=b;j++) V2[i].push_back(x[j]-'0');
	}
	
	for(int i=1;i<=10;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			for(int k=1;k<=i;k++)
			{
				sum[i][k] += V2[V[i][j]][k-1];
				sum[i][k] %= MOD;
			}
		}
	}
	
	long long int ans = 0;
	for(int c=1;c<=10;c++)
	{
		for(int d=1;d<=10;d++)
		{
			if(c>=d)
			{
				long long int S = 0;
				long long int k = 10;
				for(int i=c;i>=c-d+2;i--)
				{
					S += sum[c][i]*k, S%=MOD;
					k*=100, k%=MOD;
				}
				for(int i=c-d+1;i>=1;i--)
				{
					S += sum[c][i]*k, S%=MOD;
					k*=10, k%=MOD;
				}
				ans += S*V[d].size(), ans%=MOD;
				
				S = 0;
				k = 1;
				for(int i=d;i>=1;i--)
				{
					S += sum[d][i]*k, S%=MOD;
					k*=100, k%=MOD;
				}
				ans += S*V[c].size(), ans%=MOD;
			}
			else
			{
				long long int S = 0;
				long long int k = 10;
				for(int i=c;i>=1;i--)
				{
					S += sum[c][i]*k, S%=MOD;
					k*=100, k%=MOD;
				}
				ans += S*V[d].size(), ans%=MOD;
				
				S = 0;
				k = 1;
				for(int i=d;i>=d-c+1;i--)
				{
					S += sum[d][i]*k, S%=MOD;
					k*=100, k%=MOD;
				}
				for(int i=d-c;i>=1;i--)
				{
					S += sum[d][i]*k, S%=MOD;
					k*=10, k%=MOD;
				}
				ans += S*V[c].size(), ans%=MOD;
			}
		}
	}
	printf("%lld",ans);
}