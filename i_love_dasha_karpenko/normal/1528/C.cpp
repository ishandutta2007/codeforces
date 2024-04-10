//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;
vector<ll> G[DIM],H[DIM];
pair<ll,ll> del[DIM];
ll tin[DIM],tout[DIM],timer = 0,res = 0;
void dfsh(ll v){
    tin[v] = ++timer;
    for(ll to:H[v]){
        dfsh(to);
    }
    tout[v] = ++timer;
}
set<pair<ll,ll> > S;
void dfsg(ll v){
    {
        auto it = S.lower_bound({tin[v],0});
        if (!S.empty() && it!=S.begin()){
            it = prev(it);
            if (it->second>=tout[v]) {
                del[v] = *it;
                S.erase(it);
            }
        }
    }
    {
        auto it = S.lower_bound({tin[v],INF});
        if (!(it!=S.end() && it->second<=tout[v]))
            S.insert({tin[v],tout[v]});
    }
    for(ll to:G[v]){
        dfsg(to);
    }
    res = max(res,ll(S.size()));
    S.erase({tin[v],tout[v]});
    if (del[v]!=pair<ll,ll>{0,0})
        S.insert(del[v]);
    del[v] = {0,0};
}
ll solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<n;++i){
        ll par;
        cin>>par;
        G[par].push_back(i+1);
    }
    for(ll i = 1;i<n;++i){
        ll par;
        cin>>par;
        H[par].push_back(i+1);
    }
    timer = res = 0;
    dfsh(1);
    dfsg(1);
    for(ll i = 1;i<=n;++i){
        G[i].clear();
        H[i].clear();
    }
    cout<<res<<endl;
    return 0;
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