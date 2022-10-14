#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T; cin >> T;
    while(T--) {
        ll a, b, c = 0;
        cin >> a >> b;
        while(true) {
            ll temp = a + b + (c + 1) * c / 2;
            if(!(temp % 2) && temp >= 2 * max(a, b)) break;
            c++;
        }
        cout << c << endl;
    }
}