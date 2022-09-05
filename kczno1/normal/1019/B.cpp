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

void out(int x)
{
	printf("! %d\n",x);
	exit(0);
}
int qiu(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	return a;
}
int n;
int D(int i)
{
	int d=qiu(i+n/2)-qiu(i);
	if(!d)out(i);
	return d;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	scanf("%d",&n);
	if(n%4)out(-1);
	int l=1,r=n/2,dl=D(l),dr=D(r);
	while(1)
	{
		int m=(l+r)/2,dm=D(m);
		if((dm>0)==(dl>0))l=m;
		else r=m;
	}
}