#include <stdio.h>
#include <vector>
#define MAX 123456789

struct segTree{
	std::pair<int,int> value[1000010];
	void setValue(int ind, std::pair<int,int> val, int l=1, int r=250000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			if(value[2*v].first < value[2*v+1].first) value[v] = value[2*v];
			else value[v] = value[2*v+1];
		}
	}
	std::pair<int,int> getMin(int L, int R, int l=1, int r=250000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return std::make_pair(MAX,0);
		else if(R<l) return std::make_pair(MAX,0);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> P1 = getMin(L,R,l,h,2*v);
			std::pair<int,int> P2 = getMin(L,R,h+1,r,2*v+1);
			if(P1.first<P2.first) return P1;
			else return P2;
		}
	}
}T1,T2;

int func(int s, int t)
{
	if(s==t) return 0;
	int x1 = T1.getMin(s,t).second;
	int x2 = T2.getMin(s,t).second;
	if(x1>x2)
	{
		int temp = x2;
		x2 = x1;
		x1 = temp;
	}
	
	return func(s,x1) + 1 + func(x2,t);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			T1.setValue(i,std::make_pair(b,i));
			T2.setValue(i,std::make_pair(-b,i));
		}
		printf("%d\n",func(1,a));
	}
}