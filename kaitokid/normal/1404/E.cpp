#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
#define neigh(u,e,v) for(int e=head[u],v;~e&&(v=to[e],1);e=nxt[e])

const int N=4e4+5,E=1e6+6,M=N;
int head[N],nxt[E],to[E],edgcnt=0,n,m;
int vis[N],vid=0;
int l2r[N],r2l[M],dist[N];

void addEdge(int a,int b)
{
    nxt[edgcnt]=head[a];
    to[edgcnt]=b;
    head[a]=edgcnt++;
}

void init()
{
    memset(head,-1,n*sizeof(head[0]));
    edgcnt=0;
}

bool bfs()
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(l2r[i]==-1)
        {
            q.push(i);
            dist[i]=0;
        }
        else
            dist[i]=-1;
    }
    int g=INT_MAX;
    while(q.size())
    {
        int lid=q.front();
        q.pop();
        if(dist[lid]>=g)continue;
        neigh(lid,e,rid)
        {
            int newlid=r2l[rid];
            if(newlid==-1 ){g=min(g,dist[lid+1]);continue;}
            if(newlid!=-1&&dist[newlid]==-1)
            {
                dist[newlid]=dist[lid]+1;
                q.push(newlid);
            }
        }
    }
    return (g!=INT_MAX);
}

int dfs(int lid)
{
    neigh(lid,e,rid)
    {
        if(r2l[rid]!=-1&&dist[lid]+1!=dist[r2l[rid]])
            continue;
        if(r2l[rid]==-1||dfs(r2l[rid]))
        {
            r2l[rid]=lid;
            l2r[lid]=rid;
            return 1;
        }
    }
    dist[lid]=1000000000;
    return 0;
}

int maxMatching()
{
    int res=0;
    memset(r2l,-1,m*sizeof(r2l[0]));
    memset(l2r,-1,n*sizeof(l2r[0]));

    while(bfs())
    {

        for(int i=0;i<n;i++)
            if(dist[i]==0&&dfs(i))
                res++;

    }
    return res;
}
char s[209][209];
int dw[209][209],rg[209][209];
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf("%s",s[i]);
    for(int i=0;i+1<r;i++)
        for(int j=0;j<c;j++)
        if(s[i][j]=='#' && s[i+1][j]=='#')dw[i][j]=++n;
    for(int i=0;i<r;i++)
        for(int j=0;j+1<c;j++)
        if(s[i][j]=='#' && s[i][j+1]=='#')rg[i][j]=++m;
    init();
    int num=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
    {
        if(s[i][j]=='#')num++;
        if(!dw[i][j])continue;
        if(rg[i][j])addEdge(dw[i][j]-1,rg[i][j]-1);
        if(j>0 && rg[i][j-1])addEdge(dw[i][j]-1,rg[i][j-1]-1);
        if(i+1<r && rg[i+1][j])addEdge(dw[i][j]-1,rg[i+1][j]-1);
        if(j>0 && i+1<r && rg[i+1][j-1])addEdge(dw[i][j]-1,rg[i+1][j-1]-1);

    }
    int res=n+m-maxMatching();
    res=num-res;
    printf("%d",res);
	return 0;
}