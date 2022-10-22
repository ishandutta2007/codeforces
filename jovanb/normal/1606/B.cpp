#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll cur = 1;
        ll tren = 1;
        ll cnt = 0;
        while(tren < k){
            tren *= 2;
            cnt++;
        }
        n = max(0LL, n - tren);
        cout << cnt + (n+k-1)/k << "\n";
    }
    return 0;
}