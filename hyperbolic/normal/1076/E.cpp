#include <stdio.h>
#include <vector>
#include <map>

struct segTree{
	long long int value[1200010];
	void addValue(int ind, long long int val, int l=1, int r=300000, int v=1)
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
	long long int getSum(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

int a;
long long int ans[300010];
std::vector<int> V[300010];
int height[300010];
void init(int k, int prev, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		init(V[k][i],k,h+1);
	}
}

std::map<int,long long int> M[300010];
void func(int k, int prev)
{
	for(std::map<int,long long int> ::iterator it = M[k].begin();it!=M[k].end();it++) T.addValue(it->first,it->second);
	ans[k] = T.getSum(height[k],a);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k);
	}
	for(std::map<int,long long int> ::iterator it = M[k].begin();it!=M[k].end();it++) T.addValue(it->first,-(it->second));
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	init(1,0,1);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		int f = height[c]+d;
		if(f>a) f = a;
		M[c][f] += e;
	}
	func(1,0);
	
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}