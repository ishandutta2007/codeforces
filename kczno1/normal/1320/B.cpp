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
vector<int>lk[N],nlk[N];
int g[N],p[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	rep(i,1,m)
	{
		int x=read(),y=read();
		lk[y].push_back(x);
		nlk[x].push_back(y);
	}
	int k=read();
	rep(i,1,k)p[i]=read(); 
	
	rep(i,1,n)g[i]=-1;
	deque<int>q;
	auto P=[&](int x,int d)
	{
		if(g[x]==-1){q.push_back(x);g[x]=d;}
	};
	P(p[k],0);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		for(auto y:lk[x])P(y,g[x]+1);
	}
	
//	rep(i,1,n)cout<<g[i]<<endl;
	int ans=0;
	rep(i,1,k-1)ans+=(g[p[i]]!=g[p[i+1]]+1);
	printf("%d ",ans);
	rep(i,1,k-1)
	{
		int x=p[i],y=p[i+1];
		if(g[y]==g[x]-1)
		for(auto z:nlk[x])
		if(g[z]==g[x]-1&&z!=y){++ans;break;}
	}
	printf("%d\n",ans);
}