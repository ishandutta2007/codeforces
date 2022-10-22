#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx=300003;
pair<ll,ll> sg[2000000];
ll d[2000000];
ll ans[2000000];
ll n,x;
pair<ll,ll>mrg(pair<ll,ll> a,pair<ll,ll> b)
{
    return {a.first+b.first,a.second+ b.second};
}
pair<ll,ll>go(int l,int r,int st=0,int en=mx,int i=0)
{
    if(l<=st&&r>=en)return sg[i];
    if(l>en|| r<st)return {0,0};
    int mid=(st+en)/2;
    return mrg(go(l,r,st,mid,2*i+1),go(l,r,mid+1,en,2*i+2));
}
void chn(int x,int st=0,int en=mx,int i=0)
{
    if(x<st||x>en)return ;
    if(st==en){sg[i]={1,x};return ;}
    int mid=(st+en)/2;
    chn(x,st,mid,2*i+1);
    chn(x,mid+1,en,2*i+2);
    sg[i]=mrg(sg[2*i+1],sg[2*i+2]);
}
void add(int l,int r,ll z,int st=0,int en=mx,int i=0)
{
    if(l>en||st>r)return;
    if(l<=st&& r>=en){d[i]+=z;return;}
    int mid=(st+en)/2;
    add(l,r,z,st,mid,2*i+1);
    add(l,r,z,mid+1,en,2*i+2);

}
ll cal(int x,int st=0,int en=mx,int i=0)
{
    if(x<st||x>en)return 0;
    if(st==en)return d[i];
    int mid=(st+en)/2;
    return d[i]+cal(x,st,mid,2*i+1)+cal(x,mid+1,en,2*i+2);


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ans[i]=ans[i-1];
        ans[i]+=go(0,x-1).second;
        ans[i]+=go(x+1,mx).first*x;
        //cout<<ans[i]<<" ";
        for(int j=1;x*j<=mx;j++)
        {
            pair<ll,ll> g=go((j*x+1),min(mx,(j+1)*x-1));
            ans[i]+=g.second - g.first * (j*x);
        }
        //cout<<ans[i]<<" ";
        //cout<<cal(x)<<endl;
        ans[i]+=go(0,x-1).first* x -cal(x);
       // cout<<ans[i]<<endl;
        chn(x);
        for(int j=1;x*j<=mx;j++)
        {
            add(j*x,min(x*(j+1)-1,mx),j*x);
        }
    cout<<ans[i]<<" ";
    }
    return 0;
}