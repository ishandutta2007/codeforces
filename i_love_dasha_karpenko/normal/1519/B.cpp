#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
   ll n,m,k;
   cin>>n>>m>>k;
   if ((n-1)+n*(m-1)==k)
       cout<<"YES\n";
   else
       cout<<"NO\n";
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