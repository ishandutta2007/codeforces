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

const int N=3e5+5,U=15e6+5;
int a[N];
int r[U],pr[U],pcnt,cnt[U],mn[U];

void init(int n)
{
	rep(i,2,n)
	{
		if(!r[i])
		{
			r[i]=pr[++pcnt]=i;
		}
		for(int j=1,x;x=pr[j],i*x<=n;++j)
		{
			r[i*x]=x;
			if(x==r[i])break;
		}
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	int u=15e6;
	init(u);
	int g=0;
	rep(i,1,n)g=__gcd(g,a[i]=read());
	for(int x=g;x>1;)
	{
		int p=r[x];
		while(x%p==0){x/=p;++mn[p];}
	}
	rep(i,1,n)
	for(int x=a[i];x>1;)
	{
		int p=r[x],c=0;
		while(x%p==0){x/=p;++c;}
		if(!mn[p])++cnt[p];
		else cnt[p]+=c==mn[p];
	}
	int ans=n;
	rep(i,1,u)chmin(ans,mn[i]?cnt[i]:n-cnt[i]);
	cout<<(ans==n?-1:ans);
}