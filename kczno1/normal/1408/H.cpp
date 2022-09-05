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

const int N=5e5+5,U=1e9;
int a[N],last[N];
namespace SEG
{
#define cl (k*2)
#define cr (cl+1)
#define mid ((l+r)/2)
const int T=N*4;
int n,mn[T],ad[T];
void Add(int k,int w)
{
	mn[k]+=w;ad[k]+=w;
}
void down(int k)
{	
	if(ad[k]){Add(cl,ad[k]);Add(cr,ad[k]);ad[k]=0;}
}
void up(int k)
{
	mn[k]=min(mn[cl],mn[cr]);
}
int ql,qr,qw;
void add_dfs(int k,int l,int r)
{
	if(ql<=l&&qr>=r)
	{
		Add(k,qw);
		return ;
	}
	if(ql>r||qr<l)return ;
	down(k);
	add_dfs(cl,l,mid);
	add_dfs(cr,mid+1,r);
	up(k);
}
void add(int l,int r,int w)
{
//	cerr<<l<<" "<<r<<" "<<w<<endl;
	ql=l;qr=r;qw=w;
	add_dfs(1,1,n);
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int case_cnt;
	cin>>case_cnt;
	rep(case_id,1,case_cnt)
	{
		int n=read();
		SEG::n=n;
		rep(i,1,n*4)SEG::mn[i]=SEG::ad[i]=0;
		rep(i,1,n)last[i]=1;
		rep(i,1,n)a[i]=read();
		int c0=0,ans=n;
		SEG::add(1,n,U);
		rep(i,1,n)
		if(!a[i])
		{
			++c0;
			for(int j=i-1;j&&a[j];--j)
			{
				SEG::add(last[a[j]],c0-1,1);
				last[a[j]]=c0;
			}
			SEG::add(c0,c0,c0-1-U);
			chmin(ans,SEG::mn[1]-c0);
		}		
		printf("%d\n",min(c0+ans,c0/2));
	}
}