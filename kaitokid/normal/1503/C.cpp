#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sg[500009];
int mx;
void upd(int l,int r,ll val,int st=0,int en=mx,int x=0)
{
    if(st>=l&&en<=r){if(sg[x]==-1)sg[x]=val;sg[x]=min(sg[x],val);return;}
    if(st>r||en<l)return;
    int md=st+(en-st)/2;
    upd(l,r,val,st,md,2*x+1);
    upd(l,r,val,md+1,en,2*x+2);

}
ll fn(int z,int st=0,int en=mx,int x=0)
{
    ll ans=LLONG_MAX;
    if(sg[x]!=-1)ans=sg[x];
    if(st==en)return ans;
    int md=st+(en-st)/2;
    if(z<=md)ans=min(ans,fn(z,st,md,2*x+1));
    else ans=min(ans,fn(z,md+1,en,2*x+2));
    return ans;

}
ll go(vector<pair<ll,ll> >&v)
{
    memset(sg,-1,sizeof sg);
    mx=v.size();
    int r=upper_bound(v.begin(),v.end(),make_pair(v[0].first,LLONG_MAX))-v.begin()-1;
    upd(0,r,0);
    for(int i=0;i<v.size();i++)
    {
        ll ans=fn(i);
        if(i){ans=min(ans,fn(i-1)+v[i].first-v[i-1].first);}
    int g=upper_bound(v.begin(),v.end(),make_pair(v[i].first+v[i].second,LLONG_MAX))-v.begin()-1;
        upd(i,g,ans);
if(g<mx-1)upd(g+1,g+1,ans+v[g+1].first-v[i].first-v[i].second);
    }
 return fn(v.size()-1);
}
vector<pair<ll,ll> >v;
int main()
{ios::sync_with_stdio(0);
cin.tie(0);
ll n,a,b,x,y;
cin>>n;
ll ans=0;
for(int i=0;i<n;i++)
{
    cin>>x>>y;
    ans+=y;
    v.push_back({x,y});

}
sort(v.begin(),v.end());
ans+=go(v);
cout<<ans<<endl;
    return 0;
}