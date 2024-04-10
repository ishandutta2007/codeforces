#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ed[200009];
ll pr[200009][25],lv[200009],sz[200009],sum[200009],n;
int go(int x,int p,int l)
{
    lv[x]=l;
    pr[x][0]=p;
    sz[x]=1;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)sz[x]+=go(ed[x][i],x,l+1);
        return sz[x];
}
int anc(int x,int k)
{
    for(int i=24;i>=0;i--)
        if(k&(1<<i))x=pr[x][i];
    return x;
}
bool isan(int p,int ch)
{
    if(lv[p]>lv[ch])return false;
    return (anc(ch,lv[ch]-lv[p])==p);
}
ll cal(vector<int>&g)
{
    if(g.empty())
    {
        ll res=n*(n-1)/2;
        for(int i=0;i<ed[0].size();i++)
        {   int u=ed[0][i];
            res-=(sz[u]*(sz[u]-1))/2;}
            return res;
                }

       if(g.size()==1)
       {
           ll p=n;
           ll u=anc(g[0],lv[g[0]]-1);
           p-=sz[u];
           p*=sz[g[0]];
           return p;
       }
     if(g.size()==2)
     {
         ll u=anc(g[0],lv[g[0]]-1);
         ll v=anc(g[1],lv[g[1]]-1);
         if(u==v)return 0;
         return sz[g[0]]*sz[g[1]];

     }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n+2;i++)
        {
            ed[i].clear();
            sum[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        go(0,0,0);
       for(int i=1;i<25;i++)
          for(int j=0;j<n;j++)
          pr[j][i]=pr[pr[j][i-1]][i-1];
      vector<int>g;
      for(int i=0;i<n;i++)
      {
          sum[i]=cal(g);
          if(i==n)break;
          for(int j=0;j<=g.size();j++)
          {
              if(j==g.size()){g.push_back(i+1);break;}
              if(isan(i+1,g[j]))break;
              if(isan(g[j],i+1)){g[j]=i+1;break;}
          }
         if(g.size()>2)break;
      }
     cout<<n*(n-1)/2-sum[0]<<" ";
     for(int i=1;i<n;i++)cout<<sum[i-1]-sum[i]<<" ";
     cout<<sum[n-1]<<endl;
    }
}