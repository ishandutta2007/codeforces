#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 8E5+7;
const ll MOD = 1E9+7;
ll A[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }
        for(ll i = 1;i<=n;++i){
            for(ll j = n;j>i;--j){
                ll add = min(k,A[i]);
                A[j]+=add;
                A[i]-=add;
                k-=add;
            }
        }
        for(ll i = 1;i<=n;++i)
            cout<<A[i]<<' ';
        cout<<endl;
    }
    return 0;
}