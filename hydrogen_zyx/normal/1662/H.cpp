#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}


set<ll> st;

void getfac(ll val) {
    st.insert(val);
    st.insert(1);
    for (ll i = 1; i * i <= val; i++) {
        if (val % i == 0) {
            st.insert(i);
            st.insert(val / i);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        st.clear();
        st.insert(2);
        ll val = gcd(n - 1, m - 1);
        getfac(val);
        val = gcd(n, m - 2);
        getfac(val);
        val = gcd(n - 2, m);
        getfac(val);

        cout << st.size();
        for (auto x: st) cout << " " << x;
        cout << endl;
    }
}