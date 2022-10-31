#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll INF = 1E18;
const ll DIM = 3E3+7;
const ll LOG = 40;
ll dp[LOG][DIM],olddp[DIM],res = 0;
vector<ll> V[DIM];
ll n,k;
void solve(ll l,ll r,ll level){
    if (l>r)return;
    if (l==r){
        for(ll i = max(0ll,k-V[l].size()+1);i<=k;++i){
            res = max(res,dp[level][i]+V[l][k-i]);
        }
        return;
    }
    ll tm = (l+r)/2;

    for(ll len = 1;len<=k;++len){
        dp[level+1][len] = 0;
        olddp[len] = dp[level][len];
    }
    for(ll i = tm+1;i<=r;++i){
        for(ll len = ll(V[i].size())-1;len<=k;++len){
            dp[level+1][len] = max(dp[level+1][len],ll(olddp[len-V[i].size()+1]+V[i].back()));
        }
        for(ll len = 1;len<=k;++len){
            olddp[len] = max(olddp[len],dp[level+1][len]);
            dp[level+1][len] = 0;
        }
    }
    for(ll len = 1;len<=k;++len){
        dp[level+1][len] = olddp[len];
    }
    solve(l,tm,level+1);
    for(ll len = 1;len<=k;++len){
        dp[level+1][len] = 0;
        olddp[len] = dp[level][len];
    }
    for(ll i = l;i<=tm;++i){
        for(ll len = ll(V[i].size())-1;len<=k;++len){
            dp[level+1][len] = max(dp[level+1][len],ll(olddp[len-V[i].size()+1]+V[i].back()));
        }
        for(ll len = 1;len<=k;++len){
            olddp[len] = max(olddp[len],dp[level+1][len]);
            dp[level+1][len] = 0;
        }
    }
    for(ll len = 1;len<=k;++len){
        dp[level+1][len] = olddp[len];
    }
    solve(tm+1,r,level+1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(ll i = 1;i<=n;++i){
        ll len;
        cin>>len;
        V[i].resize(len+1);
        V[i][0] = 0;
        for(ll j = 1;j<=len;++j){
            cin>>V[i][j];
            V[i][j]+=V[i][j-1];
        }

    }
    solve(1,n,0);
    cout<<res<<endl;
    return 0;

}