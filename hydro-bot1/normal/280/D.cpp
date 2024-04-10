// Hydro submission #62c560668672efa577bebaf1@1657102439080
#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define db double
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
namespace IO
{
	const int SZ=1<<20;
	char gchar()
	{
	    static char buf[SZ];
	    static int i=SZ;
	    if(i==SZ)i=0,fread(buf,1,SZ,stdin);
	    return buf[i++];
	}
	void pchar(char c)
	{
	    static char buf[SZ];
	    static int i=0;
	    if(c)buf[i++]=c;
	    if(!c||i==SZ)fwrite(buf,1,i,stdout),i=0;
	}
	void pstr(string s,char end='\n')
	{
		for(char c:s)pchar(c);
		pchar(end);
	}
	template<typename T>void read(T &x)
	{
	    x=0;int f=1;
	    static char c;
	    while((c=gchar())>'9'||c<'0')if(c=='-')f=-1;
	    x=c-'0';
	    while((c=gchar())>='0'&&c<='9')
			x=(x<<1)+(x<<3)+(c^48);
		x*=f;
	}
	template<typename T>void i_write(T x)
	{
	    if(x>9)i_write(x/10);
	    pchar(x%10+'0');
	}
	template<typename T>void write(T x,char end='\n')
	{
	    if(x<0)pchar('-'),x=-x;
	    if(x>9)i_write(x/10);
	    pchar(x%10+'0');
	    pchar(end);
	}
}
using IO::read;
using IO::write;
const int N=1e5+10;
int n,m,a[N];
struct node
{
	int l,r,mxlp,mxrp,mnlp,mnrp,mxl,mxr,mnl,mnr;
	ll lmx,lmn,rmx,rmn,mx,mn,s;
	node operator + (node b) const
	{
		node c;
		c.l=l,c.r=b.r,c.s=s+b.s;
		c.lmx=max(lmx,s+b.lmx);
		if(c.lmx==lmx)c.mxlp=mxlp;
		else c.mxlp=b.mxlp;
		c.lmn=min(lmn,s+b.lmn);
		if(c.lmn==lmn)c.mnlp=mnlp;
		else c.mnlp=b.mnlp;
		c.rmx=max(rmx+b.s,b.rmx);
		if(c.rmx==rmx+b.s)c.mxrp=mxrp;
		else c.mxrp=b.mxrp;
		c.rmn=min(rmn+b.s,b.rmn);
		if(c.rmn==rmn+b.s)c.mnrp=mnrp;
		else c.mnrp=b.mnrp;
		c.mx=max(max(mx,b.mx),rmx+b.lmx);
		if(c.mx==mx)c.mxl=mxl,c.mxr=mxr;
		else if(c.mx==b.mx)c.mxl=b.mxl,c.mxr=b.mxr;
		else c.mxl=mxrp,c.mxr=b.mxlp;
		c.mn=min(min(mn,b.mn),rmn+b.lmn);
		if(c.mn==mn)c.mnl=mnl,c.mnr=mnr;
		else if(c.mn==b.mn)c.mnl=b.mnl,c.mnr=b.mnr;
		else c.mnl=mnrp,c.mnr=b.mnlp;
		return c;
	}
};
struct SegmentTree
{
	node t[N<<2];
	bool rev[N<<2];
	void build(int p,int l,int r)
	{
		if(l==r)return t[p]=(node){l,r,l,r,l,r,l,r,l,r,a[l],a[l],a[l],a[l],a[l],a[l],a[l]},void();
		int mid=(l+r)>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	void tag(int p)
	{
		swap(t[p].mxlp,t[p].mnlp),swap(t[p].mxrp,t[p].mnrp);
		swap(t[p].mxl,t[p].mnl),swap(t[p].mxr,t[p].mnr);
		swap(t[p].lmx,t[p].lmn),t[p].lmx=-t[p].lmx,t[p].lmn=-t[p].lmn;
		swap(t[p].rmx,t[p].rmn),t[p].rmx=-t[p].rmx,t[p].rmn=-t[p].rmn;
		swap(t[p].mx,t[p].mn),t[p].mx=-t[p].mx,t[p].mn=-t[p].mn;
		t[p].s=-t[p].s,rev[p]^=1;
	}
	void pushdown(int p)
	{
		if(rev[p])tag(p<<1),tag(p<<1|1),rev[p]=0;
	}
	void upd(int p,int l,int r,int x,int v)
	{
		if(l==r)return t[p]=(node){l,r,l,r,l,r,l,r,l,r,v,v,v,v,v,v,v},void();
		pushdown(p);int mid=(l+r)>>1;
		if(x<=mid)upd(p<<1,l,mid,x,v);
		else upd(p<<1|1,mid+1,r,x,v);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	void cov(int p,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return tag(p);
		pushdown(p);int mid=(l+r)>>1;
		if(L<=mid)cov(p<<1,l,mid,L,R);
		if(R>mid)cov(p<<1|1,mid+1,r,L,R);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	node ask(int p,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)return t[p];
		pushdown(p);int mid=(l+r)>>1;
		if(R<=mid)return ask(p<<1,l,mid,L,R);
		if(L>mid)return ask(p<<1|1,mid+1,r,L,R);
		return ask(p<<1,l,mid,L,R)+ask(p<<1|1,mid+1,r,L,R);
	}
}sgt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	sgt.build(1,1,n);
	int t,l,r,k;
	while(m--)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(!t)a[l]=r,sgt.upd(1,1,n,l,r);
		else
		{
			scanf("%d",&k);vector<pii>vec;
			ll ans=0;
			for(int i=1;i<=k;i++)
			{
				node res=sgt.ask(1,1,n,l,r);
				if(res.mx<0)break;
				ans+=res.mx,sgt.cov(1,1,n,res.mxl,res.mxr);
				vec.push_back({res.mxl,res.mxr});
			}
			printf("%lld\n",ans);
			for(auto p:vec)sgt.cov(1,1,n,p.fi,p.se);
		}
	}
	IO::pchar(0);
	return 0;
}