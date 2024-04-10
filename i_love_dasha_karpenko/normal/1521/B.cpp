//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E6+7;
ll A[DIM];
void solve(){
    ll n;
    cin>>n;
    ll pos = 0;
    A[0] = 2E9;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        if (A[i]<A[pos])
            pos = i;
    }
    cout<<pos-1+n-pos<<endl;
    for(ll i = pos+1;i<=n;++i){
        cout<<pos<<' '<<i<<' '<<A[pos]<<' '<<A[pos]+i-pos<<endl;
        A[i] = A[i-1]+1;
    }
    for(ll i = pos-1;i>=1;--i){
        cout<<pos<<' '<<i<<' '<<A[pos]<<' '<<A[i+1]+1<<endl;
        A[i] = A[i+1]+1;
    }
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