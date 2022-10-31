#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll INF = 1E18;
const ll DIM = 5000+7;
const ll MOD = 1E9+7;
ll A[DIM],mult[DIM],fact[DIM],rev[DIM],dp[DIM][DIM],olddp[DIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k,q;
    cin>>n>>k>>q;
    for(ll i = 1;i<=n;++i){
        dp[0][i] = 1;
    }
    for(ll st = 1;st<=k;++st){
        for(ll pos = 1;pos<=n;++pos){
            dp[st][pos] = (dp[st-1][pos-1]+dp[st-1][pos+1])%MOD;
        }
    }
    for(ll i = 1;i<=n;++i){
        for(ll step = 0;step<=k;++step){
            mult[i] = (mult[i]+dp[step][i]*dp[k-step][i])%MOD;
        }
    }
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        res = (res+A[i]*mult[i])%MOD;
    }
    while(q--){
        ll pos,val;
        cin>>pos>>val;
        res = (MOD+(res+mult[pos]*(val-A[pos]))%MOD)%MOD;
        A[pos] = val;
        cout<<res<<endl;
    }

    return 0;
}