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

vector<int>ed[maxn];
int dfn[maxn],low[maxn],times,top[maxn],son[maxn],sz[maxn],fa[maxn],deep[maxn];
int id[maxn];

void dfs(int u)
{
	sz[u]=1;
	for(int v:ed[u])
	{
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
	dfn[u]=++times; id[times]=u;
	if(son[u])top[son[u]]=top[u],dfs1(son[u]);
	for(int v:ed[u])
	{
		if(v==fa[u] || v==son[u])continue;
		top[v]=v;
		dfs1(v);
	}
	low[u]=times;
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

int n;
char str[maxn];
int s[maxn],s1[maxn],p2[maxn];

const int seed=181;
const int mod=1e9+9;

inline void init()
{
	n=read();
	scanf("%s",str+1);
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	deep[1]=1; dfs(1);
	top[1]=1; dfs1(1);
	p2[0]=1; REP(i,1,n)p2[i]=(ll)p2[i-1]*seed%mod;
	REP(i,1,n)s[i]=((ll)s[i-1]*seed+str[id[i]]-'a'+1)%mod;
	DREP(i,n,1)s1[i]=((ll)s1[i+1]*seed+str[id[i]]-'a'+1)%mod;
}

#define pii pair<int,int>

inline vector<pii > Get(int u,int v)
{
	vector<pii >A,B;
	int t=lca(u,v);
	while(top[u]!=top[t])
	{
	 	A.push_back(mkr(dfn[u],dfn[top[u]]));
	 	u=fa[top[u]];
	}
	A.push_back(mkr(dfn[u],dfn[t]));
	while(top[v]!=top[t])
	{
		B.push_back(mkr(dfn[top[v]],dfn[v]));
		v=fa[top[v]];
	}
	if(v!=t)B.push_back(mkr(dfn[t]+1,dfn[v]));
	DREP(i,SZ(B)-1,0)A.push_back(B[i]);
	return A;
}

inline int check(int l,int r)
{
	if(l<=r)return ((s[r]-(ll)s[l-1]*p2[r-l+1])%mod+mod)%mod;
	else return ((s1[r]-(ll)s1[l+1]*p2[l-r+1])%mod+mod)%mod;
}

inline int Lowerbound(int l1,int r1,int l2,int r2)
{
	int len=abs(r1-l1)+1;
	int l=0,r=len-1;
	while(l<r)
	{
		int mid=l+r+1>>1;
		int R1=l1<=r1?l1+mid-1:l1-mid+1,R2=l2<=r2?l2+mid-1:l2-mid+1;
		if(check(l1,R1)==check(l2,R2))l=mid;
		else r=mid-1;
	}
	return l;
}

inline void doing()
{
	int q=read();
	while(q--)
	{
		int a=read(),b=read(); vector<pii >A=Get(a,b);
		int c=read(),d=read(); vector<pii >B=Get(c,d);

		int ans=0;
		for(int i=0,j=0;i<SZ(A) && j<SZ(B);)
		{
			int lena=abs(A[i].se-A[i].fi)+1,lenb=abs(B[j].se-B[j].fi)+1;
			int l1=A[i].fi,r1=A[i].se,l2=B[j].fi,r2=B[j].se;
			int len=min(lena,lenb);
			int R1,R1n,R2,R2n;
			if(l1<=r1)R1=l1+len-1,R1n=l1+len;
			else R1=l1-len+1,R1n=l1-len;
			if(l2<=r2)R2=l2+len-1,R2n=l2+len;
			else R2=l2-len+1,R2n=l2-len;
			if(lena==lenb)
			{
				if(check(l1,r1)==check(l2,r2))i++,j++,ans+=len;
				else { ans+=Lowerbound(l1,r1,l2,r2); break;}
			}
			else if(lena<lenb)
			{
				if(check(l1,R1)==check(l2,R2))i++,B[j].fi=R2n,ans+=len;
				else { ans+=Lowerbound(l1,R1,l2,R2); break;}
			}else
			{
				if(check(l1,R1)==check(l2,R2))j++,A[i].fi=R1n,ans+=len;
				else { ans+=Lowerbound(l1,R1,l2,R2); break;}
			}
		}
		printf("%d\n",ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF504E.in","r",stdin);
	freopen("CF504E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}