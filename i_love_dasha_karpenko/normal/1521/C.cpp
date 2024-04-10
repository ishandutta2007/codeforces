//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E6+7;
ll R[DIM],val[DIM];
ll ask(ll t,ll i,ll j,ll x){
    cout<<"? "<<t<<' '<<i<<' '<<j<<' '<<x<<endl;
    ll ret;
    cin>>ret;
    return ret;
}
void solve(){
    ll n;
    cin>>n;
    ll pos = n;
    vector<pair<ll,ll> > V;
    for(ll i = 1;i+1<=n;i+=2){
        R[i] = ask(2,i,i+1,1);
        V.push_back({R[i],i});
        if (R[i]==2){
            R[i+1] = ask(2,i+1,i,1);
            if (R[i+1]==1){
                pos = i+1;
            }
        }
        if (R[i]==1){
            pos = i;
        }
    }
    val[pos] = 1;
    for(ll i = 1;i<=n;++i){
        if (i!=pos)
        val[i] = ask(1,pos,i,n-1);
    }
    cout<<"! ";
    for(ll i = 1;i<=n;++i){

        cout<<val[i]<<' ';
    }
    cout<<endl;
}
int main() {

    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}