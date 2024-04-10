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

const int N=500+5;
int a[N][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
	rep(j,1,m)a[i][j]=read();
	rep(i,1,n)
	rep(j,1,m)a[i][j]^=read();
	rep(i,1,n)
	rep(j,1,m)
	if(a[i][j])
	{
		if(i==n||j==m){puts("No");exit(0);}
		rep(dx,0,1)
		rep(dy,0,1)a[i+dx][j+dy]^=1;
	}
	puts("Yes");
}