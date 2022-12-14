#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 12345678


struct segTree{
	int value[2400010];
	int lazy[2400010];
	void setValue(int L, int R, int val, int l=0, int r=600000,int v=1)
	{
		if(L<=l&&r<=R) value[v] = val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getValue(int ind, int l=0, int r=600000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T[2];

int x[300010];
long long int y[300010];
std::vector<long long int> index;
std::map<long long int,int> hash;
std::vector<int> save[2][600010];

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		index.clear();
		hash.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) y[i] = x[i] - y[i-1];
		for(int i=0;i<=a;i++) index.push_back(y[i]);
		for(int i=0;i<=a;i++) index.push_back(-y[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		
		int n = index.size();
		for(int i=0;i<n;i++) hash[index[i]] = i+1;
		T[0].setValue(0,n,MAX);
		T[1].setValue(0,n,MAX);
		
		long long int ans = 0;
		for(int i=a;i>=1;i--)
		{
			int t = hash[y[i]];
			T[i%2].setValue(t,n,i);
			save[i%2][t].push_back(i);
			
			t = hash[y[i-1]];
			int limit1 = T[(i+1)%2].getValue(t-1);
			
			t = hash[-y[i-1]];
			int limit2 = T[i%2].getValue(t-1);
			
			int limit = limit1<limit2?limit1:limit2;
			
			t = hash[y[i-1]];
			int min = 0, max = save[(i+1)%2][t].size();
			int p1 = 0;
			max--;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(save[(i+1)%2][t][h]<limit)
				{
					p1 = (save[(i+1)%2][t].size()-1) - h + 1;
					max = h-1;
				}
				else min = h+1;
			}
			ans += p1;
			
			t = hash[-y[i-1]];
			min = 0, max = save[i%2][t].size();
			int p2 = 0;
			max--;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(save[i%2][t][h]<limit)
				{
					p2 = (save[i%2][t].size()-1) - h + 1;
					max = h-1;
				}
				else min = h+1;
			}
			ans += p2;
		}
		for(int i=0;i<=a;i++) save[i%2][hash[y[i]]].clear();
		
		printf("%lld\n",ans);
	}
}