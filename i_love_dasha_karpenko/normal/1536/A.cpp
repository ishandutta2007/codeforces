//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll flag = 0;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            if (x<0)
                flag = 1;
        }
        if (flag){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n"<<201<<endl;
            for(ll i = 0;i<=200;++i)cout<<i<<' ';
            cout<<endl;
        }

    }
    return 0;
}