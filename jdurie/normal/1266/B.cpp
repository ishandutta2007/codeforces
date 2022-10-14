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
    ll T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        cout << ((n >= 14) && (n % 14 <= 6) && (n % 14) ? "YES" : "NO") << endl;
    }
}