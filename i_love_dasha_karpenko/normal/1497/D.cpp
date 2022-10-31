//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
ll T[DIM],S[DIM],MX[DIM];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>T[i];
    }
    for(ll i = 1;i<=n;++i){
        cin>>S[i];
    }
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = i-1;j>=1;--j){
            if (T[i]==T[j])continue;
            ll prev = MX[i];
            MX[i] = max(MX[i],MX[j]+abs(S[i]-S[j]));
            MX[j] = max(MX[j],prev+abs(S[i]-S[j]));
            res = max({res,MX[i],MX[j]});
        }
    }
    for(ll i = 1;i<=n;++i)MX[i] = 0;
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}