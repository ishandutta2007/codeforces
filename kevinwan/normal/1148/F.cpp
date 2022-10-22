#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int mn=3e5+10;
pll v[mn];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    ll sum=0;
    for(i=0;i<n;i++)scanf("%lld%lld",&v[i].second,&v[i].first),sum+=v[i].second;
    if(sum>0){
        for(i=0;i<n;i++)v[i].second*=-1;
    }
    sort(v,v+n);
    ll ans=0;
    sum=0;
    for(i=0;i<n;i=j){
        ll ssum=0;
        for(j=i;j<n&&__builtin_clzll(v[i].first)==__builtin_clzll(v[j].first);j++){
            if(__builtin_popcountll(v[j].first&ans)&1)ssum-=v[j].second;
            else ssum+=v[j].second;
        }
        if(sum-ssum>0){
            sum-=ssum;
            ans|=1LL<<63-__builtin_clzll(v[i].first);
        }
        else{
            sum+=ssum;
        }
    }
    printf("%lld",ans);
}