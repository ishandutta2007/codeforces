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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
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

const int N=5e5+5,L=20;
int n,fa[N],son[N];
int ll[N],rl[N],f[N][L];	
s64 d[N],mn[N],mnr[N],mnl[N],g[N][L],gl[N][L],gr[N][L];int d0[N],dyl[N],dyr[N];
namespace ST
{
s64 mn[L][N];
int lo[N];
void init()
{
	rep(i,2,n)lo[i]=lo[i/2]+1;
	rep(j,1,L-1)
	rep(i,1,n-(1<<j)+1)mn[j][i]=min(mn[j-1][i],mn[j-1][i+(1<<j-1)]);
}
s64 get_mn(int l,int r)
{
	if(l>r)return 1e18;
	int j=lo[r-l+1];
	return min(mn[j][l],mn[j][r-(1<<j)+1]);
}
};
int get_lca(int x,int y)
{
	if(d0[x]<d0[y])swap(x,y);
	per(j,L-1,0)
	if((d0[x]-d0[y])&(1<<j))x=f[x][j];
	if(x==y)return x;
	per(j,L-1,0)
	if(f[x][j]!=f[y][j])
	{
		x=f[x][j];
		y=f[y][j];
	}
	return fa[x];
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	n=read();int m=read();
	rep(i,2,n)
	{
		++son[fa[i]=read()];
		d[i]=d[fa[i]]+read();
		d0[i]=d0[fa[i]]+1;
	}
	rep(i,1,n){mn[i]=1e18;ll[i]=N;rl[i]=0;ST::mn[0][i]=1e18;}
	per(i,n,2)
	{
	if(!son[i])
	{
		per(j,i,1)
		{
			dyr[j]=i;
			if(!son[j-1])break;
		}
		rep(j,i,n)
		{
			dyl[j]=i;
			if(!son[j+1])break;
		}
		ST::mn[0][i]=mn[i]=d[i];
		ll[i]=rl[i]=i;
	}
		chmin(mn[fa[i]],mn[i]);
		chmin(ll[fa[i]],ll[i]);
		chmax(rl[fa[i]],rl[i]);
	}
	ST::init();
	static s64 last[N];
	rep(i,1,n)last[i]=1e18;
	rep(i,2,n)
	{
		mnl[i]=last[fa[i]];
		chmin(last[fa[i]],mn[i]);
	}
	rep(i,1,n)last[i]=1e18;
	per(i,n,2)
	{
		mnr[i]=last[fa[i]];
		chmin(last[fa[i]],mn[i]);
	}
	rep(i,2,n)
	{
		f[i][0]=fa[i];
		g[i][0]=-2*d[i]+mn[i];
		gl[i][0]=-2*d[fa[i]]+mnl[i];
		gr[i][0]=-2*d[fa[i]]+mnr[i];
		rep(j,1,L-1)
		{
			f[i][j]=f[f[i][j-1]][j-1];
			g[i][j]=min(g[i][j-1],g[f[i][j-1]][j-1]);
			gl[i][j]=min(gl[i][j-1],gl[f[i][j-1]][j-1]);
			gr[i][j]=min(gr[i][j-1],gr[f[i][j-1]][j-1]);
		}
	}
	rep(case_id,1,m)
	{
		int v=read(),l=dyr[read()],r=dyl[read()];
		int lca=get_lca(l,r);
		s64 ans=ST::get_mn(l,r)+d[v]-2*d[get_lca(v,lca)];
		int l1=get_lca(l,v),r1=get_lca(r,v);
//		if(case_id==52)
//			int yyx=1;
		if(d0[l1]>d0[lca])
		{
		if(ll[v]>=l&&rl[v]<=r)
		{
			int x=v;
			per(j,L-1,0)
			if(f[x][j]>=l1)
			{
				chmin(ans,g[x][j]+d[v]);
				x=f[x][j];
			}
		}
			int x=l1;
			chmin(ans,ST::get_mn(max(l,ll[x]),min(r,rl[x]))+d[v]-2*d[x]);
			per(j,L-1,0)
			if(f[x][j]>lca)
			{
				chmin(ans,gr[x][j]+d[v]);
				x=f[x][j];
			}
		}
		else
		if(d0[r1]>d0[lca])
		{
		if(ll[v]>=l&&rl[v]<=r)
		{
			int x=v;
			per(j,L-1,0)
			if(f[x][j]>=r1)
			{
				chmin(ans,g[x][j]+d[v]);
				x=f[x][j];
			}
		}
			int x=r1;
			chmin(ans,ST::get_mn(max(l,ll[x]),min(r,rl[x]))+d[v]-2*d[x]);
			per(j,L-1,0)
			if(f[x][j]>lca)
			{
				chmin(ans,gl[x][j]+d[v]);
				x=f[x][j];
			}
		}
		else
		if(d0[v]>d0[lca])
		{
		if(ll[v]>=l&&rl[v]<=r)
		{
			int x=v;
			per(j,L-1,0)
			if(f[x][j]>=lca)
			{
				chmin(ans,g[x][j]+d[v]);
				x=f[x][j];
			}
		}
		}
		chmin(ans,ST::get_mn(max(l,ll[v]),min(r,rl[v]))-d[v]);
		printf("%lld\n",ans);
	}
}