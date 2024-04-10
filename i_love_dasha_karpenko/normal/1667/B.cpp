#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll INF = 1e18;
void solve(){
    int n;
    cin>>n;
    ll pref = 0;
    set<pair<ll,ll> > Neg = {{0,0}},Pos = {{0,0}};
    map<ll,ll> Zero;
    Zero[0] = 0;
    for(int i = 1;i<=n;++i) {
        int a; cin>>a;
        pref += a;
        ll dp = -INF;
        {
            auto it = Pos.lower_bound({pref,-INF});
            if (!Pos.empty() && it!=Pos.begin()){
                it = prev(it);
                dp = max(dp,it->second+i);
            }
        }
        {
            auto it = Neg.lower_bound({pref,INF});
            if (it!=Neg.end()){
                dp = max(dp,it->second-i);
            }
        }
        if (Zero.count(pref)) {
            dp = max(dp, Zero[pref]);
        }
        if (i==n){
            cout<<dp<<endl;
            return;
        }
        {
            auto it = Pos.lower_bound({pref,-INF});
            while(it!=Pos.end() && it->second<=dp-i){
                auto nxt = next(it);
                Pos.erase(it);
                it = nxt;
            }
            if (it==Pos.end() || it->first!=pref)
                if (it==Pos.begin() || prev(it)->second<dp-i){
                    Pos.insert({pref,dp-i});
                }
        }
        {
            auto it = Neg.lower_bound({pref,INF});
            while(it!=Neg.begin() && prev(it)->second<=dp+i){
                Neg.erase(prev(it));
            }
            if (it==Neg.begin() || prev(it)->first!=pref)
                if (it==Neg.end() || it->second<dp+i)
                    Neg.insert({pref,dp+i});
        }
        if (!Zero.count(pref))
            Zero[pref] = dp;
        else Zero[pref] = max(Zero[pref],dp);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}