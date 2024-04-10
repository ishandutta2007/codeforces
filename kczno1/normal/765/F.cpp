//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'-');
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

const int N=1e5+5,inf=1e9,M=3e5+5;
int n,a[N];
vector<pii> lk[N];
int ans[M];

namespace SEG
{
const int T=N*3;
int a[T],d;
void init()
{
	for(d=1;d<n;d<<=1);d-=1;
	rep(i,1,T-1)a[i]=inf;
}
void up(int i,int x)
{
	for(i+=d;a[i]>x;i>>=1)a[i]=x;
}
int qiu(int i)
{
	int ans=a[i+=d];
	for(;i>1;i>>=1)
	if(!(i&1))chmin(ans,a[i+1]);
	return ans;
}
};
#define cl (k*2)
#define cr (cl+1)
#define mid (l+r>>1)
namespace SEG2
{
const int T=N*4;
int q[N],top;
int a[T];
void init()
{
	memcpy(q+1,::a+1,n*sizeof(int));
	sort(q+1,q+n+1);
	top=unique(q+1,q+n+1)-(q+1);

	memset(a,0,sizeof(a));
}
int ql,qr,ans;
namespace QIU
{
void dfs(int k,int l,int r)
{
	if(ql<=l&&qr>=r)
	{
		chmax(ans,a[k]);
		return ;
	}
	if(ql>r||qr<l)return ;
	dfs(cl,l,mid);dfs(cr,mid+1,r);
}
};
int qiu(int l,int r)
{
	ql=lower_bound(q+1,q+top+1,l)-q;qr=lower_bound(q+1,q+top+1,r+1)-q-1;ans=0;
	QIU::dfs(1,1,top);
	return ans;
}
void up(int i,int v)
{
	i=lower_bound(q+1,q+top+1,i)-q;
	int k=1,l=1,r=top;
	while(1)
	{
		chmax(a[k],v);
		if(l==r)break;
		if(i<=mid){r=mid;k=cl;}
		else{l=mid+1;k=cr;}
	}
}
};

void solve()
{
	SEG::init();
	SEG2::init();
	deque<pii>st;
	a[0]=-1;
	st.pb(mp(inf,0));
	rep(r,1,n)
	{
		int x=a[r];
		while(st.back().first<x)st.pop_back();
		int l=st.back().second;
		while(a[l]>=x)
		{
			SEG::up(l,a[l]-x);
			if(a[l]==x)break;
			int v=(a[l]+x-1)>>1;
			l=SEG2::qiu(x,v);
		}
		SEG2::up(x,r);
		st.push_back(mp(x,r));
		for(auto pr:lk[r])chmin(ans[pr.second],SEG::qiu(pr.first));
	}
}

int main()
{
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	n=read();
	rep(i,1,n)a[i]=read();
	int m=read();
	rep(i,1,m)
	{
		int l=read(),r=read();
		lk[r].pb(mp(l,i));
	}
	rep(i,1,m)ans[i]=inf;
	solve();
	rep(i,1,n)a[i]=inf-a[i];
	solve();
	rep(i,1,m)printf("%d\n",ans[i]);
}