#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int mn=1e6+10;
pll p[mn];
bool comp(const pll&a,const pll&b){
    return a.first-a.second>b.first-b.second;
}
int main()
{
    int n,a,b,i;
    scanf("%d%d%d",&n,&a,&b);
    ll bes=0;
    for(i=0;i<n;i++)scanf("%lld%lld",&p[i].first,&p[i].second);
    sort(p,p+n,comp);
    b=min(b,n);
    for(i=0;i<b;i++)bes+=max(p[i].first,p[i].second);
    ll lalt;
    if(b)lalt=max(p[b-1].first,p[b-1].second)-p[b-1].second;
    for(i=b;i<n;i++)bes+=p[i].second;
    ll balt=0,alt=0;
    for(i=0;i<b;i++){
        alt=(p[i].first<<a)-max(p[i].first,p[i].second);
        balt=max(alt,balt);
    }
    if(b){
        for(i=b;i<n;i++){
            alt=(p[i].first<<a)-p[i].second-lalt;
            balt=max(alt,balt);
        }
    }
    printf("%lld",bes+balt);
}