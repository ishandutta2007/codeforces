#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 123456789

struct segTree{
	long long int value[4000010];
	long long int lazy[4000010];
	void add(int L, int R, long long int val, int l=1, int r=1000000, int v=1)
	{
		if(L>R) return;
		if(L<=l&&r<=R)
		{
			value[v] += val;
			lazy[v] += val;
		}
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
			add(L,R,val,l,h,2*v);
			add(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long long int getMin(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return -1;
		else if(R<l) return -1;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			long long int s1 = getMin(L,R,l,h,2*v);
			long long int s2 = getMin(L,R,h+1,r,2*v+1);
			if(s1==-1) return s2;
			if(s2==-1) return s1;
			return s1<s2?s1:s2;
		}
	}
}T;

int x[500010],check[500010];
std::vector<int> index;
std::map<int,int> hash;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[i] -= i;
	
	for(int i=1;i<=a;i++) index.push_back(x[i]);
	index.push_back(0);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		check[c] = 1;
	}
	
	for(int i=1;i<=a;i++)
	{
		int k = hash[x[i]];
		long long int temp = T.getMin(1,k);
		T.add(1,1000000,1);
		long long int temp2 = T.getMin(k,k);
		T.add(k,k,temp-temp2);
		if(check[i]==1)
		{
			T.add(1,hash[x[i]]-1,MAX);
			T.add(hash[x[i]]+1,1000000,MAX);
		}
		long long int ans = T.getMin(1,1000000);
	}
	long long int ans = T.getMin(1,1000000);
	if(ans>=MAX) printf("-1");
	else printf("%lld",ans);
}