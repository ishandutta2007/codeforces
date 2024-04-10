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
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=3e5+20;

#define pii pair<int,int>
#define lc (o<<1)
#define rc (o<<1|1)
#define left lc,l,mid
#define right rc,mid+1,r

vector<pii>c[(1<<20)+20];
int n;
map<pii,int>mp;

void update(int ql,int qr,pii x,int o,int l,int r)
{
	if(ql<=l && r<=qr)return c[o].push_back(x),void();
	int mid=l+r>>1;
	if(ql<=mid)update(ql,qr,x,left);
	if(qr>mid)update(ql,qr,x,right);
}

inline void init ()
{
	n=read();
	REP(i,1,n)
	{
		int x=read(),y=read();
		int id=mp[mkr(x,y)];
		if(id==0)mp[mkr(x,y)]=i;
		else update(mp[mkr(x,y)],i-1,mkr(x,y),1,1,n),mp[mkr(x,y)]=0;
	}
	for(pair<pii,int> x:mp)
		if(x.se)update(x.se,n,x.fi,1,1,n);
}

int fa[maxn<<1],szl[maxn<<1],szr[maxn<<1],dep[maxn<<1];
int stx[maxn<<1],sty[maxn<<1],Dep[maxn<<1],top;
ll ans;

inline int fin(int x){ while(x!=fa[x])x=fa[x]; return x;} 

inline void merge(int x,int y)
{
	y+=3e5;
	x=fin(x); y=fin(y);
	if(dep[x]<dep[y])swap(x,y);
	stx[++top]=x; sty[top]=y;
	Dep[x]=dep[x];
	if(x==y)return;
	ans-=1ll*szl[x]*szr[x]+1ll*szl[y]*szr[y];
	szl[x]+=szl[y]; szr[x]+=szr[y]; fa[y]=x;
	chkmax(dep[x],dep[y]+1);
	ans+=1ll*szl[x]*szr[x];
}

inline void undo()
{
	int x=stx[top],y=sty[top],DEEP=Dep[top--];
	if(x==y)return;
	ans-=1ll*szl[x]*szr[x];
	szl[x]-=szl[y]; szr[x]-=szr[y]; fa[y]=y;
	dep[x]=DEEP;
	ans+=1ll*szl[x]*szr[x]+1ll*szl[y]*szr[y];
}

void dfs(int o,int l,int r)
{
	for(pii x:c[o])merge(x.fi,x.se);
	int mid=l+r>>1;
	if(l==r)printf("%lld ",ans);
	else dfs(left),dfs(right);
	for(pii x:c[o])undo();
}

inline void doing()
{
	REP(i,1,3e5)fa[i]=i,szl[i]=1;
	REP(i,3e5+1,3e5+3e5)fa[i]=i,szr[i]=1;
	
	dfs(1,1,n);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}