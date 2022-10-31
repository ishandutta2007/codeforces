//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg

void solve(){
    ll n,k1,k2;
    cin>>n>>k1>>k2;
    ll w,b;
    cin>>w>>b;
    ll mi = min(k1,k2),mx = max(k1,k2);\
    ll cnt = mi+(mx-mi)/2;

    if (cnt<w){
        cout<<"NO\n";
        return;
    }
    k1 = n-k1;
    k2 = n-k2;
    mi = min(k1,k2),mx = max(k1,k2);\
    cnt = mi+(mx-mi)/2;

    if (cnt<b){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}