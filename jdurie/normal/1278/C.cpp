#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 100010;
ll a[2 * NN];
map<ll, ll> fir;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T; cin >> T;
    while(T--) {
        fir.clear();
        ll n; cin >> n;
        for(ll i = 0; i < 2 * n; i++) cin >> a[i];
        ll ct = 0;
        fir[0] = n;
        for(ll i = 2 * n - 1; i >= n; i--) {
            if(a[i] == 2) ct++; else ct--;
            fir[ct] = i - n;
        }
        ct = 0;
        ll ans = n + fir[0];
        for(ll i = 0; i < n; i++) {
            if(a[i] == 2) ct++; else ct--;
            if(fir.count(-ct)) ans = min(ans, n - 1 - i + fir[-ct]);
        }
        cout << ans << endl;
    }
}