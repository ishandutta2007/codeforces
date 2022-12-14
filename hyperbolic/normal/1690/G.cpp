#include <stdio.h>
#include <vector>
#define MAX 1234567890

struct segTree{
	int lazy[400010];
	void setValue(int L, int R, int val, int l=1 ,int r=100000, int v=1)
	{
		if(L<=l&&r<=R) lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] = lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=1, int r=100000, int v=1)
	{
		if(l==r) return lazy[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] = lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T1,T2;

std::vector<int> V;
int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ans = 1;
		for(int i=1;i<=a;i++) x[i] = MAX;
		x[0] = -1;
		x[a+1] = -1;
		T1.setValue(1,a,1);
		T2.setValue(1,a,a);
		for(int c=1;c<=a;c++)
		{
			int d;
			scanf("%d",&d);
			x[c] = d;
			int L = T1.getValue(c), R = T2.getValue(c)+1;
			
			if(x[c]<x[L])
			{
				ans++;
				T2.setValue(L,c-1,c-1);
				L = c;
			}
			
			while(x[R]>=x[L])
			{
				ans--;
				R = T2.getValue(R)+1;
			}
			T1.setValue(L,R-1,L);
			T2.setValue(L,R-1,R-1);
		}
		
		while(b--)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			int L = T1.getValue(c), R = T2.getValue(c)+1;
			x[c] -= d;
			
			if(x[c]<x[L])
			{
				ans++;
				T2.setValue(L,c-1,c-1);
				L = c;
			}
			
			while(x[R]>=x[L])
			{
				ans--;
				R = T2.getValue(R)+1;
			}
			T1.setValue(L,R-1,L);
			T2.setValue(L,R-1,R-1);
			V.push_back(ans);
		}
		
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
		printf("\n");
	}
}