#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=1000005;

int id;
char s[MAXN];
string nme[MAXN];
vector <int> G[MAXN],p[MAXN];

int getson(int u,int pos)
{
	int f=0;
	while (isdigit(s[pos])) f=f*10+s[pos++]-'0';
	pos++;
	for (int i=0;i<f;i++)
	{
		int l=pos;
		while (isalpha(s[l++]));
		nme[++id].assign(s+pos,s+l-1);
		G[u].pb(id);
		pos=getson(id,l);
	}
	return pos;
}

int dfs(int u,int dep)
{
	int maxdep=dep;
	p[dep].pb(u);
	for (int i=0;i<G[u].size();i++)
		maxdep=max(maxdep,dfs(G[u][i],dep+1));
	return maxdep;
}

int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for (int i=0;i<len;)
	{
		int l=i;
		while (isalpha(s[l++]));
		nme[++id].assign(s+i,s+l-1);
		G[0].pb(id);
		i=getson(id,l);
	}
	int d=dfs(0,0);
	printf("%d\n",d);
	for (int i=1;i<=d;i++)
	{
		for (int j=0;j<p[i].size();j++)
			cout << nme[p[i][j]] << ' ';
		puts("");
	}
	return 0;
}