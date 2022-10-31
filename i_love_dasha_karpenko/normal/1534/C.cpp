//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 4E5+7;
const ll MOD = 1E9+7;
ll A[DIM],P[DIM];
ll F(ll x){
    if (x==P[x])
        return x;
    return P[x] = F(P[x]);
}
void unite(ll a,ll b){
    a = F(a);
    b = F(b);
    P[a] = b;
}
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i],P[i] = i;
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
        unite(A[i],x);
    }
    ll res = 1;
    for(ll i = 1;i<=n;++i){
        if (F(i)==i)
            res*=2;
        if (res>=MOD)
            res-=MOD;
    }
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}