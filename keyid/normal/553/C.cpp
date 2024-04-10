#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAX=100005,MOD=1000000007;

struct edge
{
    int to,c,next;
}e[MAX*2];

int ec,first[MAX],no[MAX],c[MAX];
bool vis[MAX];
queue <int> q;
vector <int> p[MAX];

void bfs(int s,int number)
{
    vis[s]=true;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        p[number].push_back(u);
        no[u]=number;
        for (int i=first[u];i!=-1;i=e[i].next)
            if (e[i].c)
            {
                int v=e[i].to;
                if (!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
    }
}

bool dfs(int b)
{
    for (int i=0;i<p[b].size();i++)
    {
        int u=p[b][i];
        for (int j=first[u];j!=-1;j=e[j].next)
            if (!e[j].c)
            {
                int v=no[e[j].to];
                if (!c[v])
                {
                    c[v]=3-c[b];
                    if (!dfs(v)) return false;
                }
                else if (c[v]==c[b]) return false;
            }
    }
    return true;
}

inline void addedge(int u,int v,int w)
{
    e[ec]=(edge){v,w,first[u]};
    first[u]=ec++;
}

int main()
{
    memset(first,-1,sizeof(first));
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0,a,b,c;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
        addedge(b,a,c);
    }
    int bc=0;
    for (int i=1;i<=n;i++)
        if (!vis[i])
            bfs(i,bc++);
    int cnt=0;
    for (int i=0;i<bc;i++)
        if (!c[i])
        {
            c[i]=1;
            if (dfs(i)) cnt++;
            else
            {
                putchar('0');
                return 0;
            }           
        }
    int ans=1;
    for (int i=1;i<cnt;i++) ans=ans*2%MOD;
    printf("%d",ans);
    return 0;
}