#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define gi(x) (x-'a')
const int N = 2e5+7;
int A[N];
void solve() {
    int n;
    cin>>n;
    ll total = 0;
    for(int i = 1;i<=n;++i)
        cin>>A[i],total += A[i];
    ll pref = A[n];
    ll mi = 0;
    ll ans;
    for(int i = n-1;i>=1;--i){ 
        if (i==1)
            ans = total-mi;
        mi = min(mi,(total-mi)+pref);
        pref += A[i];
    }
    cout<<ans<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}