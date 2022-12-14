#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 12345678

struct segTree{
	int value[1200010];
	void update(int k)
	{
		value[k] = value[2*k]<value[2*k+1]?value[2*k]:value[2*k+1];
	}
	void set(int ind, int val, int l=1, int r=300000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) set(ind,val,l,h,2*v);
			else set(ind,val,h+1,r,2*v+1);
			update(v);
		}
	}
	int get(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L>R) return MAX;
		
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			int s1 = get(L,R,l,h,2*v);
			int s2 = get(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

int x[300010],y[300010];
std::queue<int> Q[300010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int CASE = 1; CASE <= Case; CASE++)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int i=1;i<=a;i++) while(!Q[i].empty()) Q[i].pop();
		for(int i=1;i<=a;i++) Q[x[i]].push(i);
		for(int i=1;i<=a;i++)
		{
			if(Q[i].size()>0) T.set(i,Q[i].front());
			else T.set(i,MAX);
		}
		
		for(int i=1;i<=a;i++)
		{
			if(Q[y[i]].size()==0)
			{
				printf("NO\n");
				goto u;
			}
			int t = Q[y[i]].front();
			Q[y[i]].pop();
			
			if(T.get(1,y[i]-1)<t)
			{
				printf("NO\n");
				goto u;
			}
			if(Q[y[i]].size()>0) T.set(y[i],Q[y[i]].front());
			else T.set(y[i],MAX);
		}
		printf("YES\n");
		u:;
	}
}