#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(n%2){
        cout << a + min(2*a*(n/2), b*(n/2)) << "\n";
    }
    else{
        cout << min(a*n, b*n/2) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}