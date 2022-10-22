#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sg[800009];
ll lf[800009],rg[800009];
int b[200009],a[200009],n;
void build(int x=0,int st=1,int en=n)
{
    if(st==en)
    {
        if(b[st]==1){sg[x]=lf[x]=rg[x]=1;return;}

        sg[x]=1;
        lf[x]=rg[x]=0;
        return;
    }
    int mid=(st+en)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    sg[x]=sg[2*x+1]+sg[2*x+2]+(rg[2*x+1]+(rg[2*x+1]!=(mid-st+1)))*lf[2*x+2];
    lf[x]=lf[2*x+1];
    if(lf[x]==mid-st+1)lf[x]+=lf[2*x+2];
    rg[x]=rg[2*x+2];
    if(rg[x]==en-mid)rg[x]+=rg[2*x+1];
//cout<<x<<" "<<st<<" "<<en<<" "<<lf[x]<<" "<<rg[x]<<" "<<sg[x]<<endl;
}
pair<pair<ll,int>,pair<ll,ll> >cal(int l,int r,int x=0,int st=1,int en=n)
{
    if(l>en||st>r)return {{0,1},{0,0}};
    if(st>=l && en<=r)return {{sg[x],(int)(lf[x]==(en-st+1))},{lf[x],rg[x]}};
    int mid=(st+en)/2;
    pair<pair<ll,int>,pair<ll,ll> > u=cal(l,r,2*x+1,st,mid),v=cal(l,r,2*x+2,mid+1,en);
    ll h=u.first.first+v.first.first + (u.second.second+1-u.first.second)*(v.second.first);
    int d= (u.first.second & v.first.second);
    ll lft=u.second.first;
    if(u.first.second)lft+=v.second.first;
    ll rgt=v.second.second;
    if(v.first.second)rgt+=u.second.second;
    return {{h,d},{lft,rgt}};

}
void chn(int u,int x=0,int st=1,int en=n)
{
    if(st==en)
    {
        if(b[st]==1){sg[x]=lf[x]=rg[x]=1;return;}

        sg[x]=1;
        lf[x]=rg[x]=0;
        return;

    }
    int mid=(st+en)/2;
    if(u<=mid)chn(u,2*x+1,st,mid);
    else chn(u,2*x+2,mid+1,en);
 sg[x]=sg[2*x+1]+sg[2*x+2]+(rg[2*x+1]+(rg[2*x+1]!=(mid-st+1)))*lf[2*x+2];
    lf[x]=lf[2*x+1];
    if(lf[x]==mid-st+1)lf[x]+=lf[2*x+2];
    rg[x]=rg[2*x+2];
    if(rg[x]==en-mid)rg[x]+=rg[2*x+1];

}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int q;
cin>>n>>q;
for(int i=1;i<=n;i++){cin>>a[i];
b[i]=(a[i]>=a[i-1]);
}
build();
while(q--)
{
    int t;
    cin>>t;
    if(t==2)
    {
        int l,r;
        cin>>l>>r;
        cout<<cal(l,r).first.first<<endl;
    continue;
    }
    int x;
    cin>>x;
    cin>>a[x];
    b[x]=(a[x]>=a[x-1]);
    b[x+1]=(a[x+1]>=a[x]);
    chn(x);
    if(x!=n)chn(x+1);
}


    return 0;

}