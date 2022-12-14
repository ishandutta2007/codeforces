#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

struct segTree{
	int value[800010];
	void update(int k)
	{
		value[k]=value[2*k]>value[2*k+1]?value[2*k]:value[2*k+1];
	}
	void setValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			update(v);
		}
	}
	int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

struct str{
	int x0;
	int value;
};
struct str2{
	int x0;
	int y0;
}z[200010];
bool cmp(str2 a, str2 b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}

bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;

std::vector<int> V[200010];
int dist[200010][3];
void func(int k, int color)
{
	Q.push({k,1});
	while(!Q.empty())
	{
		int k = Q.top().x0;
		int value = Q.top().value;
		Q.pop();
		if(dist[k][color]) continue;
		dist[k][color] = value;
		for(int i=0;i<V[k].size();i++) if(dist[V[k][i]][color]==0) Q.push({V[k][i],value+1});
	}
}

int x[200010],y[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	for(int i=1;i<=c;i++) y[x[i]] = 1;
	
	int C = 0;
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
		if(y[d]==1&&y[e]==1) C = 1;
	}
	
	func(1,1);
	func(a,2);
	
	if(C==1)
	{
		printf("%d",dist[a][1]-1);
		return 0;
	}
	
	for(int i=1;i<=c;i++) z[i]={dist[x[i]][1]-1,dist[x[i]][2]-1};
	std::sort(z+1,z+c+1,cmp);
	
	for(int i=1;i<=c;i++) T.setValue(i,z[i].y0);
	
	int min = 1, max = a;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		
		for(int i=1;i<=c;i++)
		{
			int min0 = i+1, max0 = c;
			int start = c+1;
			while(min0<=max0)
			{
				int h0 = (min0+max0)/2;
				if(z[h0].x0+z[i].y0>=h)
				{
					start = h0;
					max0 = h0-1;
				}
				else min0 = h0+1;
			}
			if(start==c+1) continue;
			
			int s = T.getMax(start,c);
			if(s+z[i].x0+1>=h)
			{
				ans = h;
				min = h+1;
				goto u;
			}
		}
		
		max = h-1;
		u:;
	}
	ans = ans<dist[a][1]-1?ans:dist[a][1]-1;
	printf("%d",ans);
}