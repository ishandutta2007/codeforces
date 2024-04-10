#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        sort(all(a));
        reverse(all(a));
        vector<ll> pref(n);
        pref[0] = a[0];
        rep(i, 1, n) pref[i] = pref[i-1] + a[i];

        while (q--) {
            ll x;
            cin >> x;
            auto it = lower_bound(all(pref), x);
            if (it == end(pref)) {
                cout << -1 << '\n';
            } else {
                cout << (it-begin(pref))+1 << '\n';
            }
        }
    }
}