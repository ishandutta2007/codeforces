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

const int N=1e6+5;
vector<pii>lk[N];
int n,sz[N];
s64 G,B;

void dfs(int x,int fr)
{
	sz[x]=1;
	for(auto e:lk[x])
	{
		int y,w;
		tie(y,w)=e;
		if(y==fr)continue;
		dfs(y,x);
		sz[x]+=sz[y];
		if(sz[y]%2)G+=w;
		B+=1ll*w*min(sz[y],n-sz[y]);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		n=read()*2;
		rep(i,1,n)lk[i].clear();
		rep(i,1,n-1)
		{
			int x=read(),y=read(),w=read();
			lk[x].push_back({y,w});
			lk[y].push_back({x,w});
		}
		G=B=0;
		dfs(1,0);
		printf("%lld %lld\n",G,B);
	}
}