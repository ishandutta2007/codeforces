#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 57;
ll dp[DIM],vv[DIM],sz[DIM],enl;
ll solve(ll level,ll tl,ll tr,ll l,ll r){
    if (l<=tl && tr<=r)
        return dp[level];
    if (tl>r || tr<l)return 0;
    return solve(level+1,tl,tl+sz[level+1]-1,l,r)+solve(enl+(vv[level]%2==0),tl+sz[level+1],tl+sz[level+1],l,r) + solve(level+1,tl+sz[level+1]+1,tr,l,r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,l,r;
    cin>>n>>l>>r;
    if (n==0){
        cout<<0<<endl;
        return 0;
    }
    ll cur = n;
    ll level = 0;
    while(cur>1){
        vv[level] = cur;
        cur/=2;
        ++level;
    }
    dp[level] = 1;
    vv[level] = 1;
    sz[level] = 1;
    enl = level;
    for(ll i = level-1;i>=0;--i){
        dp[i] = dp[i+1]*2+vv[i]%2;
        sz[i] = sz[i+1]*2+1;
    }
    cout<<solve(0,1,sz[0],l,r)<<endl;
    return 0;

}