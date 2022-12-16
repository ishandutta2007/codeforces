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

    int n, q;
    cin >> n >> q;
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    sort(a, a+n);
    reverse(a, a+n);
    ll pref[n];
    pref[0] = a[0];
    rep(i, 1, n) pref[i] = pref[i-1] + a[i];

    while (q--) {
        ll y, x;
        cin >> x >> y;
        ll payamt = x-y;
        ll out = pref[x-1];
        if (payamt > 0) out -= pref[payamt-1];
        cout << out << '\n';
    }
}