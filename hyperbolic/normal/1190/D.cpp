#include <stdio.h>
#include <algorithm>
#include <vector>

struct segTree{
	int value[800010];
	void update(int k)
	{
		value[k] = value[2*k]+value[2*k+1];
	}
	void set(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = 1;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) set(ind,l,h,2*v);
			else set(ind,h+1,r,2*v+1);
			update(v);
		}
	}
	int sum(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			return sum(L,R,l,h,2*v)+sum(L,R,h+1,r,2*v+1);
		}
	}
}T;

struct str{
	int x0;
	int x1;
	int y0;
}x[200010];
bool cmp1(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	if(a.y0==b.y0) return a.x0<b.x0;
	return a.y0>b.y0;
}

std::vector<int> V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]={b,0,c};
	}
	std::sort(x+1,x+a+1,cmp1);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i].x0!=x[i-1].x0) count++;
		x[i].x1 = count;
	}
	std::sort(x+1,x+a+1,cmp2);
	
	long long int ans = 0;
	V.push_back(0);
	for(int i=1;i<=a;i++)
	{
		if(x[i].y0<x[i-1].y0)
		{
			for(int j=1;j<V.size();j++)
			{
				long long int s1 = T.sum(V[j-1]+1,V[j]);
				long long int s2 = T.sum(V[j],a);
				ans += s1*s2;
			}
			V.clear(), V.push_back(0);
		}
		V.push_back(x[i].x1);
		T.set(x[i].x1);
	}
	for(int j=1;j<V.size();j++)
	{
		long long int s1 = T.sum(V[j-1]+1,V[j]);
		long long int s2 = T.sum(V[j],a);
		ans += s1*s2;
	}
	printf("%lld",ans);
}