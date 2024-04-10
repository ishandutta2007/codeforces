//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("funroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 1e9+7;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll res = 0,mult = 1;
    while(k){
        if (k&1)
            res = (res+mult)%MOD;
        mult = (mult*n)%MOD;
        k = k>>1;
    }
    cout<<res<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}