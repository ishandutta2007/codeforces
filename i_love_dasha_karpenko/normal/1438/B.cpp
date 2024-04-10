#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll> S;
        ll flag = 0;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            if (S.count(x)){
                flag = 1;
            }
            S.insert(x);
        }
        if (flag){
            cout<<"YES\n";
            continue;
        }
        else cout<<"NO\n";

    }

    return 0;

}