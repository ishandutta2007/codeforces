#include <stdio.h>
#include <vector>

int x[200010],y[200010];
int check[200010];
int S1[200010],S2[200010],S3[200010];

std::vector<int> prime;
int main()
{
	for(int i=2;i<=200000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=200000;j+=i) check[j] = 1;
		}
	}
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=200000;i++) S1[i] = S2[i] = 20;
	
	for(int i=1;i<=a;i++)
	{
		int s = x[i];
		for(int j=0;j<prime.size() && prime[j]*prime[j]<=x[i];j++)
		{
			int count = 0;
			while(s%prime[j]==0)
			{
				count++;
				s/=prime[j];
			}
			if(count==0) continue;
			
			S3[prime[j]]++;
			if(S1[prime[j]] > count)
			{
				S2[prime[j]] = S1[prime[j]];
				S1[prime[j]] = count;
			}
			else if(S2[prime[j]]>count) S2[prime[j]] = count;
		}
		if(s>1)
		{
			S3[s]++;
			if(S1[s] > 1)
			{
				S2[s] = S1[s];
				S1[s] = 1;
			}
			else if(S2[s] > 1) S2[s] = 1;
		}
	}

	long long int ans = 1;
	for(int i=0;i<prime.size();i++)
	{
		if(S3[prime[i]]==a) for(int j=1;j<=S2[prime[i]];j++) ans *= prime[i];
		else if(S3[prime[i]]==a-1) for(int j=1;j<=S1[prime[i]];j++) ans *= prime[i];
	}
	
	printf("%lld",ans);
}