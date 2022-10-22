#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll v[mn],psa[mn];
int bes;
ll ans,m,a,thres;
ll solve(int n){
    if(n==0)return a;
    int cur=0;
    for(int i=1<<17;i;i>>=1){
        if(cur+i>=n)continue;
        if(v[cur+i]*(cur+i)-psa[cur+i-1]<=m)cur+=i;
    }
    ll l=m-(v[cur]*(cur)-psa[cur-1]);
    ll lo=v[cur]+l/(cur+1);
    lo=min(a,lo);
    return lo;
}
ll pr[mn];
pair<ll,int> s[mn];
int main()
{
    int n,cf,cm,i,j;
    scanf("%d%d%d%d%lld",&n,&a,&cf,&cm,&m);
    for(i=0;i<n;i++)scanf("%lld",v+i);
    for(i=0;i<n;i++)s[i]={v[i],i};
    sort(s,s+n);
    sort(v,v+n);
    psa[0]=v[0];
    for(i=1;i<n;i++)psa[i]=psa[i-1]+v[i];
    for(i=0;i<=n;i++){
        if(i)m-=a-v[n-i];
        if(m<0)break;
        ll pt=solve(n-i);
        ll poss=pt*cm+i*cf;
        if(poss>ans){
            bes=i,ans=poss,thres=pt;
        }
    }
    for(i=0;i<n-bes;i++)if(s[i].first<thres)s[i].first=thres;
    for(i=n-bes;i<n;i++)s[i].first=a;
    for(i=0;i<n;i++)pr[s[i].second]=s[i].first;
    printf("%lld\n",ans);
    for(i=0;i<n;i++)printf("%lld ",pr[i]);
}