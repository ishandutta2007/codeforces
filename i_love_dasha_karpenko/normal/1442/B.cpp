#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll MOD = 998244353 ;
const ll DIM = 2E5+7;
ll A[DIM],B[DIM];
ll T[DIM],L[DIM],R[DIM],D[DIM],VL[DIM],VR[DIM];
ll n,k;
void add(ll pos,ll delta){
    for(ll i = pos;i<=n;i+=(i&-i))
        T[i]+=delta;
}
ll get(ll pos){
    if (pos==0)return 0;
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i))
        ret+=T[i];
    return ret;
}
ll val(ll l,ll r){
    return get(r)-get(l-1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n>>k;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }
        for(ll i = 1;i<=k;++i){
            cin>>B[i];
            D[B[i]] = i;
        }
        set<pair<ll,ll> > S;
        for(ll i = n;i>=1;--i){
            if (D[A[i]]==0)continue;
            auto it = S.upper_bound({D[A[i]],0});
            if (it==S.end()){
                R[i] = n+1;
            }
            else{
                R[i] = it->second;
            }
            while(!S.empty() && S.begin()->first<D[A[i]]){
                S.erase(S.begin());
            }
            S.insert({D[A[i]],i});
        }
        S.clear();
        for(ll i = 1;i<=n;++i){
            if (D[A[i]]==0)continue;
            auto it = S.upper_bound({D[A[i]],0});
            if (it==S.end()){
                L[i] = 0;
            }
            else{
                L[i] = it->second;
            }
            while(!S.empty() && S.begin()->first<D[A[i]]){
                S.erase(S.begin());
            }
            S.insert({D[A[i]],i});
        }
        S.clear();
        for(ll i = 1;i<=n;++i){
            if (D[A[i]]){
                S.insert({D[A[i]],i});
            }
        }
        for(auto to:S){
            ll i = to.second;
            VL[i] = i-L[i]-1-val(L[i]+1,i);
            VR[i] = R[i]-1-i-val(i,R[i]-1);
            add(to.second,1);
        }
        ll res = 1;
        for(auto to:S){
            res=(res*((VL[to.second]>0)+(VR[to.second]>0)))%MOD;
        }
        cout<<res<<endl;
        for(ll i = 0;i<=n;++i){
            T[i] = D[i] = A[i] = B[i] = VL[i] = VR[i] = L[i] = R[i] = 0;
        }
    }




    return 0;

}