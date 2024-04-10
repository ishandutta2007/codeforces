#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
#include<immintrin.h>
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

const int N=1e5+5;
int a[6],b[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int ans=2e9;
	rep(i,0,5)a[i]=-read();
	sort(a,a+6);
	int n=read();
	rep(i,1,n)b[i]=read();
	sort(b+1,b+n+1);
	rep(i,1,n)
	rep(j,0,5)
	{
		int mn=b[i]+a[j];
		if(b[1]+a[5]<mn)continue;
		int mx=mn;
		int ni=i;
		/*rep(k,j+1,5)
		{
			if(ni<=1)break;
			int i1=lower_bound(b+1,b+ni,mn-a[k])-b;
			if(i1<ni){chmax(mx,a[k]+b[ni-1]);ni=i1;}
		}*/
		ni=n+1;
		rep(k,0,5)
		{
			int i1=lower_bound(b+1,b+ni,mn-a[k])-b;
			if(i1<ni)
			{
				chmax(mx,a[k]+b[ni-1]);
				ni=i1;
			}
		}
		chmin(ans,mx-mn);
	}	
	cout<<ans<<endl;
}