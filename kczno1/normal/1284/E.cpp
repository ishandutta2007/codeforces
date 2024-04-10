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

const int N=2500+5;
struct Point
{
	int x,y;
};
s64 operator *(const Point &a,const Point &b)
{
	return 1LL*a.x*b.y-1LL*b.x*a.y;
}
Point operator -(const Point &a,const Point &b)
{
	return {a.x-b.x,a.y-b.y};
}
Point p[N];
int q[N],b[N];

int C2(int n)
{
	return n*(n-1)/2;
}
s64 work(int n)
{
	rep(i,1,n)b[i]=(p[i].y>0)||(p[i].y==0&&p[i].x>0);
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,[&](int x,int y){return b[x]!=b[y]?b[x]>b[y]:p[x]*p[y]>0;}); 
	int j=1;s64 ans=0;
	rep(i,1,n)
	{
		while(p[q[i]]*p[q[j]]>=0)
		{
			if(j==n)j=1;
			else ++j;
			if(i==j)return 0;
		}
		if(j>i)ans+=C2(j-i-1);
		else ans+=C2(j+n-i-1);
	}
//	cerr<<n*(n-1)*(n-2)/6<<" "<<ans<<endl;
	return 1LL*n*(n-1)*(n-2)/6-ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	static Point p[N];
	rep(i,1,n){p[i].x=read();p[i].y=read();}
	s64 ans=0;
	rep(i,1,n)
	{
		int m=0;
		rep(j,1,n)
		if(j!=i)::p[++m]=p[j]-p[i];
		ans+=work(m);
	}
//	cerr<<ans<<endl;
	cout<<ans*(n-4)/2;
}