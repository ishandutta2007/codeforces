#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> V[300010];
int sum(int type, int L, int R)
{
	int min = 0, max = V[type].size()-1;
	int p1 = -1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[type][h]<=R)
		{
			p1 = h;
			min = h+1;
		}
		else max = h-1;
	}
	
	min = 0, max = V[type].size()-1;
	int p2 = V[type].size();
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[type][h]>=L)
		{
			p2 = h;
			max = h-1;
		}
		else min = h+1;
	}
	return p1-p2+1;
}

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
			
			if(value[2*v]==0&&value[2*v+1]==0) value[v] = 0;
			else if(value[2*v]==0) value[v] = value[2*v+1];
			else if(value[2*v+1]==0) value[v] = value[2*v];
			else if(sum(value[2*v],l,r)>=sum(value[2*v+1],l,r)) value[v] = value[2*v];
			else value[v] = value[2*v+1];
		}
	}
	int getValue(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getValue(L,R,l,h,2*v);
			int s2 = getValue(L,R,h+1,r,2*v+1);
			
			if(s1==0&&s2==0) return 0;
			else if(s1==0) return s2;
			else if(s2==0) return s1;
			else
			{
				if(sum(s1,L,R)>=sum(s2,L,R)) return s1;
				else return s2;
			}
		}
	}
}T;

int x[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) V[x[i]].push_back(i);
	for(int i=1;i<=a;i++) T.setValue(i,x[i]);
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		int t = T.getValue(c,d);
		
		if(t==0) printf("1\n");
		else
		{
			int s = 2*sum(t,c,d)-(d-c+1);
			if(s<=1) printf("1\n");
			else printf("%d\n",s);
		}
	}
}