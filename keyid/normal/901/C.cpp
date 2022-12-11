#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=300005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int ec,first[MAXN],pos[MAXN],fa[MAXN],ch[MAXN][2],top,sta[MAXN];
bool rev[MAXN];
LL sum[MAXN];

void addedge(int u,int v)
{
	e[ec]={v,first[u]};
	first[u]=ec++;
}

bool isroot(int u)
{
	return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;
}

void push_down(int o)
{
	if (rev[o])
	{
		rev[o]=false;
		rev[ch[o][0]]^=1;
		rev[ch[o][1]]^=1;
		swap(ch[o][0],ch[o][1]);
	}
}

void rotate(int x)
{
	int y=fa[x],z=fa[y],d=(ch[y][1]==x);
	if (!isroot(y))
		ch[z][ch[z][1]==y]=x;
	ch[y][d]=ch[x][d^1];
	ch[x][d^1]=y;
	fa[ch[y][d]]=y;
	fa[y]=x;
	fa[x]=z;
}

void splay(int u)
{
	sta[top=0]=u;
	for (int i=u;!isroot(i);i=fa[i])
		sta[++top]=fa[i];
	for (int i=top;i>=0;i--)
		push_down(sta[i]);
	while (!isroot(u))
	{
		int y=fa[u];
		if (!isroot(y))
			if ((ch[y][0]==u)!=(ch[fa[y]][0]==y))
				rotate(u);
			else
				rotate(y);
		rotate(u);
	}
}

void access(int u)
{
	int t=0;
	while (u)
	{
		splay(u);
		ch[u][1]=t;
		t=u;
		u=fa[u];
	}
}

void evert(int u)
{
	access(u);
	splay(u);
	rev[u]^=1;
}

void link(int u,int v)
{
	evert(u);
	fa[u]=v;
}

void cut(int u,int v)
{
	evert(u);
	access(v);
	splay(v);
	ch[v][0]=fa[u]=0;
}

int find(int u)
{
	access(u);
	splay(u);
	while (ch[u][0]) u=ch[u][0];
	splay(u);
	return u;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		first[i]=-1;
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	int head=1;
	sum[1]=1;
	pos[1]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=first[i];j!=-1;j=e[j].nxt)
			if (e[j].to>=head&&e[j].to<=i)
			{
				while (find(i)==find(e[j].to))
				{
					for (int k=first[head];k!=-1;k=e[k].nxt)
						if (e[k].to>=head&&e[k].to<=i)
							cut(head,e[k].to);
					pos[++head]=i;
				}
				if (e[j].to>=head)
					link(e[j].to,i);
			}
		sum[i]=sum[i-1]+i-head+1;
	}
	while (head<=n)
		pos[++head]=n+1;
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int k=pos[l];
		if (k>r)
			printf("%lld\n",(r-l+2LL)*(r-l+1)/2);
		else
			printf("%lld\n",sum[r]-sum[k-1]+(k-l+1LL)*(k-l)/2);
	}
	return 0;
}