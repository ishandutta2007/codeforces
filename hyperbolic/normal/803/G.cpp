#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 1234567890

struct segTree{
	int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=0, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v] = val, lazy[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v]= lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=0, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] = lazy[v], value[2*v+1] = lazy[v];
				lazy[2*v]= lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T,T2;


struct str{
	int type;
	int left;
	int right;
	int value;
}query[100010];

std::vector<int> index;
std::map<int,int> hash;
int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++) scanf("%d",&x[i]);
	for(int i=0;i<a;i++) T2.setValue(i,i,x[i]);
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d,e,f,g;
		scanf("%d",&d);
		if(d==1)
		{
			scanf("%d%d%d",&e,&f,&g);
			e--,f--;
			query[i]={d,e,f,g};
		}
		if(d==2)
		{
			scanf("%d%d",&e,&f);
			e--,f--;
			query[i]={d,e,f,-1};
		}
		index.push_back(e);
		index.push_back(f+1);
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	
	for(int i=0;i+1<index.size();i++)
	{
		int L = index[i];
		int R = index[i+1]-1;
		if(R-L+1>=a) T.setValue(i,i,T2.getMin(0,a-1));
		else
		{
			L%=a;
			R%=a;
			if(L<=R) T.setValue(i,i,T2.getMin(L,R));
			else
			{
				int s1 = T2.getMin(L,a-1);
				int s2 = T2.getMin(0,R);
				T.setValue(i,i,s1<s2?s1:s2);
			}
		}
	}
	
	for(int i=1;i<=c;i++)
	{
		int L = hash[query[i].left];
		int R = hash[query[i].right+1] - 1;
		
		if(query[i].type==1) T.setValue(L,R,query[i].value);
		else printf("%d\n",T.getMin(L,R));
	}
	
}