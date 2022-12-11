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

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int deep[maxn],son[maxn],fa[maxn],sz[maxn],top[maxn],dfn[maxn],low[maxn],times,down[maxn];
int n,m;

void dfs(int u)
{
	sz[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		deep[v]=deep[u]+1;
		fa[v]=u;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}

void dfs1(int u)
{
	dfn[u]=++times;
	if(son[u])top[son[u]]=top[u],dfs1(son[u]),down[u]=down[son[u]];
	else down[u]=deep[u];
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u] || v==son[u])continue;
		top[v]=v;
		dfs1(v);
	}
}

inline int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(deep[top[u]]>deep[top[v]])swap(u,v);
		v=fa[top[v]];
	}
	if(deep[u]>deep[v])swap(u,v);
	return u;
}

inline void init()
{
	n=read();m=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	deep[1]=1; dfs(1);
	top[1]=1; dfs1(1);
}

const double eps=1e-9;

struct line {
	double k,b;
	double t1,t2;
	int id;
};

inline double Intersection(line l1,line l2)
{
	if(l1.k==l2.k)
	{
		if(fabs(l1.b-l2.b)<eps)return max(l1.t1,l2.t1);
		else return 1e18;
	}
	return (l1.b-l2.b)/(l2.k-l1.k);
}

vector<line>num[maxn];

double ans;

struct Modify {
	double pos;
	int op,id;
};
Modify md[maxn<<3];
int mtot;

double NOW;

struct cmp {
	inline bool operator () (line a,line b)const { return a.k*NOW+a.b==b.k*NOW+b.b?a.id<b.id:a.k*NOW+a.b<b.k*NOW+b.b;}
};

set<line,cmp>s;
set<line,cmp>::iterator it,itt,ittt;

inline void solve(int id)
{
	double tmp=1e18;
	vector<line>f;
	f=num[id];
	REP(i,0,SZ(f)-1)f[i].id=i;
	mtot=0;
	REP(i,0,SZ(f)-1)md[++mtot]=(Modify){f[i].t1,1,i},md[++mtot]=(Modify){f[i].t2,-1,i};
	sort(md+1,md+1+mtot,[](Modify a,Modify b){ return fabs(a.pos-b.pos)<eps?a.op>b.op:a.pos<b.pos;});
	s.clear();
	REP(i,1,mtot)
	{
		NOW=md[i].pos;
		if(NOW-eps>=tmp)return;
		int id=md[i].id;
		if(md[i].op==1)
		{
			s.insert(f[id]);
			it=s.lower_bound(f[id]);
			if(it!=s.begin())
			{
				itt=it; itt--;
				double sect=Intersection(*itt,*it);
				if(sect>=NOW-eps && sect-eps<=it->t2 && sect-eps<=itt->t2)chkmin(tmp,sect),chkmin(ans,sect);
			}
			if(it!=(--s.end()))
			{
				itt=it; itt++;
				double sect=Intersection(*itt,*it);
				if(sect>=NOW-eps && sect-eps<=it->t2 && sect-eps<=itt->t2)chkmin(tmp,sect),chkmin(ans,sect);
			}
		}else
		{
			it=s.lower_bound(f[id]);
			if(it!=s.begin() && it!=(--s.end()))
			{
				itt=it; itt--; it++;
				double sect=Intersection(*itt,*it);
				if(sect>=NOW-eps && sect-eps<=it->t2 && sect-eps<=itt->t2)chkmin(tmp,sect),chkmin(ans,sect);
			}
			s.erase(f[id]);
		}
	}
}

inline void doing()
{
	REP(i,1,m)
	{
		double tim,times;scanf("%lf",&tim);
		int c=read(),u=read(),v=read(),t=lca(u,v);
		int DIS=(deep[u]+deep[v]-deep[t]*2);
		//cerr<<t<<endl;
		times=tim;
		line now; int dis;
		while(top[u]!=top[t])
		{
			dis=deep[u]-deep[top[u]]+1;
			now.k=c; now.b=down[u]-deep[u]-times*c;
			now.t1=times; times+=(1.*dis/c); now.t2=times;
			num[top[u]].push_back(now);
			u=fa[top[u]];
		}
		dis=deep[u]-deep[t];
		now.k=c; now.b=down[u]-deep[u]-times*c;
		now.t1=times; times+=(1.*dis/c); now.t2=times;
		num[top[u]].push_back(now);

		times=tim+DIS*1./c;
		while(top[v]!=top[t])
		{
			dis=deep[v]-deep[top[v]]+1;
			now.k=-c; now.b=down[v]-deep[v]+times*c;
			now.t2=times; times-=dis*1./c; now.t1=times; 
			num[top[v]].push_back(now);
			v=fa[top[v]];
		}
		dis=deep[v]-deep[t];
		now.k=-c; now.b=down[v]-deep[v]+times*c;
		now.t2=times+1e-8; times-=dis*1./c; now.t1=times+1e-8;  
		num[top[v]].push_back(now);
		v=fa[top[v]];
	}
	ans=1e18;
	REP(i,1,n)if(SZ(num[i])>0)
		solve(i);
	if(ans!=1e18)printf("%.8lf\n",ans);
	else puts("-1");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}