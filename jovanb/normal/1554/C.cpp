#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll x = 0;
    ll res = m+1;
    for(int j=29; j>=0; j--){
        if(!((1 << j) & m)){
            if((1 << j) & n) res = min(res, x);
            else res = min(res, x + (1 << j));
        }
        else{
            if(!((1 << j) & n)) x += (1 << j);
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}