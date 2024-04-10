#include <stdio.h>
#include <vector>
#include <map>

struct str{
	long long int value[800010];
	void addValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			return getSum(L,R,l,h,2*v)+getSum(L,R,h+1,r,2*v+1);
		}
	}
}T1,T2,T3;

std::pair<int,int> P[200010];
std::map<int,int> M,hash;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = std::make_pair(b,c);
	}
	for(int i=1;i<=a;i++) if(P[i].second>0) M[P[i].second] = 1;
	int C = 1;
	for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
	{
		hash[it->first] = C++;
	}
	
	long long int S = 0;
	for(int i=1;i<=a;i++)
	{
		S+=P[i].second;
		if(P[i].first==0)
		{
			if(P[i].second>0)
			{
				T1.addValue(hash[P[i].second],P[i].second);
				T3.addValue(hash[P[i].second],1);
			}
			else
			{
				T1.addValue(hash[-P[i].second],P[i].second);
				T3.addValue(hash[-P[i].second],-1);
			}
		}
		else
		{
			if(P[i].second>0)
			{
				T1.addValue(hash[P[i].second],P[i].second);
				T2.addValue(hash[P[i].second],1);
			}
			else
			{
				T1.addValue(hash[-P[i].second],P[i].second);
				T2.addValue(hash[-P[i].second],-1);
			}
		}
		
		int size = T2.getSum(1,a);
		if(size==0)
		{
			printf("%lld\n",S);
			continue;
		}
		
		int min = 1, max = a;
		int k = a+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T2.getSum(h,a)+T3.getSum(h,a)<=size-1)
			{
				k = h;
				max = h-1;
			}
			else min = h+1;
		}
		long long int ans = T1.getSum(k,a);
		
		
		if(T2.getSum(k-1,a)==size)
		{
			int min = 1, max = k-1;
			int t = -1;
			
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T3.getSum(h,k-1)>=1)
				{
					t = h;
					min = h+1;
				}
				else max = h-1;
			}
			if(t==-1) printf("%lld\n",S+T1.getSum(k,a));
			else printf("%lld\n",S+T1.getSum(k,a)+T1.getSum(t,t));
		}
		else printf("%lld\n",S+T1.getSum(k-1,a));
	}
}