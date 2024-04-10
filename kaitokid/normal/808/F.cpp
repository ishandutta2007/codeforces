#include<bits/stdc++.h>
using namespace std;
#define neigh(u,e,v) for(int e=head[u],v;~e&&(v=to[e],1);e=nxt[e])

const int N=300,E=2e4;
int head[N],nxt[E],to[E],cap[E],edgcnt=0,n,src,snk;
int vis[N],vid=0,work[N],dist[N],q[N];

void addEdge(int a,int b,int c)
{
    nxt[edgcnt]=head[a];
    to[edgcnt]=b;
    cap[edgcnt]=c;
    head[a]=edgcnt++;
}
void addAug(int a,int b,int c,int d=0)
{
    addEdge(a,b,c);
    addEdge(b,a,d);
}


void init()
{
    memset(head,-1,n*sizeof(head[0]));
    edgcnt=0;
}

int dfs(int u=src,int fl=INT_MAX)
{
    if(u==snk)
        return fl;
    vis[u]=vid;
    for(int &e=work[u];~e;e=nxt[e])
    {
        int v=to[e];
        if(dist[u]+1!=dist[v]||!cap[e])
            continue;
        int f=dfs(v,min(fl,cap[e]));
        if(f)
        {
            cap[e]-=f;
            cap[e^1]+=f;
            return f;
        }
    }
    return 0;
}

bool bfs()
{
    vid++;
    vis[src]=vid;
    q[0]=src;
    dist[src]=0;
    int qsize=1;
    for(int i=0;i<qsize;i++)
    {
        int u=q[i];
        neigh(u,e,v)
        {
            if(vis[v]==vid||!cap[e])
                continue;
            vis[v]=vid;
            dist[v]=dist[u]+1;
            /*if(v==snk)
                return true;*/
            q[qsize++]=v;
        }
    }
    return vis[snk]==vid;
    //return false;
}

int dinic()
{
    int res=0,flow;
    while(bfs())
    {
        memcpy(work,head,n*sizeof(head[0]));
        while(flow=dfs())
            res+=flow;
    }
    return res;
}
bool ntp[1000009];
vector<pair<int,pair<int,int> > >v;
int k;
bool ch(int x)
{
    int u=0;
    for(int i=0;i<v.size();i++)
        if(v[i].first>x)break;
        else u++;
   n=2*u+2;
   src=n-1;
   snk=n-2;
   init();
   int sum=0;
   for(int i=0;i<u;i++)
   {
       sum+=2*v[i].second.first;
       addAug(src,i,v[i].second.first);
       addAug(i+u,snk,v[i].second.first);
   }
   for(int i=0;i<u;i++)
    for(int j=i+1;j<u;j++)
   {
       if(ntp[v[i].second.second+v[j].second.second])continue;
       addAug(i,u+j,INT_MAX);
       addAug(j,i+u,INT_MAX);
   }

   int rs=(sum-dinic())/2;
   return (rs>=k);

}
int main()
{
    for(int i=2;i<1000;i++)
    {
        if(ntp[i])continue;
        for(int j=i*i;j<=1000000;j+=i)ntp[j]=true;
    }
    int nn,x,y,z;
    scanf("%d %d",&nn,&k);
    for(int i=0;i<nn;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        v.push_back({z,{x,y}});
    }
    sort(v.begin(),v.end());
    if(!ch(nn)){printf("-1");return 0;}
    int l=1,r=nn;
    while(r>l)
    {
        int mid=(l+r)/2;
        if(ch(mid))r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}