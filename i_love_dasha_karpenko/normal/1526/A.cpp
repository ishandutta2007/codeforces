//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 30;
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
        for(ll i = 1;i<=n*2;++i)
            cin>>A[i];
        sort(A+1,A+1+n*2);
        ll ptr = 1;
        for(ll i = 1;i<=n*2;++i) {
            if (i%2)
                cout<<A[ptr]<<' ';
            else {
                cout << A[ptr + n] << ' ';
                ++ptr;
            }
        }
        cout<<endl;
    }
    return 0;
}