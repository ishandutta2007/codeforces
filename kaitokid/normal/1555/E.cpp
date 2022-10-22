#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[300009],l[300009],r[300009],id[300009],n,m,sg[10000000],lz[10000000];
bool bl(int x,int y)
{
    return w[x]<w[y];
}
void psh(ll x,ll l,ll r)
{
    sg[x]+=lz[x];
    if(l==r){lz[x]=0;return;}
    lz[2*x+1]+=lz[x];
    lz[2*x+2]+=lz[x];
    lz[x]=0;
    return;
}
void add(ll l,ll r,ll z,ll st=0,ll en=n,ll u=0)
{
    psh(u,st,en);
    if(st>r||l>en)return;
    if(st>=l&&en<=r){lz[u]+=z;psh(u,st,en);return;}
    ll mid=(st+en)/2;
    add(l,r,z,st,mid,2*u+1);
    add(l,r,z,mid+1,en,2*u+2);
    sg[u]=min(sg[2*u+1],sg[2*u+2]);

}
ll cal(ll l,ll r,ll st=0,ll en=n,ll u=0)
{
    psh(u,st,en);
    if(st>r||l>en)return 1000000000;
    if(st>=l&&en<=r)return sg[u];
    ll mid=(st+en)/2;
    return min(cal(l,r,st,mid,2*u+1),cal(l,r,mid+1,en,2*u+2));

}
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>w[i];
        l[i]++;
        id[i]=i;
    }
    sort(id,id+m,bl);
    int i=0,j=0;
    ll ans=1000000000;
    while(i<m)
    {
      if(cal(2,n)==0)
      {
          if(j==m)break;
          add(l[id[j]],r[id[j]],1);
          j++;
      }
      else
      {
          ans=min(ans,w[id[j-1]]-w[id[i]]);
          add(l[id[i]],r[id[i]],-1);
          i++;
      }
    }
    cout<<ans;
    return 0;
}