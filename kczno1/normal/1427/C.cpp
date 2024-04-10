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

const int N=1e5+5,R=500+5;
int t[N],x[N],y[N],f[N],pf[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int r,n;
	cin>>r>>n;
	x[0]=y[0]=1;
	rep(i,1,n)
	{
		t[i]=read();
		x[i]=read();
		y[i]=read();
		f[i]=-N;
		int l=max(0,i-2*r);
		if(l)f[i]=pf[l-1]+1;
		rep(j,l,i-1)
		if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]))
			chmax(f[i],f[j]+1);
		pf[i]=max(pf[i-1],f[i]);
	}	
	cout<<pf[n]<<endl;
}