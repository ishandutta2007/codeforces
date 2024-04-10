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

const int N=1e6+5,T=N*3,inf=2e9+5;
int a[N],b[N],ad[T],mx[T],d=(1<<20)-1;
vector<pii>lk[N];

void modify(int i,int x)
{
	i+=d;
    while(i)
    {
    	if(i%2==0)
    	{
    		ad[i+1]+=x;
    		mx[i+1]+=x;
    	}
    	i>>=1;
    	mx[i]=max(mx[i*2],mx[i*2+1])+ad[i];
    }
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	rep(i,1,N-1)a[i]=b[i]=inf;
	int n,m,p;
	cin>>n>>m>>p;
	rep(i,1,n)
	{
		int x=read(),c=read();
		chmin(a[x],c);
	}
	rep(i,1,m)
	{
		int x=read(),c=read();
		chmin(b[x],c);
	}
	per(i,N-1,1)chmin(a[i-1],a[i]);
	per(i,N-1,1)chmin(b[i-1],b[i]);
	
	rep(i,1,p)
	{
		int x=read(),y=read(),z=read();
		lk[x].push_back(pii(y,z));
	}
	
	rep(i,1,T-1)mx[i]=-inf;
	rep(i,1,N-1)mx[i+d]=-b[i];
	per(i,(N-1+d)/2,1)mx[i]=max(mx[i*2],mx[i*2+1]);
	
	int ans=-inf;
	rep(i,1,N-1)
	if(a[i]!=inf)
	{
		for(auto p:lk[i-1])
		{
			int y,z;
			tie(y,z)=p;
			modify(y,z);
		}
		chmax(ans,mx[1]-a[i]);
	}
	cout<<ans;
}