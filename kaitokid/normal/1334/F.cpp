#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,a[500009],m,b[500009],q[500009],p[500009],res,sg[2000009],lz[2000009];
void rf(int x,int l,int r)
{
    if(l==r){
            if(sg[x]==-1e18){lz[x]=0;return;}
            sg[x]+=lz[x];lz[x]=0;return;}
    lz[2*x]+=lz[x];
    lz[2*x+1]+=lz[x];
    lz[x]=0;
}
void build(int x,int l,int r)
{

    if(l==r&&l==0){sg[x]=0;return;}
    if(l==r){sg[x]=-1e18;return;}
    int mid=(l+r)/2;
    build(2*x,l,mid);
    build(2*x+1,mid+1,r);
}
ll go(int x,int l,int r,int v)
{
    rf(x,l,r);

if(l==r)return sg[x];
int mid=(l+r)/2;
if(v<=mid)return go(2*x,l,mid,v);
return go(2*x+1,mid+1,r,v);
}
void ch(int x,int l,int r,int u,ll v)
{
    rf(x,l,r);
    if(l==r){sg[x]=max(sg[x],v);return;}
int mid=(l+r)/2;
if(u<=mid) ch(2*x,l,mid,u,v);
 else ch(2*x+1,mid+1,r,u,v);

}
void co(int x,int l,int r,int fr,int en,ll v)
{
    rf(x,l,r);
    if(l>en||r<fr)return;
    if(l>=fr&&r<=en){lz[x]+=v;return;}
    int mid=(l+r)/2;
    co(2*x,l,mid,fr,en,v);
    co(2*x+1,mid+1,r,fr,en,v);
}
int main()
{ios::sync_with_stdio(0);
cin>>n;
memset(q,-1,sizeof q);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++){cin>>p[i];res+=p[i];}
cin>>m;
for(int i=0;i<m;i++)
cin>>b[i];
q[b[0]]=0;
for(int i=1;i<m;i++)q[b[i]]=b[i-1];
build(1,0,n);

for(int i=0;i<n;i++)
{

    if(p[i]>0){co(1,0,n,a[i],n,p[i]);}

    if(q[a[i]]!=-1)
    {ll u=go(1,0,n,q[a[i]]);

  if(u>-1e18)  ch(1,0,n,a[i],u+p[i]);}


}
ll u=go(1,0,n,b[m-1]);
if(u==-1e18)cout<<"NO";
else cout<<"YES\n"<<res-u;
    return 0;
}