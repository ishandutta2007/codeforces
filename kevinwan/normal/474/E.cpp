#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
typedef long long ll;
typedef pair<ll,ll> pll;
int u;
ll h[mn];
vector<ll> p;
pll seg[mn*2],dp[mn];
map<ll,int> comp;
void update(int a,pll b){
    seg[a+=u]=b;
    for(a>>=1;a;a>>=1)seg[a]=max(seg[a*2],seg[a*2+1]);
}
pll query(int a,int b){
    pll ans={-1,-1};
    for(a+=u,b+=u;a<=b;a++,b--,a>>=1,b>>=1){
        if(a&1)ans=max(ans,seg[a]);
        if(!(b&1))ans=max(ans,seg[b]);
    }
    return ans;
}
int main()
{
    int n,i;
    ll d;
    scanf("%d%lld",&n,&d);
    for(i=0;i<n;i++)scanf("%lld",h+i),p.push_back(h[i]);
    p.push_back(-0x3f3f3f3f3f3f3f3f);
    p.push_back(0x3f3f3f3f3f3f3f3f);
    sort(p.begin(),p.end());
    p.resize(u=distance(p.begin(),unique(p.begin(),p.end())));
    for(i=0;i<u;i++)comp[p[i]]=i;
    memset(seg,-1,sizeof(seg));
    for(i=n-1;i>=0;i--){
        dp[i]=max(query(0,comp[*--upper_bound(p.begin(),p.end(),h[i]-d)]),
                    query(comp[*lower_bound(p.begin(),p.end(),h[i]+d)],u-1));
        dp[i].first++;
        pll base={1,-1};
        if(base>dp[i])dp[i]=base;
        update(comp[h[i]],{dp[i].first,i});
    }
    int st=seg[1].second;
    printf("%lld\n",dp[st].first);
    while(st!=-1){
        printf("%lld ",st+1);
        st=dp[st].second;
    }
}