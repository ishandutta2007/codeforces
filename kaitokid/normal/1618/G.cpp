#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >v;
ll n,m,q;
ll sum[500009],num[500009],ans[500009],res;
int fr[500009],en[500009];
int frr(int x)
{
    if(fr[x]==x)return x;
    return fr[x]=frr(fr[x]);

}
int enn(int x)
{
    if(en[x]==x)return x;
    return en[x]=enn(en[x]);

}
void mrg(int x)
{
    int r=enn(x+1);
    int l=frr(x);
    ll p=r-x-(num[r]-num[x]);
    ll g=num[x];
    if(l>0)g-=num[l-1];
    ll f=min(g,p);
    ll h=g-f;
    if(x-h>=0)res-=sum[x-h];
    if(x-h-f>=0)res+=sum[x-h-f];
    ll k=p-f;
    res+=sum[x+k+f]-sum[x+k];
    fr[x+1]=l;
    en[x]=r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        res+=x;
        v.push_back({x,1});
    }
    for(int i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        v.push_back({x,0});
    }
    sort(v.begin(),v.end());
    vector<pair<ll,ll> >ed;
    for(int i=0;i<n+m;i++)
    {
        if(i>0){sum[i]=sum[i-1],num[i]=num[i-1];ed.push_back({v[i].first-v[i-1].first,i-1});}
        sum[i]+=v[i].first;
        num[i]+=v[i].second;
        fr[i]=en[i]=i;
    }
    sort(ed.begin(),ed.end());
    vector<pair<ll,ll> >qr;
    for(int i=0;i<q;i++)
    {
        ll x;
        cin>>x;
        qr.push_back({x,i});
    }
    sort(qr.begin(),qr.end());
    int w=0;
    for(int i=0;i<q;i++)
    {
        while(w<ed.size() && ed[w].first<=qr[i].first){mrg(ed[w].second);w++;}
        ans[qr[i].second]=res;
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<endl;


    return 0;
}