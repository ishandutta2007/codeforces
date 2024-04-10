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
vector<int>lk[N];
int F[N],q[N],fa[N],sz[N];
bool in_a[N];
bool dfs(vector<int> a,int k)
{
	if(k<=1)return 1;
	for(auto x:a)in_a[x]=1;
	
	int t=1;
	fa[q[1]=a[0]]=0;
	rep(h,1,t)
	{
		int x=q[h];sz[x]=1;
		for(auto y:lk[x])
		if(in_a[y] && y!=fa[x])fa[q[++t]=y]=x;
	}
	per(h,t,1)sz[fa[q[h]]]+=sz[q[h]];
	for(auto x:a)
	if(sz[x]==F[k-2] || sz[x]==F[k-1])
	{
		int t=1;
		q[1]=x;
		rep(h,1,t)
		{
			int x=q[h];sz[x]=1;
			for(auto y:lk[x])
			if(in_a[y] && y!=fa[x])fa[q[++t]=y]=x;
		}
		vector<int>b=vector<int>(q+1,q+t+1);
		for(auto x:b)in_a[x]=0;
		vector<int>c;
		for(auto x:a)
		if(in_a[x])
		{
			in_a[x]=0;
			c.push_back(x);
		}
		return dfs(b,k-1-(b.size()==F[k-2])) && dfs(c,k-1-(c.size()==F[k-2]));
	}
	for(auto x:a)in_a[x]=0;
	return 0;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	int k=1;
	F[0]=F[1]=1;
	while(F[k]<n)
	{
		++k;
		F[k]=F[k-1]+F[k-2];
	}
	if(F[k]!=n)puts("NO");
	else 
	{
		vector<int>a(n);
		rep(i,0,n-1)a[i]=i+1;
		puts(dfs(a,k)?"YES":"NO");
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase, fa[++tot]=tot(UB)  
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/