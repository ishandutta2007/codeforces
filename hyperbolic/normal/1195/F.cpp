#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

struct str{
	int first;
	int second;
	int index;
	int ans;
}query[100010];
bool cmp(str a, str b)
{
	if((a.first/330)==(b.first/330)) return a.second<b.second;
	return (a.first/330)<(b.first/330);
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}
long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
std::pair<int,int> P[300010];
std::vector< std::pair<long long int,long long int> > V[100010],index;
std::map< std::pair<long long int,long long int> , int> hash;
std::vector<int> V2[100010];

int count[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=b;j++) scanf("%d%d",&P[j].first,&P[j].second);
		P[b+1] = P[1];
		for(int j=1;j<=b;j++)
		{
			long long int s = P[j+1].first - P[j].first;
			long long int t = P[j+1].second - P[j].second;
			long long int g = gcd(abs(s),abs(t));
			s/=g;
			t/=g;
			V[i].push_back(std::make_pair(s,t));
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=0;j<V[i].size();j++) index.push_back(V[i][j]);
	
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=1;i<=index.size();i++) hash[index[i-1]] = i;
	
	for(int i=1;i<=a;i++) for(int j=0;j<V[i].size();j++) V2[i].push_back(hash[V[i][j]]);
	
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i]={c,d,i,-1};
	}
	std::sort(query+1,query+b+1,cmp);
	
	int s = 1, t = 1;
	int C = 0;
	for(int j=0;j<V2[1].size();j++)
	{
		count[V2[1][j]]++;
		if(count[V2[1][j]]==1) C++;
	}
	
	for(int i=1;i<=b;i++)
	{
		int L = query[i].first;
		int R = query[i].second;
		while(t<R)
		{
			for(int j=0;j<V2[t+1].size();j++)
			{
				count[V2[t+1][j]]++;
				if(count[V2[t+1][j]]==1) C++;
			}
			t++;
		}
		while(t>R)
		{
			for(int j=0;j<V2[t].size();j++)
			{
				count[V2[t][j]]--;
				if(count[V2[t][j]]==0) C--;
			}
			t--;
		}
		
		while(s>L)
		{
			for(int j=0;j<V2[s-1].size();j++)
			{
				count[V2[s-1][j]]++;
				if(count[V2[s-1][j]]==1) C++;
			}
			s--;
		}
		while(s<L)
		{
			for(int j=0;j<V2[s].size();j++)
			{
				count[V2[s][j]]--;
				if(count[V2[s][j]]==0) C--;
			}
			s++;
		}
		query[i].ans = C;
	}
	std::sort(query+1,query+b+1,cmp2);
	
	for(int i=1;i<=b;i++) printf("%d\n",query[i].ans);
}