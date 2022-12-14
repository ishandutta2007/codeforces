#include <stdio.h>
#include <algorithm>
#include <map>
#define MAXSIZE 1000000
struct SegTree{
	int value[4*MAXSIZE+10];
	SegTree()
	{
		for(int i=0;i<=4*MAXSIZE+1;i++) value[i] = 0;
	}
	void set(int dataIndex, int dataValue,int v=1,int l=1, int r=MAXSIZE)
	{
		if(l==r)
		{
			value[v] = dataValue;
			return;
		}
		int h = (l+r)/2;
		if(dataIndex<=h) set(dataIndex,dataValue,2*v,l,h);
		else set(dataIndex,dataValue,2*v+1,h+1,r);
		update(v);
	}
	void update(int v)
	{
		value[v] = value[2*v]^value[2*v+1];
	}
	int xorProcess(int left, int right, int v=1,int l=1,int r=MAXSIZE)
	{
		if(left<=l&&r<=right) return value[v];
		else if(right<l) return 0;
		else if(r<left) return 0;
		else
		{
			int h = (l+r)/2;
			return xorProcess(left,right,2*v,l,h)^xorProcess(left,right,2*v+1,h+1,r);
		}
	}
}Tree;
std::map<int,int> M;

struct str{
	int x0;
	int y0;
	int z0;
	int ans;
}y[1000010];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.z0<b.z0;
}
int x[1000010],next[1000010];
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b);
		x[i] = b;
		if(M.find(b)==M.end()) M[b] = i;
		else
		{
			Tree.set(i,b);
			next[M[b]] = i;
			M[b] = i;
		}
	}
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&y[i].x0,&y[i].y0);
		y[i].z0 = i;
		y[i].ans = 0;
	}
	std::sort(y+1,y+b+1,cmp);
	
	int t = 1;
	for(int i=1;i<=b;i++)
	{
		while(t<y[i].x0) Tree.set(next[t],0),t++;
		y[i].ans = Tree.xorProcess(y[i].x0,y[i].y0);
	}
	std::sort(y+1,y+b+1,cmp2);
	for(int i=1;i<=b;i++)
	{
		printf("%d\n",y[i].ans);
	}
}