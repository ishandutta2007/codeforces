#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool prime(ll x){
    for(ll j=2; j*j<=x; j++){
        if(x%j == 0) return 0;
    }
    return 1;
}

void solve(){
    ld a, b;
    cin >> a >> b;
    if(a-b == 1 && prime(b+a)) cout << "YES\n";
    else cout << "NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}