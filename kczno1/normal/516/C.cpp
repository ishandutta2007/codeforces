#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define cl (k*2)
#define cr (cl+1)
#define mid ((l+r)>>1)

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

const int N=1e5+5,T=N*4;const ll inf=2e15;
int n,m;
ll d[N],tot;
struct Node
{
ll mx1;//max(hi+di)
ll mx2;//max(hi-di)
ll ans;//max( (hr+dr) + (hl-dl) )
void init(const ll &d,int h)
{
	mx1=h+d;
	mx2=h-d;
}
void merge(Node *l,Node *r)
{
	mx1=max(l->mx1,r->mx1);
	mx2=max(l->mx2,r->mx2);
	ans=max(max(l->ans,r->ans),r->mx1+l->mx2);
}
}node[T];
ll ans,mx2;

void init(int k,int l,int r)
{
	if(l==r)
	{
		node[k].init(d[l],2*read());
	}
	else
	{
		init(cl,l,mid);init(cr,mid+1,r);
		node[k].merge(node+cl,node+cr);
	}
}

int ql,qr;
void dfs(int k,int l,int r)
{
	if(ql>r||qr<l) return ;
	if(ql<=l&&qr>=r)
	{
		chmax(ans,max(node[k].ans,node[k].mx1+mx2));
		chmax(mx2,node[k].mx2);
		return ;
	}
	dfs(cl,l,mid);dfs(cr,mid+1,r);
}
void qiu(int l,int r)
{
	ql=l;qr=r;
	dfs(1,1,n);
}

int main()
{
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	n=read();m=read();
	rep(i,2,n)d[i]=read()+d[i-1];
	tot=read()+d[n];
	init(1,1,n);
	while(m--)
	{
		int l=read(),r=read();
		ans=0;mx2=-inf;
		if(l>r) 
		{
			qiu(r+1,l-1);
		}
		else
		{
			qiu(r+1,n);
			mx2+=tot;
			qiu(1,l-1);
		}
		printf("%lld\n",ans);
	}
}