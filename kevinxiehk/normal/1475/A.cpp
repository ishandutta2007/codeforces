#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
#define int long long
using namespace std;
void solve(){
    int n;cin>>n;
    int ah=2;
    while(ah<n){
        ah*=2;
    }
    if(ah==n)cout<<"NO\n";
    else cout<<"YES\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}