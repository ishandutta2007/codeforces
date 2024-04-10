#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const int N=100005;
const int M=3000005;

int now[N],next[M],point[M],pos[M],w[M],s[N],ed,ff[N];
int tot,l[N],fa[N],sum[N],faa[N],v[N];
long long ss[N];
map<int,int> ll[N];
int g1[N][21],g2[N][21],g3[N];

void link(int a,int b)
{
	ed++; next[now[a]]=ed; now[a]=ed; point[ed]=b; pos[ed]=ed+1;
	ed++; next[now[b]]=ed; now[b]=ed; point[ed]=a; pos[ed]=ed-1;
}

void link2(int a,int b)
{
	if (a==b) return;
	if (ll[a].count(b)) return;
	ll[a][b]=1;
	ll[b][a]=1;
	ff[fa[a]]++;
	ff[fa[b]]++;
	ed++; next[now[a]]=ed; now[a]=ed; point[ed]=b; w[ed]=2;
	ed++; next[now[b]]=ed; now[b]=ed; point[ed]=a; w[ed]=2;
}

void dfs(int a)
{
	if (v[a]) return;
	v[a]=1;
	int i=next[a];
	int j=point[i];
	while (i!=0)
	{
		if (w[i]==0)
		{
			w[i]=1;
			w[pos[i]]=-1;
			dfs(j);
		}
		i=next[i]; j=point[i];
	}
	tot++;
	l[tot]=a;
}

void dfs2(int a,int qq)
{
	if (!v[a]) return;
	v[a]=0;
	int i=next[a];
	int j=point[i];
	while (i!=0)
	{
		if (w[i]==-1)
		{
			dfs2(j,qq);
		}
		i=next[i]; j=point[i];
	}
	fa[a]=qq;
	sum[qq]++;
}

void dfs3(int a,int qq,int dep)
{
	if (v[a]) return;
	v[a]=1;
	s[a]=s[qq];
	if (sum[a]>1) s[a]++,g2[a][0]++;
	g1[a][0]=qq;
	for (int i=1;;i++)
	{
		g1[a][i]=g1[g1[a][i-1]][i-1];
		if (g1[a][i]==0) break;
		g2[a][i]=g2[a][i-1]+g2[g1[a][i-1]][i-1];
	}
	g3[a]=dep;
	int i=next[a];
	int j=point[i];
	while (i!=0)
	{
		if (w[i]==2)
		{
			dfs3(j,a,dep+1);
		}
		i=next[i]; j=point[i];
	}
}

int ask(int a,int b)
{
	if (g3[a]>g3[b]) swap(a,b);
	int tmp=0;
	for (int i=20;i>=0;i--)
	{
		if (g3[g1[b][i]]>=g3[a])
		{
			tmp+=g2[b][i];
			b=g1[b][i];
		}
	}
	if (a!=b)
	{
		for (int i=20;i>=0;i--)
			if (g1[a][i]!=g1[b][i])
			{
				tmp+=g2[a][i]+g2[b][i];
				a=g1[a][i];
				b=g1[b][i];
			}
		tmp+=g2[a][0]+g2[b][0];
		a=g1[a][0];
	}
	tmp+=g2[a][0];
	return ss[tmp];
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("e.in","r",stdin);
		freopen("e.out","w",stdout);
	#endif
	int n,m; scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) now[i]=i; ed=n;
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		link(a,b);
	}
	dfs(1);
	for (int i=n;i>0;i--) if (v[l[i]])
		dfs2(l[i],l[i]);
	for (int a=1;a<=n;a++)
	{
		int i=next[a];
		int j=point[i];
		while (i!=0)
		{
			if (w[i]==2) break;
			link2(fa[a],fa[j]);
			i=next[i]; j=point[i];
		}
	}
	int i;
	for (i=1;i<=n;i++)
		if (ff[i]==1) break;
	if (ff[i]!=1)
	{
		scanf("%d",&m);
		while (m--)
		{
			printf("%d\n",2);
		}
		return 0;
	}
	dfs3(i,0,1);
	scanf("%d",&m);
	ss[0]=1;
	for (int i=1;i<=n;i++)
	  ss[i]=ss[i-1]*2ll%1000000007;
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",ask(fa[a],fa[b]));
	}
	return 0;
}