#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	int value[4000010];
	void setValue(int ind, int val, int l=0, int r=1000000,int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L,int R, int l=0, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;


struct str{
	int x0;
	int y1;
	int y2;
};
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}

std::vector<str> V;
std::vector< std::pair<int,int> > query[1000010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(d==0&&e==1000000) ans++;
		query[d].push_back(std::make_pair(c,1));
		query[e+1].push_back(std::make_pair(c,0));
	}
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(d==0&&e==1000000) ans++;
		V.push_back({c,d,e});
	}
	std::sort(V.begin(),V.end(),cmp);
	
	int p = 0;
	for(int i=0;i<V.size();i++)
	{
		while(1)
		{
			if(p>V[i].x0) break;
			for(int j=0;j<query[p].size();j++) T.setValue(query[p][j].first,query[p][j].second);
			p++;
		}
		ans += T.getSum(V[i].y1,V[i].y2);
	}
	printf("%lld",ans);
}