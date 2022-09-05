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

s64 sqr(s64 x)
{
	return x*x;
}
const int N=1e5+5;
s64 x[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n/2)
	{
		int d;
		scanf("%d",&d);
		s64 nx=x[i*2-2]+1,ny;
		while(1)
		{
			if(nx>d){puts("No");exit(0);}
			s64 y2=nx*nx+d;
			ny=sqrtl(y2);
			if(ny*ny==y2)break;
			++nx;
		}
		x[i*2-1]=nx;
		x[i*2]=ny;
	}
	puts("Yes");
	rep(i,1,n)printf("%lld ",sqr(x[i])-sqr(x[i-1]));
}