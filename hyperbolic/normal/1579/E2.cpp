#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

struct segTree{
	int value[800010];
	void addValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

int x[200010];
std::vector<int> index;
std::map<int,int> hash;

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
		for(int i=1;i<=a;i++) T.addValue(i,-T.getSum(i,i));
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int t = hash[x[i]];
			int s1 = T.getSum(1,t-1);
			int s2 = T.getSum(t+1,a);
			ans += (s1<s2?s1:s2);
			T.addValue(t,1);
		}
		printf("%lld\n",ans);
	}
}