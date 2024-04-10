#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int MOD = 1e9+7;
void solve(){
    int n;
    cin>>n;
    ll ans = 1;
    for(int i = 3;i<=n*2;++i){
        ans = ans*i%MOD;
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}