
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({0,b+1-a,c+1-a})<<' '<<max({0,a+1-b,c+1-b})<<' '<<max({0,b+1-c,a+1-c})<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}