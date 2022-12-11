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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

int n;
char str[maxn];

struct Node {
	int s,ls,rs;
};
Node c[maxn<<7];
int ctot;

void update(int x,int d,int &o,int l,int r)
{
	if(!o)o=++ctot;
	c[o].s+=d;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)update(x,d,c[o].ls,l,mid);
	else update(x,d,c[o].rs,mid+1,r);
}

int Merge(int x,int y)
{
	if(!x || !y)return x|y;
	int tmp=++ctot;
	c[tmp].s=c[x].s+c[y].s;
	c[tmp].ls=Merge(c[x].ls,c[y].ls);
	c[tmp].rs=Merge(c[x].rs,c[y].rs);
	return tmp;
}

int query(int ql,int qr,int o,int l,int r)
{
	if(!o)return 0;
	if(ql<=l && r<=qr)return c[o].s;
	int mid=l+r>>1,ans=0;
	if(ql<=mid)ans+=query(ql,qr,c[o].ls,l,mid);
	if(qr>mid)ans+=query(ql,qr,c[o].rs,mid+1,r);
	return ans;
}

struct node {
	int len,fa,ch[26],pos;
};
node t[maxn<<1];
int tot,rt[maxn<<1],last;

inline void Add(int x,int pos)
{
	int p=last,np=last=++tot;
	t[np].pos=pos; t[np].len=t[p].len+1; update(pos,1,rt[np],1,n);
	while(p && !t[p].ch[x])t[p].ch[x]=np,p=t[p].fa;
	if(!p)t[np].fa=1;
	else {
		int q=t[p].ch[x];
		if(t[q].len==t[p].len+1)t[np].fa=q;
		else {
			int nq=++tot; t[nq]=t[q];
			t[nq].len=t[p].len+1;
			t[q].fa=t[np].fa=nq;
			while(p && t[p].ch[x]==q)t[p].ch[x]=nq,p=t[p].fa;
		}
	}
}

int dp[maxn<<1];
vector<int>son[maxn<<1];

void dfs(int u)
{
	for(int v:son[u])
	{
		dfs(v);
		rt[u]=Merge(rt[u],rt[v]);
	}
}

inline void init()
{
	n=read();
	scanf("%s",str+1);
	tot=last=1;
	REP(i,1,n)Add(str[i]-'a',i);
	REP(i,2,tot)son[t[i].fa].push_back(i);
	dfs(1);
}

int ans;

void dfs1(int u,int tp)
{
	for(int v:son[u])
	{
		dp[v]=max(1,dp[tp]+(query(t[v].pos-t[v].len+t[tp].len,t[v].pos,rt[tp],1,n)>=2));
		chkmax(ans,dp[v]);
		dfs1(v,dp[v]==dp[tp]?tp:v);
	}
}

inline void doing()
{
	dfs1(1,1);
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("coolshit.in","r",stdin);
	freopen("coolshit.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}