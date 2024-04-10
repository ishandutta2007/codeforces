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

const int N=2e5+5;
int nex[N],k[N],ans[N];
s64 s[N];
bool is_l[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	priority_queue<pii>heap;
	int max_len=0;
	auto push=[&](int l)
	{
		int r=nex[l]-1;
		chmax(max_len,r-l);
		if(r<n)heap.push( {(s[r]-s[l-1]-1)/(r-l+1),l} );
	};
	rep(i,1,n)
	{
		s[i]=s[i-1]+read();
		nex[i]=i+1;
		push(i);
	}
	rep(i,1,m)k[i]=read();	
	per(i,m,1)
	{
		while(!heap.empty() && heap.top().first>=k[i])
		{
			int l=heap.top().second;
			heap.pop();
			int r=nex[l];
			if(r==0)continue;
			nex[l]=nex[r];
			nex[r]=0;
			push(l);
		}
		ans[i]=max_len;
	}	
	rep(i,1,m)printf("%d%c",ans[i]," \n"[i==m]);
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/