//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
ll rsum[DIM],T[DIM];
pair<ll,ll> A[DIM];
vector<ll> V[DIM];
void solve(){
   ll n;
   cin>>n;
   for(ll i = 1;i<=n;++i){
       cin>>A[i].second;
   }
   for(ll i = 1;i<=n;++i){
       cin>>A[i].first;
       V[A[i].second].push_back(A[i].first);
   }
   ll res = 0;
   for(ll i = 1;i<=n;++i){
       sort(V[i].begin(),V[i].end());
       ll su = 0;
        for(ll j = 0;j<ll(V[i].size());++j){
            res+=V[i][j];
            su+=V[i][j];
            ll left = V[i].size()-j-1;
            for(ll div = 1;div*div<=left;++div){
                if (left%div)
                    continue;
                if (V[i].size()%div==j+1)
                rsum[div]+=su;

                ll dd = left/div;
                if (dd!=div && V[i].size()%dd==j+1){
                    rsum[dd]+=su;
                }
            }

        }
       T[V[i].size()+1] += su;
   }
   ll tsum = 0;
   for(ll i = 1;i<=n;++i){
       tsum+=T[i];
       cout<<res-tsum-rsum[i]<<' ';
   }
   cout<<endl;
   for(ll i = 1;i<=n+1;++i){
       T[i] = rsum[i] = 0;
       V[i].clear();
   }
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