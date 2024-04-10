//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 5E5+7;
const ll MOD = 1E9+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll res = 0;
        for(ll i = 1;i<=n;++i){
            for(ll j = 1;j<=m;++j){
                char ch;
                cin>>ch;
                res+=(ch=='#');
            }
        }
        ll flag = (res==n*m);
        ll ans = 1;
        while(res--)
            ans = (ans*2)%MOD;
        ans = (ans-flag+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}