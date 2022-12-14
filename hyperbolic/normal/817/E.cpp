#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

struct segTree{
	int value[400010];
	void addValue(int ind, int val, int l=1,int r=100002, int v=1)
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
	int getSum(int L,int R, int l=1, int r=100002, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h =(l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;


std::vector<int> index;
std::map<int,int> hash;

int func(int s, int t)
{
	std::map<int,int> ::iterator it, it2;
	it = hash.lower_bound(s);
	it2 = hash.upper_bound(t), it2--;
	int a = (it->second);
	int b = (it2->second);
	if(a>b) return 0;
	else return T.getSum(a,b);
}

struct str{
	int first;
	int second;
	int third;
}query[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d",&b);
		if(b!=3)
		{
			scanf("%d",&c);
			query[i] = {b,c,-1};
			index.push_back(c);
		}
		else
		{
			scanf("%d%d",&c,&d);
			query[i] = {b,c,d};
		}
	}
	index.push_back(0);
	index.push_back(1000000001);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<=a;i++)
	{
		if(query[i].first==1) T.addValue(hash[query[i].second],1);
		else if(query[i].first==2) T.addValue(hash[query[i].second],-1);
		else
		{
			int b = query[i].second, c = query[i].third;
			int sum = 0, ans = 0;
			
			for(int j=29;j>=0;j--)
			{
				int h = (1<<j);
				if((b&h)==0 && (c&h)==0);
				if((b&h)==0 && (c&h)!=0) ans += func(sum,sum+h-1), sum+=h;
				if((b&h)!=0 && (c&h)==0) sum += h;
				if((b&h)!=0 && (c&h)!=0) ans += func(sum+h,sum+2*h-1);
			}
			printf("%d\n",ans);
		}
	}
}