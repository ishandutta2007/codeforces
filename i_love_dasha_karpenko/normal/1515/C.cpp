//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E5+100;
ll h[DIM],ind[DIM];
pair<ll,ll> A[DIM];
void solve(){
    ll n,m,x;
    cin>>n>>m>>x;
    set<pair<ll,ll> > S;
    for(ll i = 1;i<=n;++i){
        cin>>A[i].first;
        A[i].second = i;
    }
    //sort(A+1,A+1+n);
    for(ll i = 1;i<=m;++i){
        h[i] = 0;
        S.insert({0,i});
    }
    ll ptr = 1;
    while(!S.empty() && ptr<=n){
        ll tow = S.begin()->second;
        S.erase(S.begin());
        h[tow]+=A[ptr].first;
        ind[A[ptr].second] = tow;
        ++ptr;
        S.insert({h[tow],tow});
    }
    cout<<"YES\n";
    for(ll i = 1;i<=n;++i){
        cout<<ind[i]<<' ';
    }
    cout<<endl;

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