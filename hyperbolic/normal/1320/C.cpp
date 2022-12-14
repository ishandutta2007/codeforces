#include <stdio.h>
#include <algorithm>
#include <vector>


long long int MAX = 1;
struct segTree{
	long long int value[4000010];
	long long int lazy[4000010];
	void update(int k)
	{
		value[k] = value[2*k]>value[2*k+1]?value[2*k]:value[2*k+1];
	}
	void add(int L,int R, long long int val, int l=1, int r=1000000, int v = 1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(R<l) return;
		else if(r<L) return;
		else
		{
			value[2*v] += lazy[v], value[2*v+1] += lazy[v];
			lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
			
			int h = (l+r)/2;
			add(L,R,val,l,h,2*v);
			add(L,R,val,h+1,r,2*v+1);
			update(v);
		}
	}
	long long int getMax(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return -MAX;
		else if(r<L) return -MAX;
		else
		{
			value[2*v] += lazy[v], value[2*v+1] += lazy[v];
			lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
			int h = (l+r)/2;
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

struct str{
	int x0;
	int y0;
}x[200010],y[200010];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}
struct str2{
	int x0;
	int y0;
	int z0;
}z[200010];
bool cmp2(str2 a, str2 b)
{
	return a.x0<b.x0;
}

int minX[200010],minY[200010];
int main()
{
	for(int i=1;i<=11;i++) MAX*=10;
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	for(int i=1;i<=b;i++) scanf("%d%d",&y[i].x0,&y[i].y0);
	for(int i=1;i<=c;i++) scanf("%d%d%d",&z[i].x0,&z[i].y0,&z[i].z0);
	std::sort(x+1,x+a+1,cmp);
	std::sort(y+1,y+b+1,cmp);
	std::sort(z+1,z+c+1,cmp2);
	
	minX[a] = x[a].y0, minY[b] = y[b].y0;
	for(int i=a-1;i>=1;i--) minX[i] = minX[i+1] < x[i].y0? minX[i+1] : x[i].y0;
	for(int i=b-1;i>=1;i--) minY[i] = minY[i+1] < y[i].y0? minY[i+1] : y[i].y0;
	
	y[0].x0 = 0;
	for(int i=1;i<=b;i++)
	{
		if(y[i-1].x0==y[i].x0) continue;
		T.add(y[i-1].x0+1,y[i].x0,-minY[i]);
	}
	if(y[b].x0<1000000) T.add(y[b].x0+1,1000000,-MAX);
	
	long long int ans = -MAX;
	int p = 1;
	for(int i=1;i<=a;i++)
	{
		while(p<=c)
		{
			if(z[p].x0<x[i].x0)
			{
				T.add(z[p].y0+1,1000000,z[p].z0);
				p++;
			}
			else break;
		}
		long long int s = T.getMax(1,1000000);
		ans = ans>s-minX[i]?ans:s-minX[i];
	}
	printf("%lld",ans);
}