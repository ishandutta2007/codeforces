#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2[65];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    pow2[0] = 1;
    for(int i=1; i<=62; i++) pow2[i] = pow2[i-1]*2;
    ll l, r;
    cin >> l >> r;
    if(l == r){cout << 0; return 0;}
    for(int i=62; i>=0; i--){
        ll a = (l & pow2[i]);
        ll b = (r & pow2[i]);
        if(a != b){cout << pow2[i+1]-1; return 0;}
    }
    return 0;
}