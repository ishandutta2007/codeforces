#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 1000005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,m,N,M,i,j;
char c[MAXN];
namespace tar
{
typedef long long lld;
const int MaxN = 1000000 + 10, MaxE = MaxN*4;
int head[MaxN], pre[MaxN], dom[MaxN], to[MaxE], nxt[MaxE], top;
void addedge(int *h,int fr,int tt)
{
    top ++;
    nxt[top] = h[fr];
    to[top] = tt;
    h[fr] = top;
}
int n, m;
int bcj[MaxN], semi[MaxN], idom[MaxN], best[MaxN], dfn[MaxN], id[MaxN], fa[MaxN], dfs_clock;
int push(int v)
{
    if(v == bcj[v]) return v;
    int y = push(bcj[v]);
    if(dfn[semi[best[bcj[v]]]] < dfn[semi[best[v]]]) best[v] = best[bcj[v]];
    return bcj[v] = y;
}//
void dfs(int rt)
{
    dfn[rt] = ++dfs_clock;
    id[dfs_clock] = rt;
    for(int i = head[rt]; i; i = nxt[i])
        if(!dfn[to[i]])
        {
            dfs(to[i]);
            fa[to[i]] = rt;
        }

}//dfs
void tarjan()
{
    for(int i = dfs_clock, u; i >= 2; --i)
    {//dfs
        u = id[i];
        for(int j = pre[u]; j; j = nxt[j])//semi
        {
            if(!dfn[to[j]]) continue;
            push(to[j]);
            if(dfn[semi[best[to[j]]]] < dfn[semi[u]]) semi[u] = semi[best[to[j]]];
        }
        addedge(dom, semi[u], u);
        bcj[u] = fa[u];u = id[i - 1];
        for(int j = dom[u]; j; j = nxt[j])//idom
        {
            push(to[j]);
            if(semi[best[to[j]]] == u) idom[to[j]] = u;
            else idom[to[j]] = best[to[j]];
        }
    }
    for(int i = 2, u; i <= dfs_clock; ++i)
    {
        u = id[i];
        if(idom[u] != semi[u]) idom[u] = idom[idom[u]];
    }
}
void solve()
{
    for(int i = 1; i <= n; ++i) bcj[i] = semi[i] = best[i] = i;
    dfs_clock = 0;
    dfs(1);
    tarjan();
}
};
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%s",c+(i-1)*m+1);
	N=n*m;
	tar::n=n*m;
	for(i=1;i<=n;i++)for(j=1;j<m;j++)if(c[(i-1)*m+j]=='.'&&c[(i-1)*m+j+1]=='.')
	{
		tar::addedge(tar::head,(i-1)*m+j,(i-1)*m+j+1);
		tar::addedge(tar::pre,(i-1)*m+j+1,(i-1)*m+j);
	}
	for(i=1;i<n;i++)for(j=1;j<=m;j++)if(c[(i-1)*m+j]=='.'&&c[i*m+j]=='.')
	{
		tar::addedge(tar::head,(i-1)*m+j,i*m+j);
		tar::addedge(tar::pre,i*m+j,(i-1)*m+j);
	}
	tar::solve();
	if(!tar::dfn[n*m])puts("0");
	else if(tar::idom[n*m]!=1)puts("1");
	else puts("2");
	return 0;
}