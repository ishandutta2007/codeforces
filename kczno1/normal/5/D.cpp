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
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
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

double a,v,mv,ans;
double jie(const double &a,const double &b,const double &c)
{
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}
double calc(const double &l,const double &v)
{
	double t=jie(a/2,v,-l/2);
	if(v+a*t<=mv)return 2*t;
	t=(mv-v)/a;
	double vt=v+a*t;
	return 2*(t+(l/2-(v+vt)/2*t)/vt);
}
void solve(const double &l,const double &mv)
{
	double t=(mv-v)/a;
	if((v+mv)/2*t<=l) 
	{
		ans+=t+calc(l-(v+mv)/2*t,mv);
		v=mv;
		return ;
	}
	t=jie(a/2,v,-l);
	ans+=t;
	v+=a*t;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	double l,d,w;
	cin>>a>>mv>>l>>d>>w;
	chmin(w,mv);
	solve(d,w);
	solve(l-d,mv);
	printf("%lf\n",ans);
}