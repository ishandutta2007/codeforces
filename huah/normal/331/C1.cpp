#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
map<pair<ll,ll>,pair<ll,ll> >mp;
pair<ll,ll> dfs(ll n,ll mx)
{
    if(mp[{n,mx}].first) return mp[{n,mx}];
    if(n<10) return {n||mx,max(mx,n)-n};
    ll m=1;
    while(m<=n/10) m*=10;
    ll p=n/m;
    m*=p;
    pair<ll,ll>a=dfs(n-m,max(p,mx)),b=dfs(m-a.second,mx);
    /*
        1222,1000222
        1000->99,222022
        99->90,9,20->18,22->20,2
        .....
    */
    return mp[{n,mx}]={a.first+b.first,b.second};
}
int main()
{
    scanf("%lld",&n);
    printf("%lld\n",dfs(n,0).first);
}