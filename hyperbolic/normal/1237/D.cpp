#include <stdio.h>
#include <vector>
#include <algorithm>

struct segTree{
	int value[1200010];
	void setValue(int ind, int val, int l=1, int r=300000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 12345678;
		else if(r<L) return 12345678;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

int DP[300010],next[300010],x[300010];
std::vector< std::pair<int,int> > V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a+1;i<=3*a;i++) x[i] = x[i-a];
	
	int max = x[a];
	for(int i=a+1;i<=3*a;i++)
	{
		if(2*x[i]<max)
		{
			DP[a] = i;
			goto u;
		}
		max = max>x[i]?max:x[i];
	}
	
	for(int i=1;i<=a;i++) printf("-1 ");
	return 0;
	u:;
	
	for(int i=1;i<=a;i++) V.push_back(std::make_pair(x[i],i));
	std::sort(V.begin(),V.end());
	for(int i=1;i<=3*a;i++) T.setValue(i,12345678);
	
	int p = 0;
	for(int i=0;i<V.size();i++)
	{
		while(p<V.size() && 2*V[i].first>=V[p].first)
		{
			int k = T.getMin(V[p].second+1,V[p].second+a-1);
			next[V[p].second] = k;
			p++;
		}
		T.setValue(V[i].second,V[i].second);
		T.setValue(V[i].second+a,V[i].second+a);
		T.setValue(V[i].second+2*a,V[i].second+2*a);
	}
	
	for(int i=a-1;i>=1;i--) DP[i] = next[i]<DP[i+1]?next[i]:DP[i+1];
	for(int i=1;i<=a;i++) printf("%d ",DP[i]-i);
}