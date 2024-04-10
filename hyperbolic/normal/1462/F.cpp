#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

struct segTree{
	int value[1600010];
	int addValue(int ind, int val, int l=1, int r=400000, int v=1)
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
	int getValue(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getValue(L,R,l,h,2*v);
			int s2 = getValue(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

std::vector<int> index;
std::map<int,int> hash;
std::pair<int,int> P[200010];

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
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			P[i] = std::make_pair(b,c);
			index.push_back(b);
			index.push_back(c);
		}
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		std::sort(P+1,P+a+1);
		int ans = a;
		for(int i=1;i<=a;i++)
		{
			T.addValue(hash[P[i].second],1);
			
			int l = 1, r = a;
			int p = a+1;
			while(l<=r)
			{
				int h = (l+r)/2;
				if(P[h].first>P[i].second)
				{
					p = h;
					r = h-1;
				}
				else l = h+1;
			}
			
			int k = (a-p+1) + T.getValue(1,hash[P[i].first]-1);
			ans = ans<k?ans:k;
		}
		printf("%d\n",ans);
		
		for(int i=1;i<=2*a;i++) T.addValue(i,-T.getValue(i,i));
	}
}