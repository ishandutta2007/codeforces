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
int fa[2][N],c[N];
vector<int>lk[2][N];

int find(int i,int x)
{
	return x==fa[i][x]?x:fa[i][x]=find(i,fa[i][x]);
}
void merge(int i,int x,int y)
{
	fa[i][find(i,x)]=find(i,y);
}
s64 C2(int n)
{
	return 1ll*n*(n-1)/2;
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
		int n=read(),m=read(),a=read(),b=read();
		rep(i,1,n)fa[0][i]=fa[1][i]=i;
		rep(i,1,m)
		{
			int x=read(),y=read();
			if(x!=a&&y!=a)merge(0,x,y);
			if(x!=b&&y!=b)merge(1,x,y);
		}
		rep(i,1,n){lk[0][i].clear();lk[1][i].clear();}
		rep(i,1,n)
		if(i!=a&&i!=b)
		{lk[0][find(0,i)].push_back(find(1,i));lk[1][find(1,i)].push_back(find(0,i));}
		s64 ans=C2(n-2);
		rep(i,1,n)
		{
			ans-=C2(lk[0][i].size())+C2(lk[1][i].size());
			for(auto x:lk[0][i])
				ans+=c[x]++;
			for(auto x:lk[0][i])c[x]=0;
		}
		printf("%lld\n",ans);
	}
}