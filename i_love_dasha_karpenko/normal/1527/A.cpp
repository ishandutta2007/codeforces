//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll mult = 1;
        ll x = n,k = n;
        while(x){
            if (x&1)
                k = mult-1;
            x/=2;
            mult*=2;
        }
        cout<<k<<endl;
    }
    return 0;
}