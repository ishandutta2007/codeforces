#include <cstdio>

using namespace std;

const int N=1e5+10;

struct Edge{int to,next,cost;} way[N<<1];
int n,m,tot,num[N];
bool vis[N];

struct Base
{
    int x[31];
    inline void Insert(int v)
    {
        if (!v) return ;
        for (int i=30;i>=0;--i)
            if ((1<<i)&v)
            {
                if (x[i]) v^=x[i];
                else { x[i]=v; break; }
            }
    }
    inline int Query(int v)
    {
        for (int i=30;i>=0;--i)
            if ((v^x[i])<v) v^=x[i];
        return v;
    }

}base; 

inline void AddEdge(int a,int b,int c){way[++tot]=(Edge){b,num[a],c}; num[a]=tot;}

inline void Init()
{
    scanf("%d%d",&n,&m);
    int u,v,cost;
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&cost);
        AddEdge(u,v,cost);
        AddEdge(v,u,cost);  
    }
}

int dis[N];

void Dfs(int x)
{
    vis[x]=1;
    for (int i=num[x];i;i=way[i].next)
    {
        int v=way[i].to;
        if(!vis[v])
        {
            dis[v]=dis[x]^way[i].cost;
            Dfs(v);
        }else base.Insert(dis[v]^dis[x]^way[i].cost);
    }
}

inline void Solve()
{
    Dfs(1);
    printf("%d\n",base.Query(dis[n]));
}

int main()
{
	Init();
    Solve();
    return 0;
}