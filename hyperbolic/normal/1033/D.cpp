#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define MAX 2000000000
#define MOD 998244353

long long int sqrt(long long int k)
{
	long long int min = 1, max = MAX;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		if(h*h==k) return h;
		else if(h*h>k) max = h-1;
		else if(h*h<k) min = h+1;
	}
	return -1;
}

long long int cubic(long long int k)
{
	long long int min = 1, max = 2000000;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		if(h*h*h==k) return h;
		else if(h*h*h>k) max = h-1;
		else if(h*h*h<k) min = h+1;
	}
	return -1;
}

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}


std::map<long long int,int> M,M2;
std::multiset<long long int> S;
std::queue<long long int> Q,save;
std::vector<long long int> V;
int check[510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		long long int p = sqrt(b);
		if(p==-1)
		{
			long long int p2 = cubic(b);
			if(p2==-1) S.insert(b);
			else
			{
				M[p2]+=3;
				Q.push(p2);
			}
		}
		else
		{
			long long int p2 = sqrt(p);
			if(p2==-1)
			{
				M[p]+=2;
				Q.push(p);
			}
			else
			{
				M[p2]+=4;
				Q.push(p2);
			}
		}
	}
	
	while(!Q.empty())
	{
		long long int p = Q.front();
		Q.pop();
		std::set<long long int> ::iterator it;
		for(it=S.begin();it!=S.end();it++)
		{
			if((*it)%p==0)
			{
				M[p]++;
				M[(*it)/p]++;
				Q.push((*it)/p);
			}
			else save.push(*it);
		}
		S.clear();
		while(!save.empty()) S.insert(save.front()),save.pop();
	}
	
	for(std::set<long long int> ::iterator it=S.begin();it!=S.end();it++) V.push_back((*it));
	
	int count = 0;
	for(int i=0;i<V.size();i++)
	{
		for(int j=0;j<V.size();j++)
		{
			if(i==j) continue;
			long long int c = gcd(V[i],V[j]);
			if(c>1&&c<V[i])
			{
				M[c]++;
				M[V[i]/c]++;
				goto u;
			}
		}
		M2[V[i]]++;
		u:;
	}
	
	long long int ans = 1;
	std::map<long long int,int> ::iterator it;
	for(it=M.begin();it!=M.end();it++)
	{
		int c = (it->second);
		ans *= (c+1);
		ans %= MOD;
	}
	for(it=M2.begin();it!=M2.end();it++)
	{
		int c = (it->second);
		ans *= (c+1)*(c+1);
		ans %= MOD;
	}
	printf("%lld",ans);
}