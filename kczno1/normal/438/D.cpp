#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}

const int N=1e5+5,T=N*4;
int n,m,mx[T];ll s[T];

#define mid (l+r>>1)
#define cl (k*2)
#define cr (cl+1)
void up(int k)
{
	s[k]=s[cl]+s[cr];
	mx[k]=max(mx[cl],mx[cr]);
}
void init(int k,int l,int r)
{
	if(l==r){scanf("%d",&mx[k]);s[k]=mx[k];return ;}
	init(cl,l,mid);init(cr,mid+1,r);
	up(k);
}
ll ans;
int ql,qr,x;
#define in (ql<=l&&qr>=r)
#define out (ql>r||qr<l)
void qiu(int k,int l,int r)
{
	if(in) {ans+=s[k];return ;}
	if(out) return;
	qiu(cl,l,mid);qiu(cr,mid+1,r);
}
void mo(int k,int l,int r)
{
	if(mx[k]<x) return ;
	if(out) return ;
	if(l==r)
	{
		mx[k]%=x;s[k]=mx[k]; return ;
	}
	mo(cl,l,mid);mo(cr,mid+1,r);
	up(k);
}
namespace T3
{
int x,w;
void dfs(int k,int l,int r)
{
	if(l==r){mx[k]=w;s[k]=mx[k]; return ;}
	if(x<=mid)dfs(cl,l,mid);
	else dfs(cr,mid+1,r);
	up(k);
}
void work()
{
	scanf("%d%d",&x,&w);
	dfs(1,1,n);
}
};

int main()
{
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	init(1,1,n);
	while(m--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			ans=0;
			scanf("%d%d",&ql,&qr);
			qiu(1,1,n);
			printf("%I64d\n",ans);
		}
		else
		if(type==2)
		{
			scanf("%d%d%d",&ql,&qr,&x);
			mo(1,1,n);
		}
		else
		{
			T3::work();
		}
	}
}