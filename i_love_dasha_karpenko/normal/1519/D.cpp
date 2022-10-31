//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 5000+7;
ll A[DIM],B[DIM];
vector<pair<ll,ll> > V[2][DIM];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    ll res = 0;
    for(ll i = 1;i<=n;++i) {
        cin >> B[i];
        res+=A[i]*B[i];
    }


    ll ans = res;
    for(ll type = 0;type<2;++type){

        for(ll i = 1;i<=n;++i){
            ll ss = 0;
            for(ll len = 1;len<=n;++len){
                ll l,r;
                if (type==0){
                    l = i-len+1,r = i+len;
                }
                else{
                    l = i-len,r = i+len;
                }
                if (l<=r && l>=1 && r<=n){
                    ss+=A[l]*B[r]+A[r]*B[l]-A[l]*B[l]-A[r]*B[r];
                    ans = max(ans,ss+res);
                    if (ans==31){
                        ll h;
                        ++h;
                    }
                }
                else break;
            }
        }
    }
    cout<<ans<<endl;
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    while(t--)
        solve();
    return 0;
}