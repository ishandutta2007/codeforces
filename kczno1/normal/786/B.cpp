#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5,T=N*3;
vector<pair<pii,int> >lk[N];
int n;
s64 g[N];

int fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

priority_queue<pair<s64,pii> >heap;

vector<pii>seg_lk[T];
int d;
void add(int l,int r,pii p)
{
	l+=d;r+=d;
	seg_lk[l].push_back(p);
	if(l==r)return ;
	seg_lk[r].push_back(p);
	while(l+1!=r)
	{
		if(l%2==0)seg_lk[l+1].push_back(p);
		if(r%2)seg_lk[r-1].push_back(p);
		l>>=1;r>>=1;
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin); 
#endif	
	int m,s;
	cin>>n>>m>>s;
	d=1;
	while(d<=n)d*=2;
	--d;
	while(m--)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int v,u,w;
			scanf("%d%d%d",&v,&u,&w);
			lk[v].push_back({{u,u},w});
		}
		else
		{
			int v,l,r,w;
			scanf("%d%d%d%d",&v,&l,&r,&w);
			if(t==2)lk[v].push_back({{l,r},w});
			else add(l,r,{v,w});
		}
	}
	
	rep(i,1,n+1)fa[i]=i;
	heap.push({0,{s,s}});
	while(!heap.empty())
	{
		auto now=heap.top();heap.pop();
		while(1)
		{
			int x=find(now.second.first);
			if(x>now.second.second)break;
			fa[x]=x+1;
			g[x]=-now.first;
			for(int i=x+d;i;i>>=1)
			{
				for(auto p:seg_lk[i])heap.push({-(g[x]+p.second),{p.first,p.first}});
				seg_lk[i].clear();
			}
			for(auto p:lk[x])heap.push({-(g[x]+p.second),p.first});
		}
	}
	rep(i,1,n)printf("%lld ",fa[i]==i?-1:g[i]);
}