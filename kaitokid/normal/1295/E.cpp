#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,p[200009],a[200009],sg[2000009],lazy[2000009],v[200009],ans=1e18;
void rf(int l,int r,int x)
{
    sg[x]+=lazy[x];
    if(l!=r){lazy[2*x]+=lazy[x];lazy[2*x+1]+=lazy[x];}
    lazy[x]=0;
}
void build (int l,int r,int x)
{
    if(l==r){sg[x]=a[l];return;}
    int mid=(l+r)/2;
    build(l,mid,2*x);
    build(mid+1,r,2*x+1);
    sg[x]=min(sg[2*x],sg[2*x+1]);
}

void chn(int l,int r,int fr,int en,int x,ll z)
{
    rf(l,r,x);
    if(l>en||fr>r)return ;
    if(l>=fr&&r<=en){lazy[x]+=z;rf(l,r,x);return;}
    int mid=(l+r)/2;
    chn(l,mid,fr,en,2*x,z);
    chn(mid+1,r,fr,en,2*x+1,z);
 sg[x]=min(sg[2*x],sg[2*x+1]);

}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)cin>>a[p[i]];
    for(int i=1;i<=n;i++){v[i]=a[i];a[i]=a[i]+a[i-1];}
    build(0,n,1);

    for(int i=0;i<n-1;i++)
    {
        chn(0,n,p[i],n,1,-v[p[i]]);
        chn(0,n,0,p[i]-1,1,v[p[i]]);
        ans=min(ans,sg[1]+lazy[1]);
    }
    cout<<ans;
return 0;
}