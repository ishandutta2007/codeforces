#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=150005,SIGMA=26;

vector <int> G[MAXN],T[MAXN];
int cnt,fa[MAXN],d[MAXN],id[MAXN],sum[MAXN][SIGMA],sa[MAXN],mx[MAXN][SIGMA],D;
char c[MAXN];

void dfs1(int u,int dep)
{
	if (G[u].size()==0)
		if (!D)
			D=dep;
		else if (D!=dep)
			D=-1;
	for (const int &v:G[u])
	{
		dfs1(v,dep+1);
		d[u]=max(d[u],d[v]);
	}
	d[u]++;
}

void update(int v,int c)
{
	for (;;)
	{
		if (sa[v]>=d[v])
			cnt--;
		sa[v]-=mx[v][c];
		mx[v][c]=0;
		for (const int &t:T[v])
			mx[v][c]=max(mx[v][c],mx[t][c]+sum[t][c]);
		sa[v]+=mx[v][c];
		if (sa[v]>=d[v])
			cnt++;
		if (v==1)
			break;
		v=fa[v];
	}
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif // KeyID
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		char s[5];
		scanf("%d%s",&fa[i],s);
		G[fa[i]].pb(i);
		c[i]=s[0];
	}
	dfs1(1,0);
	if (D==-1)
		for (int i=0;i<q;i++)
			puts("Fou");
	else
	{
		for (int i=1;i<=n;i++)
			id[i]=i;
		for (int i=2;i<=n;i++)
			if (G[i].size()!=1)
			{
				int &x=fa[i];
				if (c[i]!='?')
					sum[i][c[i]-'a']++;
				while (x!=1&&G[x].size()==1)
				{
					id[x]=i;
					if (c[x]!='?')
						sum[i][c[x]-'a']++;
					x=fa[x];
				}
				T[x].pb(i);
			}
		for (int i=n;i>=1;i--)
			if (id[i]==i)
			{
				for (const auto &v:T[i])
					for (int j=0;j<SIGMA;j++)
						mx[i][j]=max(mx[i][j],mx[v][j]+sum[v][j]);
				int &s=sa[i];
				for (int j=0;j<SIGMA;j++)
					s+=mx[i][j];
				if (s>=d[i])
					cnt++;
			}
		while (q--)
		{
			int v;
			char s[5];
			scanf("%d%s",&v,s);
			if (c[v]!='?')
			{
				sum[id[v]][c[v]-'a']--;
				update(fa[id[v]],c[v]-'a');
			}
			c[v]=s[0];
			if (c[v]!='?')
			{
				sum[id[v]][c[v]-'a']++;
				update(fa[id[v]],c[v]-'a');
			}
			if (cnt)
				puts("Fou");
			else
			{
				int ans=0;
				for (int i=0;i<SIGMA;i++)
					ans+=(i+1)*(d[1]-1-sa[1]+mx[1][i]);
				printf("Shi %d\n",ans);
			}
		}
	}
	return 0;
}