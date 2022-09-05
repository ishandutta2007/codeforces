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

const int K=16,U=1<<16,Q=2e5+5;
int ans_high[U],ans_low[U];
pii l[Q],r[Q];int v[Q];
int u;
struct Arr
{
	int a[U],s[U];
	void clear()
	{
		rep(i,0,u)a[i]=0;
	}
	void add(int l,int r)
	{
		if(l<U)++a[l];
		if(r+1<U)--a[r+1];
	}
	void init(int j,int ans[])
	{
		rep(i,1,u)a[i]+=a[i-1];
		rep(i,0,u)
		if(a[i])
		{
			a[i]=1;
			ans[i]|=1<<j;
		}
		s[0]=a[0];
		rep(i,1,u)s[i]=s[i-1]+a[i];
	}
	bool query(int l,int r)
	{
		return s[r]>(l?s[l-1]:0);
	}
}a_high,a_low;
void check(bool a)
{
	if(a)
	{
		puts("impossible");
		exit(0);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int k,q;
	cin>>k>>q;
	u=(1<<k)-1;
	rep(i,1,q)
	{
		auto R=[&]()->pii
		{
			u32 x;
			scanf("%u",&x);
			return {x>>k,x&u};
		};
		l[i]=R();r[i]=R();v[i]=read();
	}
	rep(j,0,15)
	{
		a_high.clear();
		a_low.clear();
		rep(i,1,q)
		if((v[i]>>j)&1)
		{
			a_high.add(l[i].first,r[i].first);
			if(l[i].first==r[i].first)a_low.add(l[i].second,r[i].second); else 
			if(l[i].first+1==r[i].first){a_low.add(l[i].second,u);a_low.add(0,r[i].second);} else 
				a_low.add(0,u);
		}
		a_high.init(j,ans_high);
		a_low.init(j,ans_low);
		rep(i,1,q)
		if(!((v[i]>>j)&1))
		{
			if(l[i].first==r[i].first)
			{
				check(a_high.query(l[i].first,l[i].first)&&a_low.query(l[i].second,r[i].second));
			} else 
			{
				check(a_high.query(l[i].first,l[i].first)&&a_low.query(l[i].second,u));
				check(a_high.query(r[i].first,r[i].first)&&a_low.query(0,r[i].second));
				if(l[i].first+1<r[i].first)
					check(a_high.query(l[i].first+1,r[i].first-1)&&a_low.query(0,u));
			}  
		}
	}
	puts("possible");
	rep(i,0,u)printf("%d\n",ans_low[i]);
	rep(i,0,u)printf("%d\n",ans_high[i]);
}