#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
inline void read(int &x)
{
	int v=0,f=1;char c=getchar();
	while (!isdigit(c)&&c!='-') c=getchar();
	if (c=='-') f=-1; else v=(c&15);
	while (isdigit(c=getchar())) v=(v<<1)+(v<<3)+(c&15);
	x=v*f;
}

int n,m,i,j,dfn[2000005],low[2000005],scc[2000005],ti,cnt,x,y,a,b,stk[2000005],top,rd[2000005];
vector<int> e[2000005];

void tarjan(int x)
{
	stk[++top]=x;
	dfn[x]=low[x]=++ti;
	int i;
	for (i=0;i<e[x].size();i++)
	{
		int y=e[x][i];
		if (dfn[y])
		{
			if (!scc[y]) low[x]=min(low[x],dfn[y]);
		}
		else
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
	}
	if (dfn[x]!=low[x]) return;
	cnt++;stk[top+1]=-1;
	while (stk[top+1]!=x)
	{
		scc[stk[top]]=cnt;
		top--;
	}
	return;
}

void solve()
{
	read(n);read(m); 
	rep(i,n) e[i].clear();
	rep(i,m)
	{
		read(x);read(y); 
		if(x==y) continue;
		e[x].push_back(y); 
	}
	rep(i,n)
	{
		dfn[i]=low[i]=scc[i]=rd[i]=0;
	}
	ti=cnt=top=0;
	rep(i,n) if (!dfn[i]) tarjan(i);
	if (cnt==1)
	{
		puts("No");
		return;
	}
	rep(i,n)
	{
		for (j=0;j<e[i].size();j++)
		{
			if (scc[i]!=scc[e[i][j]]) rd[scc[e[i][j]]]++;
		}
	}
	
	int t2=-1;
	rep(i,cnt)
	{
		if (rd[i]==0) t2=i;
	}
	if(t2==-1) exit(-1);
	vector<int> s1,s2;
	rep(i,n) if(scc[i]==t2) s2.push_back(i); else s1.push_back(i); 
	puts("Yes");
	printf("%d %d\n",s1.size(),s2.size());
	for (i=0;i<s1.size();i++) printf("%d ",s1[i]); puts("");
	for (i=0;i<s2.size();i++) printf("%d ",s2[i]); puts("");
}

int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		solve();
	}
	return 0;
}