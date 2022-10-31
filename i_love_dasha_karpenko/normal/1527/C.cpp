//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> last,M;
        for(ll i = 1;i<=n;++i) {
            cin >> A[i];

            last[A[i]] = 0;
            M[A[i]] = 0;
        }
        ll add = 0,res = 0;
        for(ll i = 1;i<=n;++i){
            M[A[i]]+=last[A[i]];
            res+=(n-i+1)*M[A[i]];
            last[A[i]] = i;
        }
        cout<<res<<endl;
    }
    return 0;
}