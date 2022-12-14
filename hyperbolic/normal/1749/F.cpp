#include <stdio.h>
#include <vector>

struct segTree{
	long long int lazy[800010];
	void addValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
		}
	}
	long long int getValue(int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) return lazy[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T[21];

int prev[200010][21],height[200010],size[200010],heavy[200010],up[200010],treeNum[200010];
std::vector<int> V[200010];

int init(int k, int p, int h)
{
	prev[k][0] = p;
	height[k] = h+1;
	size[k] = 1;
	heavy[k] = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		size[k] += init(V[k][i],k,h+1);
		if(heavy[k]==-1) heavy[k] = V[k][i];
		else if(size[heavy[k]] < size[V[k][i]]) heavy[k] = V[k][i];
	}
	return size[k];
}

void init2(int k, int p, int target, int &C)
{
	up[k] = target;
	treeNum[k] = C++;
	
	if(heavy[k]!=-1) init2(heavy[k],k,target,C);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		if(V[k][i]==heavy[k]) continue;
		init2(V[k][i],k,V[k][i],C);
	}
}

int LCA(int s, int t)
{
	if(height[s]>height[t])
	{
		int k = height[s]-height[t];
		for(int i=20;i>=0;i--)
		{
			if(k >= (1<<i))
			{
				k -= (1<<i);
				s = prev[s][i];
			}
		}
	}
	if(height[s]<height[t])
	{
		int k = height[t]-height[s];
		for(int i=20;i>=0;i--)
		{
			if(k >= (1<<i))
			{
				k -= (1<<i);
				t = prev[t][i];
			}
		}
	}
	
	for(int i=20;i>=0;i--)
	{
		if(prev[s][i] != prev[t][i])
		{
			s = prev[s][i];
			t = prev[t][i];
		}
	}
	if(s==t) return s;
	else return prev[s][0];
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	init(1,0,1);
	int C = 1;
	init2(1,0,1,C);
	for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) prev[i][j] = prev[prev[i][j-1]][j-1];
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			//~~
			int d;
			scanf("%d",&d);
			long long int ans = 0;
			for(int i=0;i<=20;i++)
			{
				for(int j=i;j<=20;j++) ans += T[j].getValue(treeNum[d]);
				d = prev[d][0];
				if(d==0) break;
			}
			printf("%lld\n",ans);
		}
		else
		{
			int s,t,val,d;
			scanf("%d%d%d%d",&s,&t,&val,&d);
			
			int g = LCA(s,t);
			int g2 = prev[g][0];
			for(int i=d-1;i>=0;i--)
			{
				if(g2==0) break;
				T[i].addValue(treeNum[g2],treeNum[g2],val);
				if(i-1>=0) T[i-1].addValue(treeNum[g],treeNum[g],-val);
				g2 = prev[g2][0];
				g = prev[g][0];
			}
			
			int p,p2;
			g = LCA(s,t);
			T[d].addValue(treeNum[s],treeNum[s],val);
			p = prev[s][0];
			p2 = s;
			if(height[p]>=height[g])
			{
				while(up[p]!=up[g])
				{
					T[d].addValue(treeNum[up[p]],treeNum[p],val);
					if(d-1>=0)
					{
						if(up[p2]!=up[p])
						{
							T[d-1].addValue(treeNum[p2],treeNum[p2],-val);
							p2 = prev[p2][0];
						}
						T[d-1].addValue(treeNum[up[p2]]+1,treeNum[p2],-val);
						p2 = up[p2];
					}
					p = prev[up[p]][0];
				}
				T[d].addValue(treeNum[g],treeNum[p],val);
				if(d-1>=0)
				{
					if(up[p2]!=up[p])
					{
						T[d-1].addValue(treeNum[p2],treeNum[p2],-val);
						p2 = prev[p2][0];
					}
					T[d-1].addValue(treeNum[g]+1,treeNum[p2],-val);
					p2 = up[p2];
				}
			}
			
			T[d].addValue(treeNum[t],treeNum[t],val);
			p = prev[t][0];
			p2 = t;
			
			if(height[p]>=height[g])
			{
				while(up[p]!=up[g])
				{
					T[d].addValue(treeNum[up[p]],treeNum[p],val);
					if(d-1>=0)
					{
						if(up[p2]!=up[p])
						{
							T[d-1].addValue(treeNum[p2],treeNum[p2],-val);
							p2 = prev[p2][0];
						}
						T[d-1].addValue(treeNum[up[p2]]+1,treeNum[p2],-val);
						p2 = up[p2];
					}
					p = prev[up[p]][0];
				}
				T[d].addValue(treeNum[g],treeNum[p],val);
				if(d-1>=0)
				{
					if(up[p2]!=up[p])
					{
						T[d-1].addValue(treeNum[p2],treeNum[p2],-val);
						p2 = prev[p2][0];
					}
					T[d-1].addValue(treeNum[g]+1,treeNum[p2],-val);
					p2 = up[p2];
				}
			}
			
			T[d].addValue(treeNum[g],treeNum[g],-val);
		}
	}
}