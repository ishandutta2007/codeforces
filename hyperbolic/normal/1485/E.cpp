#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

long long int MIN = -1;
long long int MAX = 1;
struct segTree{
	long long int value[800010];
	void setValue(int ind, long long int val, int l=1, int r=200000, int v=1)
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
	long long int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getMax(L,R,l,h,2*v);
			long long int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T1,T2;

long long int abs(long long int k)
{
	return k>0?k:-k;
}

std::vector<int> V[200010];
int height[200010];
void setLevel(int k, int prev, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		setLevel(V[k][i],k,h+1);
	}
}
std::vector<int> index;
std::map<int,int> hash;
std::vector<int> query[200010];
int x[200010];
long long int ans[200010];
int main()
{
	for(int i=1;i<=16;i++) MIN*=10;
	for(int i=1;i<=16;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) T1.setValue(i,MIN);
		for(int i=1;i<=a;i++) T2.setValue(i,MIN);
		index.clear();
		hash.clear();
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) query[i].clear();
		for(int i=1;i<=a;i++) ans[i] = 0;
		
		for(int i=2;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[i].push_back(b);
			V[b].push_back(i);
		}
		for(int i=2;i<=a;i++) scanf("%d",&x[i]);
		for(int i=2;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		setLevel(1,0,1);
		for(int i=1;i<=a;i++) query[height[i]].push_back(i);
		for(int i=a;i>=1;i--)
		{
			long long int maxValue = MIN;
			long long int minValue = MAX;
			for(int j=0;j<query[i+1].size();j++)
			{
				minValue = minValue<x[query[i+1][j]]?minValue:x[query[i+1][j]];
				maxValue = maxValue>x[query[i+1][j]]?maxValue:x[query[i+1][j]];
			}
			
			for(int j=0;j<query[i].size();j++)
			{
				int v = query[i][j];
				long long int ans1 = 0;
				for(int k=0;k<V[v].size();k++)
				{
					if(height[V[v][k]]==height[v]+1)
					{
						ans1 = ans1>abs(minValue-x[V[v][k]])+ans[V[v][k]]?ans1:abs(minValue-x[V[v][k]])+ans[V[v][k]];
						ans1 = ans1>abs(maxValue-x[V[v][k]])+ans[V[v][k]]?ans1:abs(maxValue-x[V[v][k]])+ans[V[v][k]];
						
						long long int P = T1.getMax(hash[x[V[v][k]]],a);
						ans1 = ans1>P-x[V[v][k]]?ans1:P-x[V[v][k]];
						P = T2.getMax(1,hash[x[V[v][k]]]-1);
						ans1 = ans1>P+x[V[v][k]]?ans1:P+x[V[v][k]];
					}
				}
				ans[v] = ans1;
			}
			
			for(int j=0;j<query[i+1].size();j++)
			{
				int v = query[i+1][j];
				T1.setValue(hash[x[v]],MIN);
				T2.setValue(hash[x[v]],MIN);
			}
			for(int j=0;j<query[i].size();j++)
			{
				int v = query[i][j];
				if(T1.getMax(hash[x[v]],hash[x[v]])<ans[v]+x[v]) T1.setValue(hash[x[v]],ans[v]+x[v]);
				if(T2.getMax(hash[x[v]],hash[x[v]])<ans[v]-x[v]) T2.setValue(hash[x[v]],ans[v]-x[v]);
			}
		}
		
		printf("%lld\n",ans[1]);
	}
}