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

const int N=12500+5,M=1e6+5;
struct Edge
{
	int to,id;
};
vector<Edge>lk[N];
pii e[M];
int s[N],ans[M];
bool w[N],mark[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,n)s[i]=w[i]=1;
	rep(i,1,m)
	{
		int x=read(),y=read();
		e[i]={x,y};
		if(x>y)swap(x,y);
		lk[y].push_back({x,i});
		++s[x];++s[y];
		ans[i]=1;
	}
	rep(x,1,n)
	{
		int c1=0,m=lk[x].size();
		for(const auto &e:lk[x])c1+=w[e.to];
		int c0=m-c1;
		rep(i,0,m)mark[i]=0;
		int p=s[x];
		for(const auto &e:lk[x])
		if(s[e.to]>=p-c0&&s[e.to]<=p+c1)
			mark[s[e.to]-(p-c0)]=1;
		int r=0;
		while(mark[r])++r;
		r-=c0;
		//cerr<<x<<" "<<r<<endl;
		s[x]+=r;
		for(const auto &e:lk[x])
		if(r>0&&w[e.to])
		{
			--r;
			w[e.to]=0;
			ans[e.id]=2;
		}
		else 
		if(r<0&&!w[e.to])
		{
			++r;
			w[e.to]=1;
			ans[e.id]=0;
		}
	}
	int c1=0;
	rep(i,1,n)c1+=w[i];
	printf("%d\n",c1);
	if(c1)
	{
		rep(i,1,n)
		if(w[i])printf("%d%c",i," \n"[--c1==0]);
	}
	rep(i,1,m)
		printf("%d %d %d\n",e[i].first,e[i].second,ans[i]);
}