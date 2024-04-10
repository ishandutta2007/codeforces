#include <stdio.h>
#include <vector>
#include <map>

int a,b;
long long int make(long long int s, long long int t)
{
	std::vector<int> V;
	for(int i=0;i<b;i++)
	{
		if(s%3==t%3) V.push_back(s%3);
		else V.push_back(3-s%3-t%3);
		s/=3, t/=3;
	}
	long long int sum = 0;
	for(int i=V.size()-1;i>=0;i--) sum*=3, sum+=V[i];
	return sum;
}

std::map<long long int,int> M;
int count[1010];
long long int x[1010];
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		for(int j=1;j<=b;j++)
		{
			int c;
			scanf("%d",&c);
			sum*=3, sum+=c;
		}
		x[i] = sum;
	}
	
	for(int i=a;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			long long int v = make(x[j],x[i]);
			if(M.find(v)!=M.end())
			{
				int w = M[v];
				count[j]++, count[i]++, count[w]++;
			}
		}
		M[x[i]] = i;
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) ans += count[i]*(count[i]-1)/2;
	printf("%lld",ans);
}