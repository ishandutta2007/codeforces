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

const int N=3e5+5,T=N*30;
int c[T][2],sz[T],tot=1;

void ins(int x)
{
	int i=1;
	per(j,29,0)
	{
		bool d=(x>>j)&1;
		i=c[i][d]?c[i][d]:c[i][d]=++tot;
		++sz[i];
	}
}

int solve(int x)
{
	int ans=0,i=1;
	per(j,29,0)
	{
		bool d=(x>>j)&1;
		if(sz[c[i][d]])i=c[i][d];
		else{ans+=1<<j;i=c[i][d^1];}
		--sz[i];
	}
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read();
	static int a[N];
	rep(i,1,n)a[i]=read();
	rep(i,1,n)ins(read());
	rep(i,1,n)printf("%d ",solve(a[i]));
}