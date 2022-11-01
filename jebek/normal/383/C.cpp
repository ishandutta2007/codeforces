#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=200000+100;
bool mark[MAXN];
long long b[MAXN],h[MAXN],e[MAXN],n,m,a[MAXN],k,f[2][12*MAXN],ans;
vector<long long>ind,G[MAXN];

void dfs(int v)
{
    mark[v]=true;
    b[v]=ind.size();
    e[v]=ind.size();
    ind.push_back(v);
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            h[u]=1-h[v];
            dfs(u);
            e[v]=ind.size();
            ind.push_back(v);
        }
    }
}

void add(int node,int l,int r,int beg,int en,int val)
{
   // qw++;
  //  if(qw<=20)
     //   cout<<node<<" "<<l<<" "<<r<<" "<<beg<<" "<<en<<" "<<val<<endl;
    if(beg<=l && r<=en)
    {
        f[k][node]+=val;
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) add(2*node,l,mid,beg,min(mid,en),val);
    if(en>mid) add(2*node+1,mid,r,max(mid,beg),en,val);
}

void d(int node,int l,int r,int x)
{
   // cout<<node<<" "<<l<<" "<<r<<" "<<x<<" "<<ans<<" "<<f[k][node]<<" "<<f[1-k][node]<<endl;
    ans+=f[k][node]-f[1-k][node];
    if(l>x || r<=x || l+1>=r)
        return;
    int mid=(l+r)/2;
    if(x<mid)
        d(2*node,l,mid,x);
    else
        d(2*node+1,mid,r,x);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int v,u;
        cin>>v>>u;
        v--;u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(0);
  //  for(int i=0;i<ind.size();i++)
   //    cout<<ind[i]<<" ";
   // cout<<endl;
    for(int i=0;i<m;i++)
    {
     //   cout<<i<<" "<<m<<endl;
        int t;
        cin>>t;
        if(t==1)
        {
            int v,val;
            cin>>v>>val;
            v--;
            k=h[v];
          //  cout<<v<<" "<<k<<" "<<b[v]<<" "<<e[v]<<endl;
            add(1,0,ind.size(),b[v],e[v]+1,val);
        }
        else
        {
            int v;
            cin>>v;
            v--;ans=0;
            k=h[v];
            d(1,0,ind.size(),b[v]);
            cout<<a[v]+ans<<endl;
        }
    }
}