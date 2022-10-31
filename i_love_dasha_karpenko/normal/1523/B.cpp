//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
    }
    cout<<n/2*6<<endl;
    for(ll i = 1;i<=n;i+=2){
        ll a = i,b = i+1;
        cout<<"1 "<<a<<' '<<b<<endl;
        cout<<"2 "<<a<<' '<<b<<endl;
        cout<<"1 "<<a<<' '<<b<<endl;
        cout<<"1 "<<a<<' '<<b<<endl;
        cout<<"2 "<<a<<' '<<b<<endl;
        cout<<"1 "<<a<<' '<<b<<endl;
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