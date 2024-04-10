#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef unsigned long long ll;
typedef pair<ll,ll>pll;
ll lim=2e16,sm=1.1e18;
ll p[19];
ll solve(ll x){
    x++;
    ll ans=0;
    for(int i=16;i>=0;i--){
        ll d=x/p[i]%10;
        ans+=d*(d-1)/2*p[i]+d*i*9*p[i]/2+d*(x%p[i]);
    }
    return ans;
}
int main(){
    ll m;
    cin>>m;
    p[0]=1;
    for(ll i=1;i<19;i++)p[i]=p[i-1]*10;
    while(1){
        ll x=rngll()%lim;
        ll v=solve(x);
        ll nxt=sm/m*m+v;
        ll cur=0;
        for(ll i=1LL<<54;i;i>>=1){
            if(solve(cur+i)<=nxt)cur+=i;
        }
        if(solve(cur)==nxt){
            printf("%lld %lld",x+1,cur);
            return 0;
        }
    }
}