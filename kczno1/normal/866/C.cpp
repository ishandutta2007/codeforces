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

const int N=50+2,U=5000+2;
double dp[N][U];
int n,r;
struct point
{
int f,s;double p;
void trans(double *f1,double *f2)
{
	rep(j,0,r+1)f1[j]=p*(f+f2[min(j+f,r+1)])
					+(1-p)*(s+f2[min(j+s,r+1)]);
}
};
point a[N];
bool ok(const double &f0)
{
	rep(i,0,r)dp[n+1][i]=0;
	dp[n+1][r+1]=f0;
	per(i,n,1)
	{
		rep(j,0,r+1)chmin(dp[i+1][j],f0);
		a[i].trans(dp[i],dp[i+1]);
	}
	return dp[1][0]<=f0;
}
double erfen()
{
	double l=0,r=1e9;
	rep(i,1,100)
	{
		double mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid;
	}
	return r;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();r=read();
	rep(i,1,n)a[i]=(point){read(),read(),double(read())/100};
	printf("%.9lf\n",erfen());
}