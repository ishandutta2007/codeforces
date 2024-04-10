#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=2e5+5;
int fa[N],a[N],b[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct Edge
{
	int u,v,w;
};	
vector<Edge> e;

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int m,n;
	cin>>m>>n;
	rep(i,1,m)a[i]=read();
	rep(i,1,n)b[i]=read();
	rep(i,1,m)
	{
		int s=read();
		rep(tmp,1,s)
		{
			int j=read();
			e.push_back({n+i,j,a[i]+b[j]});
		}
	}
	rep(i,1,n+m)fa[i]=i;
	sort(e.begin(),e.end(),[&](const Edge &a,const Edge &b){return a.w>b.w;});
	s64 sum=0;
	for(auto p:e)
	{
		int x=find(p.u),y=find(p.v);
		if(x==y)sum+=p.w;
		else fa[x]=y;
	}
	cout<<sum<<endl;	
}