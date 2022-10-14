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
        ll r, g, b;
        cin >> r >> g >> b;
        ll m = max(max(r, g), b);
        ll s = r + g + b - m;
        cout << (m <= s + 1 ? "Yes" : "No") << endl;
    }
}