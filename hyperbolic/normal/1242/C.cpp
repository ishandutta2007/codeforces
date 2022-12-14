#include <stdio.h>
#include <vector>
#include <map>

long long  a;
std::vector< std::pair<long long ,long long > > save[20];
long long  sum = 0;
long long  x[20];
std::map<long long ,long long > hash;
std::pair<long long ,long long > ans[20];

long long  check2[20][1000010];
long long  func(long long  k, long long  bit)
{
	if(k>a) return 1;
	if((bit&(1<<(k-1)))!=0) return func(k+1,bit);
	if(check2[k][bit]==1) return 0;
	
	for(long long  i=0;i<save[k].size();i++)
	{
		if((bit&save[k][i].first)!=0) continue;
		long long  t = func(k+1,bit+save[k][i].first);
		if(t==1)
		{
			long long  val = save[k][i].second;
			while(1)
			{
				long long  next = sum-(x[hash[val]] - val);
				//prlong long f("%lld %lld %d %d!!\n",val,next, hash[val], hash[next]);
				ans[hash[next]] = {next,hash[val]};
				if(next==save[k][i].second)
				{
					ans[hash[save[k][i].second]] = {save[k][i].second,hash[val]};
					break;
				}
				else val = next;
			}
			return 1;
		}
	}
	check2[k][bit] = 1;
	return 0;
}

long long  check[20];
std::vector<long long > V[20];

int main()
{
	scanf("%lld",&a);
	for(long long  i=1;i<=a;i++)
	{
		long long  b;
		scanf("%lld",&b);
		for(long long  j=1;j<=b;j++)
		{
			long long  c;
			scanf("%lld",&c);
			V[i].push_back(c);
		}
	}
	
	
	for(long long  i=1;i<=a;i++) for(long long  j=0;j<V[i].size();j++) sum += V[i][j];
	if(sum%a!=0)
	{
		printf("No");
		return 0;
	}
	sum/=a;
	for(long long  i=1;i<=a;i++) for(long long  j=0;j<V[i].size();j++) hash[V[i][j]] = i;
	for(long long  i=1;i<=a;i++) for(long long  j=0;j<V[i].size();j++) x[i] += V[i][j];
	
	for(long long  i=1;i<=a;i++)
	{
		for(long long  j=0;j<V[i].size();j++)
		{
			for(long long  k=1;k<=a;k++) check[k] = 0;
			long long  val = V[i][j];
			check[i] = 1;
			long long  S = 0;
			while(1)
			{
				long long  next = sum-(x[hash[val]] - val);
				
				if(next==V[i][j]) break;
				else if(check[hash[next]]==1) goto u;
				else
				{
					check[hash[next]] = 1;
					val = next;
				}
			}
			
			for(long long  k=1;k<=a;k++) S += check[k] * (1<<(k-1));
			save[i].push_back(std::make_pair(S,V[i][j]));
			u:;
		}
	}
	
	if(func(1,0))
	{
		printf("Yes\n");
		for(long long  i=1;i<=a;i++) printf("%lld %lld\n",ans[i].first,ans[i].second);
	}
	else printf("No");
}