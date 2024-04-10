#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if (n<4 || n%2)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}