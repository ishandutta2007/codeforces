#include <stdio.h>
#include <algorithm>

struct segTree{
	int value[4000010];
	void setValue(int L, int R, int val, int l=0, int r=1000001, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1) value[2*v] = value[v], value[2*v+1] = value[v], value[v] = -1;
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=0, int r=1000001, int v=1)
	{
		if(value[v]!=-1) return value[v];
		else
		{
			int h = (l+r)/2;
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T1,T2;

std::pair<int,int> x[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		x[i] = std::make_pair(b,i);
	}
	std::sort(x+1,x+a+1);
	
	long long int ans = 0;
	T1.setValue(1,a,0);
	T2.setValue(1,a,a+1);
	
	for(int i=1;i<=a;i++)
	{
		int L = T1.getValue(x[i].second)+1;
		int R = T2.getValue(x[i].second)-1;
		ans -= (long long int)x[i].first * (x[i].second-L+1) * (R-x[i].second+1);
		T1.setValue(x[i].second,R,x[i].second);
		T2.setValue(L,x[i].second,x[i].second);
	}
	
	T1.setValue(1,a,0);
	T2.setValue(1,a,a+1);
	for(int i=a;i>=1;i--)
	{
		int L = T1.getValue(x[i].second)+1;
		int R = T2.getValue(x[i].second)-1;
		ans += (long long int)x[i].first * (x[i].second-L+1) * (R-x[i].second+1);
		T1.setValue(x[i].second,R,x[i].second);
		T2.setValue(L,x[i].second,x[i].second);
	}
	
	printf("%lld",ans);
}