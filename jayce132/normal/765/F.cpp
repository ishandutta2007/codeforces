#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;
const int LIM=1e9;

int n,a[maxn],m;

int l[maxn*3],r[maxn*3];
vector<int>tor[maxn];

int ans[maxn*3];

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
	m=read();
	REP(i,1,m)
	{
		l[i]=read(); r[i]=read();
		tor[r[i]].push_back(i);
		ans[i]=inf;
	}
}

namespace Fenwick {
	int s[maxn];
	inline void Init(){ memset(s,inf,sizeof(s));}
	inline void Add(int x,int d){ for(x=n-x+1;x<=n;x+=x&(-x))chkmin(s[x],d);}
	inline int Sum(int x){ int res=inf;for(x=n-x+1;x;x-=x&(-x))chkmin(res,s[x]);return res;}
};

struct node {
	int mx,ls,rs;
};
node c[maxn<<6];
int ctot,rt;

void update(int x,int d,int &o,int l,int r)
{
	if(!o)o=++ctot;
	chkmax(c[o].mx,d);//c[o].s+=d;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)update(x,d,c[o].ls,l,mid);
	else update(x,d,c[o].rs,mid+1,r);
}

inline int query(int ql,int qr,int o,int l,int r)
{
	if(!o)return 0;
	if(ql<=l && r<=qr)return c[o].mx;
	int mid=l+r>>1,ans=0;
	if(ql<=mid)chkmax(ans,query(ql,qr,c[o].ls,l,mid));
	if(qr>mid)chkmax(ans,query(ql,qr,c[o].rs,mid+1,r));
	return ans;
}

inline void doing()
{
	Fenwick::Init(); memset(c,0,sizeof(node)*(ctot+1));
	REP(r,1,n)
	{
		int x=a[r];
		int far=LIM;
		while(far>=x)
		{
			int t=query(x,far,rt,1,LIM);
			if(!t)break;
			Fenwick::Add(t,a[t]-x);
			far=a[t]+x-1>>1;
		}
		update(x,r,rt,1,LIM);
		for(int i:tor[r])chkmin(ans[i],Fenwick::Sum(l[i]));
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	init();
	doing();
	reverse(a+1,a+n+1);
	REP(i,1,n)tor[i].clear();
	REP(i,1,m)l[i]=n-l[i]+1,r[i]=n-r[i]+1,swap(l[i],r[i]),tor[r[i]].push_back(i);
	doing();
	REP(i,1,m)printf("%d\n",ans[i]);
	return 0;
}