#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=410;
ll p3[31];
map<pll,ll>dp;
ll solve(ll a,ll b){
    if(a<b)swap(a,b);
    else if(b==0)return a+1;
    else if(dp.count({a,b}))return dp[{a,b}];
    if(__builtin_clzll(a)<__builtin_clzll(b)){
        ll b2=1LL<<64-__builtin_clzll(b);
        return dp[{a,b}]=a/b2*solve(b2-1,b)+solve(a%b2,b);
    }
    else{
        ll b2=1LL<<63-__builtin_clzll(b);
        return dp[{a,b}]=solve(a,b2-1)+solve(b,b2-1)-p3[63-__builtin_clzll(b2)];
    }
}
int main(){
    int tc;
    scanf("%d",&tc);
    p3[0]=1;
    for(int i=1;i<=30;i++)p3[i]=p3[i-1]*3;
    while(tc--){
        ll l,r;
        scanf("%lld%lld",&l,&r);
        if(l)printf("%lld\n", solve(r,r)-2*solve(l-1,r)+solve(l-1,l-1));
        else printf("%lld\n",solve(r,r));
    }
}