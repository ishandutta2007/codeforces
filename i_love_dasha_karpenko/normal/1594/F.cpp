//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("funroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
void solve(){
    ll s,n,k;
    cin>>s>>n>>k;
    if ((n<k && s!=k) || s<k || n>s){
        cout<<"NO\n";
        return;
    }
    if (s<k){
        cout<<"NO\n";
        return;
    }
    if (k*2<s-n+1 && k>n-2){
        cout<<"NO\n";
        return;
    }
    if (k>n-1 && k<n-s+1){
        cout<<"NO\n";
        return;
    }
    if (k<=n && (n/k)*k+n<=s){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}