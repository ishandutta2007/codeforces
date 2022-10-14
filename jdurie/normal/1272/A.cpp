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
        ll mx, mn, a, b, c;
        cin >> a >> b >> c;
        mx = max(max(a, b), c);
        mn = min(min(a, b), c);
        if(mx - mn <= 2)
            cout << 0 << endl;
        else
            cout << 2 * (mx - mn - 2) << endl;
    }
}