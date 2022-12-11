#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;
const int seed=141937;
const int mod=998244353;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn],rd[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n;

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
		rd[u]++; rd[v]++;
	}
}

int f[maxn];
int st[maxn],tp;
int stu[maxn];

void dfs(int u,int fa)
{
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		if(f[v]==-1)f[u]=-1;
	}
	if(~f[u])
	{
		tp=0; EREP(i,u)if(e[i].v!=fa)st[++tp]=f[e[i].v];
		int flg=0;
		REP(i,1,tp)if(st[i]!=st[1]){ flg=1;break;}
		if(flg)f[u]=-1;
		else f[u]=st[tp];
		if(~f[u])f[u]=((ll)f[u]*seed+rd[u])%mod;
	}
}


void dfs1(int u,int fa)
{
	tp=0; EREP(i,u)if(e[i].v!=fa)st[++tp]=f[e[i].v],stu[tp]=e[i].v;
	if(fa)st[++tp]=f[u];

	int num1=0,a=-1,b=-1,an=0,bn=0,all=0;
	REP(i,1,tp)
	{
		num1+=st[i]==-1;
		if(~st[i])
		{
			if(a==-1)a=st[i],an++,all++;
			else if(a==st[i])++an;
			else if(b==-1)b=st[i],bn++,all++;
			else if(b==st[i])++bn;
			else num1++;
		}
	}

	if(num1==0 && all<=1)printf("%d\n",u),exit(0);
	
	REP(i,1,tp-(fa>0))
		if(num1-(st[i]==-1)>=1)f[stu[i]]=-1;
		else
		{
			if(a==st[i])--an,all-=an==0;
			if(b==st[i])--bn,all-=bn==0;
			if(all==0)f[stu[i]]=0;
			else if(all==1)
			{
				if(an>0)f[stu[i]]=a;
				else f[stu[i]]=b;
			}else f[stu[i]]=-1;
			if(a==st[i])++an,all+=an==1;
			if(b==st[i])++bn,all+=bn==1;
		}
	REP(i,1,tp-(fa>0))if(~f[stu[i]])f[stu[i]]=((ll)f[stu[i]]*seed+rd[u])%mod;
	EREP(i,u)if(e[i].v!=fa)dfs1(e[i].v,u);
}

inline void doing()
{
	dfs(1,0);
	dfs1(1,0);
	puts("-1");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}