#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009],n,pr[200009];
ll sg[800009],lz[800009];
void psh(int x,int l,int r)
{
    sg[x]+=lz[x];
    if(l!=r)
    {
        lz[2*x+1]+=lz[x];
        lz[2*x+2]+=lz[x];

    }
    lz[x]=0;
}
void build(int x,int st,int en)
{
    if(st==en){sg[x]=pr[st];return;}
    int mid=(st+en)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    sg[x]=min(sg[2*x+1],sg[2*x+2]);

}
ll cal(int l,int r,int x=0,int st=0,int en=n-1)
{
    psh(x,st,en);
    if(l<=st&&r>=en)return sg[x];
    if(l>en||st>r)return 1000000000;
    int mid=(st+en)/2;
    return min(cal(l,r,2*x+1,st,mid),cal(l,r,2*x+2,mid+1,en));

}
void chn(int l,int r,ll z,int x=0,int st=0,int en=n-1)
{   psh(x,st,en);
    if(l>en||st>r)return;
    if(l<=st&&r>=en){lz[x]+=z;psh(x,st,en);return;}
    int mid=(st+en)/2;
    chn(l,r,z,2*x+1,st,mid);
    chn(l,r,z,2*x+2,mid+1,en);
    sg[x]=min(sg[2*x+1],sg[2*x+2]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    cin>>n;
    vector<pair<ll,ll> >v;
    for(int i=0;i<n;i++){cin>>a[i];
    pr[i]=pr[i-1];
    if(a[i]>=0)ans++,pr[i]+=a[i];
    else v.push_back({-1*a[i],i});
    }
   build(0,0,n-1);
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++)
   {
       ll u=v[i].second,z=v[i].first;
       ll p=cal(u,n-1);
       if(p>=z){chn(u,n-1,-z);ans++;}

   }
  cout<<ans;
}