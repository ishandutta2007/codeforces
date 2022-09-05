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

const int N=1e6+5;
int mn_p[N],cnt[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=1e6;
	rep(i,2,n)
	if(!mn_p[i])
		for(int j=i;j<=n;j+=i)
		if(!mn_p[j])mn_p[j]=i;

	int tt;
	cin>>tt;
	while(tt--)
	{
		int n=read();
		vector<int>a(n);
		int ans_0=0,ans_1=0,c1=0;
		rep(i,0,n-1)
		{
			int x=read();
			int y=x;
			while(y>1)
			{
				int p=mn_p[y];
				if(y/p%p==0)
				{
					x=x/p/p;y=y/p/p;
				}
				else y/=p;
			}
			a[i]=x;
			++cnt[x];
		}
		for(auto x:a)
		if(cnt[x])
		{
			chmax(ans_0,cnt[x]);
			if(cnt[x]%2 && x>1)chmax(ans_1,cnt[x]);
			else chmax(ans_1,c1+=cnt[x]);
			cnt[x]=0;
		}
		int q=read();
		while(q--)
		{
			s64 w;
			scanf("%lld",&w);
			printf("%d\n",w?ans_1:ans_0);
		}
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/