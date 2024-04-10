#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;

struct edge
{
    int from,to,next,flow,cap;
};

int a[MAXN],b[MAXN],res[MAXN][MAXN];

struct Dinic
{
    static const int MAX=205,MAXM=1405,INF=0x3f3f3f3f;

    edge edges[MAXM];
    int ec,s,t,first[MAX],cur[MAX],d[MAX];
    queue <int> q;

    void init(int n)
    {
        s=0;
        t=2*n+1;
        memset(first,-1,sizeof(first));
    }

    void addedge(int from,int to,int flow)
    {
        edges[ec]=(edge){from,to,first[from],flow,0};
        first[from]=ec++;
        edges[ec]=(edge){to,from,first[to],0,0};
        first[to]=ec++;
    }

    bool BFS()
    {
        memset(d,0x3f,sizeof(d));
        d[s]=0;
        q.push(s);
        while (!q.empty())
        {
            int u=q.front();q.pop();
            for (int i=first[u];i!=-1;i=edges[i].next)
            {
                edge &e=edges[i];
                if (d[e.to]==INF&&e.flow-e.cap>0)
                {
                    d[e.to]=d[u]+1;
                    q.push(e.to);
                }
            }
        }
        return d[t]<INF;
    }

    int DFS(int u,int a)
    {
        if (u==t||a==0) return a;
        int flow=0,f;
        for (int& i=cur[u];i!=-1;i=edges[i].next)
        {
            edge &e=edges[i];
            if (d[e.to]==d[u]+1&&(f=DFS(e.to,min(a,e.flow-e.cap)))>0)
            {
                e.cap+=f;
                edges[i^1].cap-=f;
                flow+=f;
                a-=f;
                if (a==0) return flow;
            }
        }
        return flow;
    }

    int Maxflow()
    {
        int flow=0;
        while (BFS())
        {
            memcpy(cur,first,sizeof(first));
            flow+=DFS(s,INF);
        }
        return flow;
    }

}dinic;

int main()
{
    int n,m,sum1=0,sum2=0;
    scanf("%d%d",&n,&m);
    dinic.init(n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum1+=a[i];
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        sum2+=b[i];
    }
    if (sum1!=sum2)
    {
        printf("NO");
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        dinic.addedge(dinic.s,i,a[i]);
        dinic.addedge(i,i+n,a[i]);
        dinic.addedge(i+n,dinic.t,b[i]);
    }
    for (int i=0;i<m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        dinic.addedge(p,q+n,a[p]);
        dinic.addedge(q,p+n,a[q]);
    }
    if (dinic.Maxflow()!=sum1) printf("NO");
    else
    {
        printf("YES\n");
        for (int i=0;i<dinic.ec;i++)
        {
            edge e=dinic.edges[i];
            if (e.from>=1&&e.from<=n&&e.to>n&&e.to<dinic.t)
                res[e.from][e.to-n]=e.cap;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++) printf("%d ",res[i][j]);
            printf("\n");
        }
    }
    return 0;
}