#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;

ll roundup(ll k, ll x) {
    if(!(k%x)) return 0;
    return x - (k%x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0, a, b, c;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        cin >> k >> a >> b >> c;
        cout << min(roundup(k, a), min(roundup(k, b), roundup(k, c))) << '\n';
    }
}