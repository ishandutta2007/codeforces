#include <stdio.h>
#include <vector>

struct segTree{
	int value[1600010];
	int lazy[1600010];
	void addValue(int L, int R, int val, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 12345678;
		else if(R<l) return 12345678;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T,T2;

std::vector<int> V1,V2;
int check[400010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=2*a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			check[b] = 1;
		}
		for(int i=1;i<=2*a;i++) if(check[i]==0) V2.push_back(i);
		for(int i=2*a;i>=1;i--) if(check[i]==1) V1.push_back(i);
		
		for(int i=1;i<=2*a;i++)
		{
			if(check[i]==1) T.addValue(i,2*a,1);
			else T.addValue(i,2*a,-1);
		}
		
		int ans = 0;
		int k = T.getMin(1,2*a);
		if(k>=0) ans++;
		for(int i=0;i<a;i++)
		{
			T.addValue(V1[i],2*a,-1);
			T.addValue(V2[i],2*a,1);
			T2.addValue(1,V1[i],1);
			T2.addValue(1,V2[i],-1);
			if(T2.getMin(1,2*a)<0) continue;
			
			k = T.getMin(1,2*a);
			if(k>=0) ans++;
		}
		printf("%d\n",ans);
		
		for(int i=1;i<=2*a;i++) T.addValue(i,i,-T.getMin(i,i));
		for(int i=1;i<=2*a;i++) T2.addValue(i,i,-T2.getMin(i,i));
	}
}