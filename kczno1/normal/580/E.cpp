#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

template <typename T> inline void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> inline void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

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

const int N=1e5+5,T=N*4,_D[3]={1e9+7,1e9+9,998244353};
int D;
#define mid (l+r>>1)
#define cl (k*2)
#define cr (cl+1)
#define in (ql<=l&&qr>=r)
#define out (ql>r||qr<l)
int n;
int _mi[3][N],_smi[3][N],_s[3][T],_same[3][T];
int *mi,*smi,*s,*same,len[T];
void PRE(int o)
{
	mi=_mi[o];smi=_smi[o];s=_s[o];same=_same[o];D=_D[o];
}
int merge(int x1,int x2,int l2)
{
	return (ll(x1)*mi[l2]+x2)%D;
}
void up(int k)
{
	s[k]=merge(s[cl],s[cr],len[cr]);
}
namespace INIT
{
char ch[N];
void init(int k,int l,int r)
{
	len[k]=r-l+1;same[k]=-1;
	if(l==r)
	{
		s[k]=ch[l]-'0';
		return ;
	}
	init(cl,l,mid);init(cr,mid+1,r);
	up(k);
}
void work()
{
	scanf("%s",ch+1);
 rep(o,0,2)
 {
 	PRE(o);
	mi[0]=smi[0]=1;
	rep(i,1,n) smi[i]=( smi[i-1] + (mi[i]=ll(mi[i-1])*10%D) )%D;
	init(1,1,n);
 }
}
};
void make_same(int k,int x)
{
	s[k]=ll(smi[len[k]-1])*x%D;
	same[k]=x;
}
void down(int k)
{
	if(same[k]!=-1)
	{
		make_same(cl,same[k]);make_same(cr,same[k]);
		same[k]=-1;
	}
}

namespace SAME
{
int ql,qr,qx;
void dfs(int k,int l,int r)
{
	if(in)
	{
		make_same(k,qx);
		return ;
	}
	if(out)return ;
	down(k);
	dfs(cl,l,mid);dfs(cr,mid+1,r);
	up(k);
}
void solve()
{
	ql=read();qr=read();qx=read();
rep(o,0,2)
{
	PRE(o);
	dfs(1,1,n);
}
}
};
namespace QUERY
{
int ql,qr,ans;
void dfs(int k,int l,int r)
{
	if(in)
	{
		ans=merge( ans,s[k],len[k]  );
		return ;
	}
	if(out)return ;
	down(k);
	dfs(cl,l,mid);dfs(cr,mid+1,r);
}
int get(int l,int r)
{
	ql=l;qr=r;ans=0;
	dfs(1,1,n);
	return ans;
}
void solve()
{
	int l=read(),r=read(),x=read();
	int len=r-l+1;
	rep(o,0,2)
    {
    	PRE(o);
    	int a1=get(l,r-x),a2=get(l+x,r);
    	if(get(l,r-x)!=get(l+x,r))
    	{
    		puts("NO");
    		return ;
    	}
    }
	puts("YES");
}
};

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	n=read();
	int m=read()+read();

	INIT::work();

	while(m--)
	if(read()==1)SAME::solve();
    else QUERY::solve();
}