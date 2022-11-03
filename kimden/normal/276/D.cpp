#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ll x, y;
    cin >> x >> y;
    for(ll i = (1LL << 60LL); i; i >>= 1LL){
        if((x ^ y) & i){
            cout << 2 * i - 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}