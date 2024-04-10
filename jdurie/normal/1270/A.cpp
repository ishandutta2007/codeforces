#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    ll T;
    cin >> T;
    while(T--) {
        ll n, k1, k2;
        cin >> n >> k1 >> k2;
        bool first = true;
        for(ll i = 0; i < k1; i++) {
            ll x; cin >> x;
        }
        for(ll i = 0; i < k2; i++) {
            ll x; cin >> x;
            if(x == n) first = false;
        }
        cout << (first ? "YES" : "NO") << endl;
    }
}