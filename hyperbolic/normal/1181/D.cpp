#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector< std::pair<long long int,long long int> > time1,time2;
int ans[500010];
int count[500010];

struct segTree{
	int value[2000010];
	int lazy[2000010];
	void addValue(int L, int R, int val, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] > value[2*v+1] ? value[2*v] : value[2*v+1];
		}
	}
	
	int lowerbound(int val, int l=1, int r=500000, int v=1)
	{
		if(value[v]<val) return r+1;
		else if(l==r) return r;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			
			int s1 = lowerbound(val,l,h,2*v);
			if(s1==h+1) return lowerbound(val,h+1,r,2*v+1);
			else return s1;
		}
	}
}T;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		count[d]++;
	}
	for(int i=1;i<=b;i++) time1.push_back(std::make_pair(count[i]+1,i));
	
	for(int i=1;i<=c;i++)
	{
		long long int d;
		scanf("%lld",&d);
		time2.push_back(std::make_pair(d,i));
	}
	
	std::sort(time1.begin(),time1.end());
	std::sort(time2.begin(),time2.end());
	
	long long int sum = a;
	int C = 0;
	int h = 1, p = 0;
	
	for(int i=0;i<time2.size();i++)
	{
		int s = time2[i].second;
		long long int t = time2[i].first;
		while(h<=500000)
		{
			while(p<time1.size()&&time1[p].first<=h)
			{
				T.addValue(time1[p].second,b,1);
				C++;
				p++;
			}
			if(sum+C<t)
			{
				sum += C;
				h++;
			}
			else
			{
				ans[s] = T.lowerbound(t-sum);
				goto u;
			}
		}
		
		ans[s] = (t-sum-1)%b+1;
		u:;
	}
	for(int i=1;i<=c;i++) printf("%d\n",ans[i]);
}