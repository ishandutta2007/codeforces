#include <stdio.h>
#include <queue>
#include <vector>

struct str{
	int value;
	int index;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;

struct segTree{
	int value[800010];
	void add(int val, int ind, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v]+=val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) add(val,ind,l,h,2*v);
			else add(val,ind,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int get(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = get(L,R,l,h,2*v);
			int s2 = get(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T1,T2;

struct str2{
	int x0;
	int y0;
	int z0;
}x[200010];

std::vector<int> V[200010];
int parent[200010],left[200010],right[200010];
void func(int k, int prev, int& C)
{
	parent[k] = prev;
	left[k] = C++;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,C);
	}
	right[k] = C-1;
}

int check[200010];

void func2(int k, int prev)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func2(V[k][i],k);
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d%d%d",&x[i].x0,&x[i].y0,&x[i].z0);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	int C =1;
	func(1,0,C);
	for(int i=1;i<=a;i++)
	{
		if(x[i].y0==0 && x[i].z0==1) T1.add(1,left[i]);
		if(x[i].y0==1 && x[i].z0==0) T2.add(1,left[i]);
	}
	
	long long int ans = 0;
	
	for(int i=1;i<=a;i++) Q.push({x[i].x0,i});
	while(!Q.empty())
	{
		int v = Q.top().index;
		Q.pop();
		if(check[v]) continue;
		
		int s1 = T1.get(left[v],right[v]);
		int s2 = T2.get(left[v],right[v]);
		int s = s1<s2?s1:s2;
		//printf("%d %d!!\n",v,s);
		ans += (long long int)x[v].x0 * (2*s);
		T1.add(-s,left[v]);
		T2.add(-s,left[v]);
		
		func2(v,parent[v]);
		
	}
	int s1 = T1.get(left[1],right[1]);
	int s2 = T2.get(left[1],right[1]);
	if(s1>0 || s2>0) printf("-1");
	else printf("%lld",ans);
}