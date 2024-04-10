#include<cstdio>

using namespace std;

int x[400000],y[400000];

struct SegmentTree
{
	struct nd
	{
		int lc,rc,sta,sum;
	}t[1000000];
	int used;void init(){used=0;}
	int new_node(){used++;t[used].lc=t[used].rc=t[used].sum=0,t[used].sta=-1;return used;}
	void update(int k){t[k].sum=0;if(t[k].lc)t[k].sum+=t[t[k].lc].sum;if(t[k].rc)t[k].sum+=t[t[k].rc].sum;}
	void add_tag(int k,int sta,int l,int r)
	{
		t[k].sta=sta,t[k].sum=t[k].sta*(r-l+1);
	}
	void spread(int k,int l,int r)
	{
		if(t[k].sta==-1)return;
		if(l==r){t[k].sta=-1;return;}
		int mid=(l+r)>>1;
		if(!t[k].lc)t[k].lc=new_node();add_tag(t[k].lc,t[k].sta,l,mid);
		if(!t[k].rc)t[k].rc=new_node();add_tag(t[k].rc,t[k].sta,mid+1,r);
		t[k].sta=-1;
	}
	void del(int cnt,int k,int l,int r)
	{
		if(!cnt)return;
		spread(k,l,r);
		if(l==r){t[k].sum=0;return;}
		int mid=(l+r)>>1;
		if(cnt<t[t[k].rc].sum)del(cnt,t[k].rc,mid+1,r);
		else{del(cnt-t[t[k].rc].sum,t[k].lc,l,mid);add_tag(t[k].rc,0,mid+1,r);}
		update(k);
	}
	void del_pnt(int pos,int k,int l,int r)
	{
		spread(k,l,r);
		if(l==r){t[k].sum=0;return;}
		int mid=(l+r)>>1;
		if(pos<=mid)del_pnt(pos,t[k].lc,l,mid);else del_pnt(pos,t[k].rc,mid+1,r);
		update(k);
	}
	int query(int pos,int k,int l,int r)
	{
		spread(k,l,r);if(l==r)return l;
		int mid=(l+r)>>1;
		return pos<=t[t[k].lc].sum?query(pos,t[k].lc,l,mid):query(pos-t[t[k].lc].sum,t[k].rc,mid+1,r);
	}
	int query_pos(int pos,int k,int l,int r)
	{
		spread(k,l,r);
		if(l==r)return t[k].sum;
		int mid=(l+r)>>1;return pos<=mid?query_pos(pos,t[k].lc,l,mid):query_pos(pos,t[k].rc,mid+1,r);
	}
}T;

const long long MOD=998244353;

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}
long long fac[500000],invf[500000];
void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}
long long C(int n,int m)
{
	if(n<0||m<0||n<m)return 0;return fac[n]*invf[m]%MOD*invf[n-m]%MOD;
}

int main()
{
	init_fac(450000);
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0,m=0;scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]);
		int cnt=0;
		x[m+1]=n+1;
		T.init();int rt=T.new_node();T.add_tag(rt,1,1,n);
		for(int i=m;i>=1;i--)
		{
			if(x[i+1]>x[i]+1)T.del(x[i+1]-x[i]-1,rt,1,n);
			int u=T.query(y[i],rt,1,n);T.del_pnt(u,rt,1,n);
			if(T.query_pos(u+1,rt,1,n))cnt++;
		}//printf("%d %d %d\n",cnt,2*n-1-cnt,n);
		printf("%lld\n",C(2*n-1-cnt,n));
	}
}