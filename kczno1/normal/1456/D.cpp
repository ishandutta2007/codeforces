//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
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
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
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

const int N=5000+5,INF=1e9+5;
s64 t[N],x[N],f[N][2];
int max_to[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n)
	{
		t[i]=read();
		x[i]=read();
		f[i][0]=INF;
	}	
	max_to[n]=n;
	per(i,n-1,0)
	{
		if(abs(t[i+1]-t[i])<abs(x[i+1]-x[i]))max_to[i]=i;
		else max_to[i]=max_to[i+1];
	}
	f[0][0]=0;
	rep(i,0,n-1)
	{
		if(f[i][0]<=t[i])
		{
			s64 t1 = f[i][0]+abs(x[i+1]-x[i]);
			if(t1<=t[i+1])
			{
				chmin(f[i+1][0],max(t1,t[i]));
				rep(k,i+2,max_to[i+1]+1)
				{
					t1 =max(f[i][0] + abs(x[k]-x[i]), t[i]);
					if(abs(x[k]-x[i+1]) <= t[i+1] - t1)
						f[k-1][1] = 1;
				}
			}
		}
		if(f[i][1])
		{
			s64 t1 = t[i]+abs(x[i+2]-x[i]);
			if(t1<=t[i+2])
			{
				chmin(f[i+2][0],max(t1,t[i+1]));
				rep(k,i+3,max_to[i+2]+1)
				{
					t1 =max(t[i] + abs(x[k]-x[i]), t[i+1]);
					if(abs(x[k]-x[i+2]) <= t[i+2] - t1)
						f[k-1][1] = 1;
				}
			}
		}
	}
	puts((f[n][0]<=t[n] || f[n-1][1])?"YES":"NO");
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/