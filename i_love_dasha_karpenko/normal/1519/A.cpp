#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll r,b,d;
    cin>>r>>b>>d;
    ll dif = abs(r-b);
    if (d==0){
        if (dif)
            cout<<"NO\n";
        else cout<<"YES\n";
        return;
    }
    ll num = dif/d+(dif%d!=0);
    if (min(r,b)<num)
        cout<<"NO\n";
    else cout<<"YES\n";
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