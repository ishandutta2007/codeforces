#include <stdio.h>
#include <vector>

struct segTree{
	int value[1200010];
	int lazy[1200010];
	void setValue(int L, int R, int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

struct segTree2{
	int value[1200010];
	int lazy[1200010];
	void setValue(int L, int R, int val, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = (r-l+1)*val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T2;

int left[300010],right[300010];
std::vector<int> V1[300010],V2[300010];
int init(int k, int &C)
{
	left[k] = C;
	C++;
	right[k] = left[k];
	for(int i=0;i<V2[k].size();i++) right[k] = init(V2[k][i],C);
	return right[k];
}

int ans = 0;
int count = 0;
void func(int k)
{
	int save = -1;
	int check = -1;
	if(T2.getSum(left[k]+1,right[k])==0)
	{
		int t = T.getMax(left[k],left[k]);
		check = t;
		if(T2.getSum(left[t],left[t])==0)
		{
			save = 0;
			count++;
			T.setValue(left[k],right[k],k);
			T2.setValue(left[k],left[k],1);
		}
		else
		{
			save = 1;
			T2.setValue(left[t],left[t],0);
			
			T.setValue(left[k],right[k],k);
			T2.setValue(left[k],left[k],1);
		}
	}
	ans = ans>count?ans:count;
	
	for(int i=0;i<V1[k].size();i++) func(V1[k][i]);
	if(save==0)
	{
		count--;
		T.setValue(left[k],right[k],check);
		T2.setValue(left[k],left[k],0);
	}
	else
	{
		T.setValue(left[k],right[k],check);
		T2.setValue(left[k],left[k],0);
		T2.setValue(left[check],left[check],1);
	}
}

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V1[i].clear();
		for(int i=1;i<=a;i++) V2[i].clear();
		
		ans = 0, count = 0;
		T.setValue(1,a,0);
		T2.setValue(1,a,0);
		
		for(int i=2;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V1[b].push_back(i);
		}
		for(int i=2;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V2[b].push_back(i);
		}
		
		int C = 1;
		init(1,C);
		func(1);
		printf("%d\n",ans);
	}
}