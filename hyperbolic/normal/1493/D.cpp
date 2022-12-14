#include <stdio.h>
#include <vector>
#include <map>
#define MOD 1000000007

std::vector<int> prime;
int check[1010];
std::map<int,int> M[200010],M2[200010];
int start[200010];

int main()
{
	for(int i=2;i<=500;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=500;j+=i) check[j] = 1;
		}
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=2;i<=200000;i++) M2[i][0] = a;
	for(int i=2;i<=200000;i++) start[i] = 1;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		for(int k=0;k<prime.size();k++)
		{
			int j = prime[k];
			while(c%j==0)
			{
				M[j][i]++;
				M2[j][M[j][i]]++;
				c/=j;
			}
		}
		if(c>1)
		{
			M[c][i]++;
			M2[c][M[c][i]]++;
		}
	}
	
	long long int ans = 1;
	for(int i=2;i<=200000;i++)
	{
		while(1)
		{
			if(M2[i][start[i]]==a)
			{
				ans *= i, ans %= MOD;
				start[i]++;
			}
			else break;
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		for(int k=0;k<prime.size();k++)
		{
			int j = prime[k];
			while(d%j==0)
			{
				M[j][c]++;
				M2[j][M[j][c]]++;
				d/=j;
			}
			while(1)
			{
				if(M2[j][start[j]]==a)
				{
					ans *= j, ans %= MOD;
					start[j]++;
				}
				else break;
			}
		}
		if(d>1)
		{
			M[d][c]++;
			M2[d][M[d][c]]++;
			while(1)
			{
				if(M2[d][start[d]]==a)
				{
					ans *= d, ans %= MOD;
					start[d]++;
				}
				else break;
			}
		}
		printf("%lld\n",ans);
	}
	
}