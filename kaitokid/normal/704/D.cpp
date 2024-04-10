#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define neigh(u,e,v) for(int e=head[u],v;~e&&(v=to[e],1);e=nxt[e])

const int N=300000,E=2e6;
int head[N],nxt[E],to[E],cap[E],edgcnt=0,n,src,snk;
int vis[N],vid=0,work[N],dist[N],q[N];

int addEdge(int a,int b,int c)
{
    nxt[edgcnt]=head[a];
    to[edgcnt]=b;
    cap[edgcnt]=c;
    head[a]=edgcnt;
    return edgcnt++;
}
int addAug(int a,int b,int c,int d=0)
{
    addEdge(a,b,c);
    return addEdge(b,a,d);
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
            if(v==snk)
                return true;
            q[qsize++]=v;
        }
    }
    //return vis[snk]==vid;
    return false;
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
int nn,m,r,b,x[100009],y[100009],id[100009];
int lmx[100009],lmy[100009],frx[100009],fry[100009];
int main()
{
    scanf("%d%d%d%d",&nn,&m,&r,&b);
    vector<int>hsx,hsy,hssx,hssy;
    for(int i=0;i<nn;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        hsx.push_back(x[i]);
        hsy.push_back(y[i]);
    }
    sort(hsx.begin(),hsx.end());
    sort(hsy.begin(),hsy.end());
    hssx.push_back(hsx[0]);
    hssy.push_back(hsy[0]);
    for(int i=1;i<nn;i++)
    {
        if(hsx[i]>hsx[i-1])hssx.push_back(hsx[i]);
        if(hsy[i]>hsy[i-1])hssy.push_back(hsy[i]);
    }
    int xnum=hssx.size();
    int ynum=hssy.size();
    n=xnum+ynum+4;
    src=n-1;
    snk=n-2;
    int ss=n-3,tt=n-4;
    init();
    for(int i=0;i<nn;i++)
    {
        x[i]=lower_bound(hssx.begin(),hssx.end(),x[i])-hssx.begin();
        y[i]=lower_bound(hssy.begin(),hssy.end(),y[i])-hssy.begin();
        frx[x[i]]++,lmx[x[i]]++;
        fry[y[i]]++,lmy[y[i]]++;
        id[i]=addAug(x[i],xnum+y[i],1);
    }
    for(int i=0;i<m;i++)
    {
        int t,l,d;
        scanf("%d%d%d",&t,&l,&d);
        int g=l;
        if(t==1)
        {

            l=lower_bound(hssx.begin(),hssx.end(),l)-hssx.begin();
            if(l==xnum)continue;
            if(hssx[l]!=g)continue;
            lmx[l]=min(lmx[l],d);
            continue;
        }
        l=lower_bound(hssy.begin(),hssy.end(),l)-hssy.begin();
        if(l==ynum)continue;
        if(hssy[l]!=g)continue;
        lmy[l]=min(lmy[l],d);


    }
    int smx=0,smy=0;
    for(int i=0;i<xnum;i++)
    {
        int mn=(frx[i]-lmx[i]+1)/2;
        int mx=(frx[i]+lmx[i])/2;
        if(mx<mn){printf("-1");return 0;}
        addAug(ss,i,mx-mn);
        addAug(src,i,mn);
        smx+=mn;
    }
    for(int i=0;i<ynum;i++)
    {
        int mn=(fry[i]-lmy[i]+1)/2;
        int mx=(fry[i]+lmy[i])/2;
        if(mx<mn){printf("-1");return 0;}
        addAug(i+xnum,tt,mx-mn);
        addAug(i+xnum,snk,mn);
        smy+=mn;
    }
    addAug(ss,snk,smx);
    addAug(src,tt,smy);
    int z=addAug(tt,ss,INT_MAX);
    int ff=dinic();
    if(ff<smx+smy){printf("-1");return 0;}
    int ans=cap[z];
    cap[z]=cap[z^1]=0;
    src=ss;
    snk=tt;
    ans+=dinic();
    ll res=nn*1LL*max(r,b);
    res-=ans*1LL*abs(r-b);
    char lw='r',hg='b';
    if(b<r)swap(lw,hg);
    printf("%lld\n",res);
    for(int i=0;i<nn;i++)
    {
        if(cap[id[i]])printf("%c",lw);
        else printf("%c",hg);

    }

    return 0;
}