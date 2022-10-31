//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll a,b;
    cin>>a>>b;
    if (b==1){
        cout<<"NO\n";
        return;
    }
    ll n1 = a*(b-1),n2 = a*(b+1),n3 = 2*a*b;
    cout<<"YES\n"<<n1<<' '<<n2<<' '<<n3<<endl;
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