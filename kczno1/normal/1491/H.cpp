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

const int N=1e5+5,L=400,B=N/L+5;
int a[N],b[N],belong[N],bl[B],br[B],ad[B];
void init_block(int i)
{
	int x=ad[i];
	if(x>=L)return ;
	rep(j,bl[i],br[i])
	{
		b[j]=a[j]-x;
		if(b[j]>=bl[i])b[j]=b[b[j]];
	}
}
void brute(int i,int l,int r,int x)
{
	rep(j,l,r)a[j]=max(1,a[j]-x);
	init_block(i);
}
int get_lca(int x,int y)
{
	while(x!=y)
	if(belong[x]==belong[y])
	{
		int i=belong[x];
		int x1,y1;
		if(ad[i]>=L){x1=a[x]-ad[i];y1=a[y]-ad[i];}
		else {x1=b[x];y1=b[y];}
		if(x1==y1)
		{
			while(x!=y)
			if(x>y)x=a[x]-ad[i];
			else y=a[y]-ad[i];
			return max(1,x);
		}
		else 
		{
			x=x1;y=y1;
			if(x<=1 || y<=1)return 1;
		}
	}
	else 
	{
		if(x>y)
		{
			x=ad[belong[x]]>=L?a[x]-ad[belong[x]]:b[x];
			if(x<=1)return 1;
		}
		else 
		{
			y=ad[belong[y]]>=L?a[y]-ad[belong[y]]:b[y];
			if(y<=1)return 1;
		}
	}
	return x;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),q=read();
	rep(i,2,n)
	{
		a[i]=read();
		belong[i]=i/L+1;
		if(!bl[belong[i]])bl[belong[i]]=i;
		br[belong[i]]=i;
	}
	rep(i,1,belong[n])init_block(i);
	while(q--)
	if(read()==1)
	{
		int l=read(),r=read(),x=read();
		int lb=belong[l],rb=belong[r];
		if(lb==rb)brute(lb,l,r,x);
		else 
		{
			brute(lb,l,br[lb],x);
			brute(rb,bl[rb],r,x);
			rep(i,lb+1,rb-1)
			if(ad[i]<n)
			{
				ad[i]+=x;
				init_block(i);
			}
		}
	}
	else 
	{
		int u=read(),v=read();
		printf("%d\n",get_lca(u,v));
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase, fa[++tot]=tot(UB)  
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/