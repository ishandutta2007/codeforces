#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair <LL,int> pli;

const int MAX=300005;
const LL INF=1LL<<60;

struct edge
{
    int u,v,w,id;
}e[MAX];

struct edge2
{
    int to,w,next,id;
}e2[MAX*2];

int n,m,ec,ec2,first[MAX],p[MAX];
LL d[MAX];
priority_queue <pli,vector<pli>,greater<pli> > q;
vector <int> r;

void dijkstra(int s)
{
    fill(d+1,d+n+1,INF);
    d[s]=0;
    q.push(make_pair(0,s));
    while (!q.empty())
    {
        pli x=q.top();q.pop();
        int u=x.second;
        if (x.first!=d[u]) continue;
        for (int i=first[u];i!=-1;i=e2[i].next)
        {
            int v=e2[i].to;
            if (d[v]>x.first+e2[i].w)
            {
                d[v]=x.first+e2[i].w;
                q.push(make_pair(d[v],v));
            }
        }
    }
}

inline void addedge(int u,int v,int w,int id)
{
    e2[ec2]=(edge2){v,w,first[u],id};
    first[u]=ec2++;
}

int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}

bool cmp(edge a,edge b)
{
    return d[a.v]!=d[b.v]?d[a.v]<d[b.v]:a.w<b.w;
}

int main()
{
    memset(first,-1,sizeof(first));
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w,i+1);
        addedge(v,u,w,i+1);
    }
    int s;
    scanf("%d",&s);
    dijkstra(s);
    for (int u=1;u<=n;u++)
        for (int i=first[u];i!=-1;i=e2[i].next)
        {
            int v=e2[i].to;
            if (d[u]+e2[i].w==d[v]) e[ec++]=(edge){u,v,e2[i].w,e2[i].id};
        }
    LL ans=0;
    for (int i=1;i<=n;i++) p[i]=i;
    sort(e,e+ec,cmp);
    for (int i=0;i<ec;i++)
    {
        int x=find(e[i].u),y=find(e[i].v);
        if (x!=y)
        {
            p[x]=y;
            ans+=e[i].w;
            r.push_back(e[i].id);
        }
    }
    printf("%I64d\n",ans);
    for (int i=0;i<r.size();i++) printf("%d ",r[i]);
    return 0;
}