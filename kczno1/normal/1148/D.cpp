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

const int N=3e5+5;
int a[N],b[N],q[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	int cnt=0;
	rep(i,1,n){a[i]=read();b[i]=read();cnt+=a[i]<b[i];}
	if(cnt>n-cnt)
	{
		cout<<cnt<<endl;
		int t=0;
		rep(i,1,n)
		if(a[i]<b[i])q[++t]=i;
		sort(q+1,q+t+1,[&](int x,int y){return a[x]>a[y];});
		rep(i,1,t)printf("%d ",q[i]);
	}
	else
	{
		cout<<n-cnt<<endl;
		int t=0;
		rep(i,1,n)
		if(a[i]>b[i])q[++t]=i;
		sort(q+1,q+t+1,[&](int x,int y){return b[x]<b[y];});
		rep(i,1,t)printf("%d ",q[i]);
	}
}