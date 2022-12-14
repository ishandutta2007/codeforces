#include <stdio.h>
#include <vector>
#include <stack>
#define MIN -(long long int)1e16

struct segTree{
	long long int value[1200010];
	long long int lazy[1200010];
	void add(int L, int R, long long int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			add(L,R,val,l,h,2*v);
			add(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;


std::pair<int,int> P[300010];
std::stack< std::pair<long long int,int> > Q;
long long int value[300010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		ans = ans>b-d?ans:b-d;
		P[i] = std::make_pair(c,d);
	}
	
	for(int i=1;i<a;i++) value[i] = (long long int)(P[i+1].first-P[i].first)*(P[i+1].first-P[i].first);
	
	T.add(a,a,b-P[a].second);
	for(int i=a-1;i>=1;i--)
	{
		while(!Q.empty())
		{
			std::pair<long long int,int> P = Q.top();
			if(P.first<value[i])
			{
				Q.pop();
				if(Q.empty())
				{
					T.add(P.second,a,P.first-value[i]);
					break;
				}
				else T.add(P.second,Q.top().second-1,P.first-value[i]);
			}
			else break;
		}
		T.add(i+1,i+1,-value[i]);
		Q.push(std::make_pair(value[i],i+1));
		T.add(i,a,b-P[i].second);
		
		long long int t = T.getMax(i+1,a);
		ans = ans>t?ans:t;
	}
	printf("%lld",ans);
}