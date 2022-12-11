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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=3e5+20;
const int inf=0x3f3f3f3f;

int n,p[maxn];
int Le[maxn];

#define pii pair<int,int>

struct node {
	int mn;
	int lz;
	inline void Merge(node lc,node rc) {
		mn=min(lc.mn,rc.mn);
	}
};
node c[(1<<20)+20];
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

void make_tree(int o,int l,int r)
{
	c[o].mn=0;
	if(l==r)return;
	int mid=l+r>>1;
	make_tree(left);
	make_tree(right);
}

inline void Add(int o,int d){ c[o].mn+=d; c[o].lz+=d;}

inline void pushdown(int o)
{
	if(c[o].lz)
	{
		Add(lc,c[o].lz);
		Add(rc,c[o].lz);
		c[o].lz=0;
	}
}

void update(int ql,int qr,int d,int o,int l,int r)
{
	if(ql<=l && r<=qr)return Add(o,d),void();
	int mid=l+r>>1;
	pushdown(o);
	if(ql<=mid)update(ql,qr,d,left);
	if(qr>mid)update(ql,qr,d,right);
	c[o].Merge(c[lc],c[rc]);
}

int queryK(int o,int l,int r)
{
	if(l==r)return l;
	int mid=l+r>>1;
	pushdown(o);
	if(c[lc].mn==0)return queryK(left);
	else return queryK(right);
}

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int x=read(),y=read();
		p[x]=y; 
	}

	make_tree(1,1,n);
	int stmx[maxn]={0},topmx=0,stmn[maxn]={0},topmn=0;
	REP(i,1,n)
	{
		while(topmx && p[stmx[topmx]]<=p[i])
		{
			update(stmx[topmx-1]+1,stmx[topmx],-p[stmx[topmx]],1,1,n);
			topmx--;
		}
		update(stmx[topmx]+1,i,p[i],1,1,n);
		stmx[++topmx]=i;

		while(topmn && p[stmn[topmn]]>=p[i])
		{
			update(stmn[topmn-1]+1,stmn[topmn],p[stmn[topmn]],1,1,n);
			topmn--;
		}
		update(stmn[topmn]+1,i,-p[i],1,1,n);
		stmn[++topmn]=i;
		Le[i]=queryK(1,1,n);
		update(1,i,-1,1,1,n);
	}
	//REP(i,1,n)cerr<<Le[i]<<" "; cerr<<endl;
}

const int maxt=maxn<<1;

int tot,fa[maxt],l[maxt],r[maxt],op[maxt];
int L[maxt],R[maxt];
//0:,1sx,2:jx
int rd[maxt];

inline void doing()
{
	int st[maxt]={0},top=0;
	REP(i,1,n)
	{
		int now=++tot; op[now]=0; l[now]=r[now]=i; L[now]=R[now]=p[i];
		//cerr<<now<<" ";
		while(1)
		{
			while(top)
			{
				int x=st[top];
				if(R[x]+1==L[now]|| L[x]-1==R[now])
				{
					if(!op[x] || (op[x]==1 && L[x]-1==R[now]) || (op[x]==2 && R[x]+1==L[now]))
					{
						++tot; int nx=tot;
						r[nx]=r[now]; l[nx]=l[x];
						L[nx]=min(L[x],L[now]);
						R[nx]=max(R[x],R[now]);
						fa[x]=fa[now]=nx;
						op[nx]=p[l[nx]]<p[r[nx]]?1:2;
						now=nx; top--;
					}else
					{
						chkmax(r[x],r[now]); fa[now]=x;
						L[x]=min(L[x],L[now]);
						R[x]=max(R[x],R[now]);
						//op[x]=p[l[x]]<p[r[x]]?1:2; 
						now=x; top--;
					}
				}else break;
			}
			st[++top]=now;
			int flg=1,mx=R[now],mn=L[now];
			for(int th=top-1;th>=1 && l[st[th]]>=Le[i];th--)
			{
				int x=st[th];
				chkmax(mx,R[x]);
				chkmin(mn,L[x]);
				if(mx-mn==i-l[x])
				{
					flg=0;
					++tot;
					L[tot]=inf;
					REP(j,th,top)fa[st[j]]=tot,chkmin(L[tot],L[st[j]]),chkmax(R[tot],R[st[j]]);
					l[tot]=l[x]; r[tot]=r[st[top]]; op[tot]=0;
					top=th-1; //st[top]=tot;
					now=tot;
					break;
				}
			}
			if(flg)break;
		}
	}
	REP(i,1,tot)rd[fa[i]]++;
	ll ans=0;
	REP(i,1,tot)
	{
		chkmax(rd[i],1);
		if(op[i])
		{
			ans+=((ll)rd[i]*(rd[i]-1)>>1)-1;
		}
	}
	REP(i,1,tot)ans++;
	printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("526F.in","r",stdin);
	freopen("526F.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}