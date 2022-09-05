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

const int M=3e5+5,T=M*3;
s64 t[T],x[T],y[T],s,b;
int n,m,head,tail;

s64 get_t(int i)
{
	return (y[i]-y[i+1]+x[i+1]-x[i]-1)/(x[i+1]-x[i]);
}
s64 get(int tail)
{
	return y[tail]+x[tail]*s+b;
}
void work()
{
	int ty=read();
	if(ty==1)
	{
		int k=read();
		n+=k;
		head=tail=M;
		x[head]=0;y[head]=-b;
	}
	else
	if(ty==2)
	{
		int k=read();
		++tail;
		x[tail]=n;
		y[tail]=-(n*s+b);
		n+=k;
		if(tail>head&&get(tail-1)<=get(tail))--tail;
		else
		{
			while(tail-head+1>=3&&get_t(tail-2)<=get_t(tail-1))
			{
				--tail;
				x[tail]=x[tail+1];
				y[tail]=y[tail+1];
			}
		}
	}
	else
	{
		b+=read();
		s+=read();
		while(tail>head&&get(tail-1)<=get(tail))--tail;
	}
} 

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n>>m;
	head=tail=M;
	x[head]=0;y[head]=0;
	while(m--)
	{
		work();
		printf("%lld %lld\n",x[tail]+1,get(tail));
	}
}