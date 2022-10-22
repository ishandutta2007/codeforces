#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    if(n > k || m > k){cout << "-1\n"; return;}
    if(n%2 == m%2){
        if(n%2 == k%2){cout << k << "\n"; return;}
        else {cout << k-2 << "\n"; return;}
    }
    cout << k-1 << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}