#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

std::vector< std::pair<long long int, long long int> > V[200010];
std::vector< std::pair<long long int, long long int> > index;
std::map< std::pair<long long int, long long int> , int> hash;

std::vector< std::pair<int,int> > V2[400010];
std::vector< std::pair<int,int> > ans;
int check[400010],height[400010];

int func(int k, int prev, int h)
{
	check[k] = 1;
	height[k] = h;
	int p = -1;
	for(int i=0;i<V2[k].size();i++)
	{
		if(V2[k][i].first==prev)
		{
			p = i;
			break;
		}
	}
	
	std::vector<int> temp;
	for(int i=0;i<V2[k].size();i++)
	{
		if(i==p) continue;
		if(check[V2[k][i].first]==1)
		{
			if(height[V2[k][i].first]<height[k]) temp.push_back(V2[k][i].second);
		}
		else
		{
			int t = func(V2[k][i].first,k,h+1);
			if(t==1) temp.push_back(V2[k][i].second);
		}
	}
	
	if(temp.size()%2==0)
	{
		for(int i=0;i+1<temp.size();i+=2) ans.push_back({temp[i],temp[i+1]});
		return 1;
	}
	else if(prev==0)
	{
		temp.pop_back();
		for(int i=0;i+1<temp.size();i+=2) ans.push_back({temp[i],temp[i+1]});
		return 1;
	}
	else
	{
		temp.push_back(V2[k][p].second);
		for(int i=0;i+1<temp.size();i+=2) ans.push_back({temp[i],temp[i+1]});
		return 0;
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c,d,e;
		scanf("%lld%lld%lld%lld",&b,&c,&d,&e);
		// s/t
		long long int s = b*e;
		long long int t = c*d;
		
		long long int g = gcd(s+c*e,t);
		V[i].push_back({(s+c*e)/g,t/g});
		index.push_back({(s+c*e)/g,t/g});
		
		g = gcd(s,t+c*e);
		V[i].push_back({s/g,(t+c*e)/g});
		index.push_back({s/g,(t+c*e)/g});		
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	int b = index.size();
	
	
	for(int i=1;i<=a;i++)
	{
		int s = hash[V[i][0]];
		int t = hash[V[i][1]];
		//printf("%d : %d %d!!\n",i,s,t);
		V2[s].push_back({t,i});
		V2[t].push_back({s,i});
	}
	
	for(int i=1;i<=b;i++)
	{
		if(check[i]==0)
		{
			func(i,0,1);
		}
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}