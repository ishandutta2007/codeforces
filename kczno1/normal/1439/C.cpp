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

struct Node
{
	int al,ar,size;
	s64 sum;
};
const int N=2e5+5;
Node node[N*4];
#define cl (k*2)
#define cr (cl+1)
#define mid ((l+r)/2)
void push_up(int k)
{
	node[k].al=node[cl].al;
	node[k].ar=node[cr].ar;
	node[k].sum=node[cl].sum+node[cr].sum;
}
void set_max(int k,int y)
{
	if(y>node[k].ar)
	{
		node[k].al=node[k].ar=y;
		node[k].sum=s64(node[k].size)*y;
	}
}
void push_down(int k)
{
	set_max(cl,node[k].ar);	
	set_max(cr,node[k].ar);	
}
void init(int k,int l,int r)
{
	node[k].size=r-l+1;
	if(l==r)
	{
		node[k].al=node[k].ar=node[k].sum=read();
	}
	else 
	{
		init(cl,l,mid);
		init(cr,mid+1,r);
		push_up(k);
	}
}
int x,y,ans;
void dfs1(int k,int l,int r)
{
	if(l>x || y<=node[k].ar)return ;
	if(r<=x)
	{
		if(y>=node[k].al)
		{
			set_max(k,y);
			return ;
		}
	}
	push_down(k);
	dfs1(cl,l,mid);
	dfs1(cr,mid+1,r);
	push_up(k);
}
void dfs2(int k,int l,int r)
{
	if(r<x || y<node[k].ar)return ;
	if(l>=x)
	{
		if(y>=node[k].sum)
		{
			y-=node[k].sum;
			ans+=node[k].size;
			return ;
		}
	}
	push_down(k);
	dfs2(cl,l,mid);
	dfs2(cr,mid+1,r);
}


int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	init(1,1,n);
	while(m--)
	{
		int op=read();x=read();y=read();
		if(op == 1)
		{
			dfs1(1,1,n);
		}
		else 
		{
			ans=0;
			dfs2(1,1,n);
			printf("%d\n",ans);
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