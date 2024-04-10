#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#define moder 1e9 + 7 
using namespace std ;
const int N = 1e5 +10 ;
vector <int> G[N] ;
stack <int> S ;
bool vis[N] ;
int belong[N],low[N],dfn[N],num[N],b[N],a[N] ;
int dfn_max=0,scc=0,n,m,k ; 

void Tarjan(int now)
{
    dfn[now]=low[now]=++dfn_max;
    S.push(now),vis[now]=true ; 
    for (int i=0;i<G[now].size();i++)
	{
        int to=G[now][i] ;
        if (!dfn[to]){
            Tarjan(to) ;
            low[now]=min(low[now],low[to]) ;
        }
        else if (vis[to]) low[now]=min(low[now],dfn[to]);
    }
    if (dfn[now]==low[now])
	{
        scc++ ;
        while (1){
            int x=S.top();S.pop() ;
            belong[x]=scc ;
            num[scc]++ ;
            if (x==now) break ;
        }
    }
    return ;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k) ;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for (int i=1;i<=m;i++) {
        int u,v ;
        scanf("%d%d",&u,&v) ;
        if ((a[u]+1)%k==a[v]) G[u].push_back(v) ;
        if ((a[v]+1)%k==a[u]) G[v].push_back(u) ;
    }
    for (int i=1;i<=n;i++)
    if (!dfn[i]) Tarjan(i) ;
    for (int i=1;i<=n;i++)
	{
        for (int j=0;j<G[i].size();j++)
		{
            int x=G[i][j] ;
            if (belong[x]!=belong[i]) b[belong[i]]++ ;
        }
    }
    int ans,MINI=moder;
    for (int i=1;i<=n;i++)
	{
        if (!b[belong[i]] && num[belong[i]]<MINI)
		{
            MINI=num[belong[i]] ;
            ans=belong[i] ; 
        }
    }
    printf("%d\n",MINI) ;
    for (int i=1;i<=n;i++)
    if (ans==belong[i]) printf("%d ",i) ;
    return 0 ; 
}