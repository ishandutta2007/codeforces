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
    ll T; cin >> T;
    while(T--) {
        ll a, b, c, r, ans = 0;
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        if(c - r > a) ans += min(c - r, b) - a;
        if(c + r < b) ans += b - max(c + r, a);
        cout << ans << endl;
    }
}