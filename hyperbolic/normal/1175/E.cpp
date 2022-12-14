#include <stdio.h>
#include <algorithm>

struct str{
	int x0;
	int y0;
	int index;
	int value;
}x[500010],y[500010];

bool cmp(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}

struct segTree{
	int value[2000010];
	int get(int L, int R,int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = get(L,R,l,h,2*v);
			int s2 = get(L,R,h+1,r,2*v+1);
			if(s1==0) return s2;
			else if(s2==0) return s1;
			else
			{
				if(x[s1].y0<x[s2].y0) return s2;
				else return s1;
			}
		}
	}
	void update(int v)
	{
		int s1 = value[2*v];
		int s2 = value[2*v+1];
		if(s1==0) value[v] = s2;
		else if(s2==0) value[v] = s1;
		else
		{
			if(x[s1].y0<x[s2].y0) value[v] = s2;
			else value[v] = s1;
		}
	}
	void set(int ind, int l = 1, int r = 500000, int v = 1)
	{
		if(l==r)
		{
			value[v] = ind;
			return;
		}
		int h = (l+r)/2;
		if(ind<=h) set(ind,l,h,2*v);
		else set(ind,h+1,r,2*v+1);
		update(v);
	}
}T;


int next[500010][30];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	for(int i=1;i<=b;i++) scanf("%d%d",&y[i].x0,&y[i].y0);
	for(int i=1;i<=b;i++) y[i].index = i;
	std::sort(x+1,x+a+1,cmp);
	std::sort(y+1,y+b+1,cmp);
	x[a+1].x0 = 1234567, x[a+1].y0 = 12345678;
	
	for(int i=1;i<=a;i++) T.set(i);
	
	int l = 1, r = 1;
	for(int i=1;i<=a;i++)
	{
		while(x[l].x0<x[i].x0) l++;
		while(x[r+1].x0<=x[i].y0) r++;
		if(l>r) next[i][0] = i;
		else next[i][0] = T.get(l,r);
	}
	for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
	
	int p = 0;
	for(int i=1;i<=b;i++)
	{
		while(x[p+1].x0<=y[i].x0) p++;
		if(p==0)
		{
			y[i].value = -1;
			continue;
		}
		
		int s = T.get(1,p);
		
		if(x[s].y0<y[i].x0)
		{
			y[i].value = -1;
			continue;
		}
		
		int ans = 1;
		for(int j=20;j>=0;j--)
		{
			if(x[next[s][j]].y0<y[i].y0)
			{
				ans += (1<<j);
				s = next[s][j];
			}
		}
		if(x[s].y0<y[i].y0) ans++;
		
		if(ans>a) y[i].value = -1;
		else y[i].value = ans;
	}
	std::sort(y+1,y+b+1,cmp2);
	for(int i=1;i<=b;i++) printf("%d\n",y[i].value);
}