//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l,i##_r=r;i<=i##_r;++i)
#define per(i,r,l) for(int i=r,i##_l=l;i>=i##_l;--i)
#define pb push_back
#define mp make_pair
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

const int N=1e4+5;
const double eps=1e-7;
int cmp(const double &x)
{
	return x<-eps?-1:x>eps;
}
int n;ll w,v,u;

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	cin>>n>>w>>v>>u;
	ll mx=0,mn=1e12;
	rep(i,1,n)
	{
		ll x=read(),y=read();
		ll now=x*u-y*v;
		chmin(mn,now);
		chmax(mx,now);
	}
	if(mn>=0) printf("%lf\n",(double)w/u);
	else printf("%lf\n",(double)mx/(u*v)+(double)w/u);
}