#include <stdio.h>
#include <vector>
#include <set>

struct segTree{
	int value[2000010];
	int lazy[2000010];
	void setValue(int ind, int val, int l=0, int r=500000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	
	int getValue(int L, int R, int l=0, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getValue(L,R,l,h,2*v);
			int s2 = getValue(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T1,T2;
std::set<int> S;
int x[500010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=0;i<=a;i++) T1.setValue(i,0);
		for(int i=0;i<=a;i++) T2.setValue(i,0);
		S.clear();
		S.insert(0);
		
		for(int i=1;i<=a;i++)
		{
			int s1 = T1.getValue(0,x[i])+1;
			int s2 = T2.getValue(0,x[i])+1;
			T1.setValue(x[i],s1>s2?s1:s2);
			std::set<int> ::iterator it;
			for(it = S.begin();it!=S.end();it++)
			{
				if((*it)>x[i]) break;
				T2.setValue(*it,T2.getValue(*it,*it)+1);
			}
			while(S.begin()!=S.end() && ((*S.begin())<=x[i])) S.erase(S.begin());
			T2.setValue(x[i],s1>s2?s1:s2);
			S.insert(x[i]);
		}
		int s1 = T1.getValue(0,a);
		int s2 = T2.getValue(0,a);
		printf("%d\n",s1>s2?s1:s2);
	}
}