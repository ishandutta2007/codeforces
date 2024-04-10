//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 100;
ll A[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ll flag = 0;
        for(ll k = 0;k<111 && k*11<=x;++k){
            if ((k*11)%111==x%111) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}