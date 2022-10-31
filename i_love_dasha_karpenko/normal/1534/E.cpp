//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
const ll DIM = 500+7;
ll need[DIM];
void solve(){
    ll n,k;
    cin>>n>>k;
    ll cur = n;
    for(ll i = 1;i<=n;++i){
        need[i] = 1;
    }
    ll ptr = 1;
    ll mx = 1;
    if (cur%k!=0 || mx>cur/k)
    while(cur<=n*k){
        need[ptr]+=2;
        cur+=2;
        mx = max(mx,need[ptr]);
        ++ptr;
        if (ptr>n)ptr-=n;
        if (cur%k==0 && mx<=cur/k)
            break;
    }
    if (cur%k!=0 || mx>cur/k){
        cout<<"-1"<<endl;
        return;
    }
    ll div = cur/k;
    ll res = 0;
    while(div--){
        vector<pair<ll,ll> > V;
        for(ll i = 1;i<=n;++i)
            V.push_back({need[i],i});
        sort(V.begin(),V.end(),greater<pair<ll,ll>>());
        vector<ll> ask;
        for(ll i = 0;i<k;++i)
            ask.push_back(V[i].second),--need[V[i].second];
        sort(ask.begin(),ask.end());
        cout<<"? ";
        for(ll i = 0;i<k;++i){
            cout<<ask[i]<<' ';
        }
        cout<<endl;
        ll x;
        cin>>x;
        res^=x;
    }
    cout<<"! "<<res<<endl;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    ll t = 1;
    while(t--)
        solve();
    return 0;
}