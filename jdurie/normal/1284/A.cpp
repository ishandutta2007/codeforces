#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

string s[200], t[200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, q;
    cin >> n >> m;
    for(ll i = 0; i < n; i++) cin >> s[i];
    for(ll i = 0; i < m; i++) cin >> t[i];
    cin >> q;
    while(q--) {
        ll x; cin >> x;
        cout << s[(x - 1) % n] + t[(x - 1) % m] << endl;
    }
}