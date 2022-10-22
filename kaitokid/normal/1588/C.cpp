#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll>sg[1500009][2];
ll lz[1500009][2],n;
pair<ll,ll>mrg(pair<ll,ll>x,pair<ll,ll>y)
{
    if(x.first==y.first)return {x.first,x.second+y.second};
    return min(x,y);
}
void psh(int u,int st,int en,int id)
{
    sg[u][id].first+=lz[u][id];
    if(st!=en)
    {
        lz[2*u+1][id]+=lz[u][id];
        lz[2*u+2][id]+=lz[u][id];

    }
    lz[u][id]=0;
}
void build(int id,int st=0,int en=n/2,int u=0)
{
    lz[u][id]=0;
    if(st==en){sg[u][id]={0,1};return;}
    int mid=(st+en)/2;
    build(id,st,mid,2*u+1);
    build(id,mid+1,en,2*u+2);
    sg[u][id]=mrg(sg[2*u+1][id],sg[2*u+2][id]);

}
void upd(int l,int r,int id,ll val,int st=0,int en=n/2,int u=0)
{
    psh(u,st,en,id);
    if(l>en||st>r)return;
    if(st>=l&& en<=r){lz[u][id]+=val;
    psh(u,st,en,id);
    return;}
    int mid=(st+en)/2;
    upd(l,r,id,val,st,mid,2*u+1);
    upd(l,r,id,val,mid+1,en,2*u+2);
    sg[u][id]=mrg(sg[2*u+1][id],sg[2*u+2][id]);
}
int go(int id,int st=0,int en=n/2,int u=0)
{
    psh(u,st,en,id);
    if(sg[u][id].first>=0)return st;
    if(st==en)return n+10;
    int mid=(st+en)/2;
    int p=go(id,mid+1,en,2*u+2);
    if(p!=mid+1)return p;
    p=min(p,go(id,st,mid,2*u+1));
    return p;
}
pair<ll,ll>cal(int l,int r,int id,int st=0,int en=n/2,int u=0)
{
    if(l>r)return {0,0};
    psh(u,st,en,id);
    if(l>en||st>r)return {0,0};
    if(st>=l&&en<=r)return sg[u][id];
    int mid=(st+en)/2;
    return mrg(cal(l,r,id,st,mid,2*u+1),cal(l,r,id,mid+1,en,2*u+2));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
         cin>>n;
         build(0);
         build(1);
    ll ans=0;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==0 && i%2==0)ans++;
       upd(0,i/2,i%2,x);
       if(i>0) upd(0,(i-1)/2,(i-1)%2,-x);
        int u=go(0);
        int v=go(1);
        u=max(u,v);
        v=max(v,u-1);
        //cout<<i<<" "<<u<<" "<<v<<endl;
        pair<ll,ll>g;
     if(i>0)    g=cal(u,(i-1)/2,0);
        if(g.first==0)ans+=g.second;
      //  cout<<g.first<<" "<<g.second<<endl;
        if(i>0) {g=cal(v,(i-1)/2,1);
        //cout<<g.first<<" "<<g.second<<endl;
        if(g.first==0)ans+=g.second;}
    }

    cout<<ans<<endl;
    }
    return 0;
}