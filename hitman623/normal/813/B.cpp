#include <bits/stdc++.h>
#define pb push_back
#define lll long double
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < lll >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    io;
    lll x,y,l,r,tx,ty,ans=0;
    int ll,uu,j,i;
    cin>>x>>y>>l>>r;
    map < lll , long > mp;
    vl v;
    tx=1;
    while(tx<=r)
    {
        ty=1;
        while(ty<=r)
        {
            if(tx+ty>r) break;
            if(mp[tx+ty]==0)
            v.pb(tx+ty);
            mp[tx+ty]=1;
            ty*=y;
        }
        tx*=x;
    }
    sort(v.begin(),v.end());
    uu=upper_bound(v.begin(),v.end(),r)-v.begin();
    ll=lower_bound(v.begin(),v.end(),l)-v.begin();
    if(uu==0) { cout<<r-l+1;exit(0);}
    ans=max(ans,v[ll]-l);
    if(v[uu-1]>=l)
    ans=max(ans,r-v[uu-1]);
    else ans=max(ans,r-l+1);
    for(i=ll;i<uu-1;++i)
    ans=max(ans,v[i+1]-v[i]-1);
    cout<<(long long )ans;
    return 0;
}