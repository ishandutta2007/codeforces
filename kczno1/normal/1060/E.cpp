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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
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
int n;
vector<int>lk[N];
int sz[N],c0;

void dfs(int x,int fr,int dep)
{
	sz[x]=1;c0+=dep%2==0;
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x,dep+1);
		sz[x]+=sz[y];
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs(1,0,0);
	s64 ans=0;
	rep(x,1,n)ans+=s64(sz[x])*(n-sz[x]);
	cout<<(ans+s64(c0)*(n-c0))/2;
}