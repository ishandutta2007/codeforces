#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair

ll llersect(ll a, ll b, ll c, ll d) {
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    if (b <= c) return 0;

    return min(b, d)-c;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if (s[0] != t[0]) {
            cout << -1 << '\n';
            continue;
        }

        vi breaks;
        rep(i, 1, n) {
            if (s[i] != s[i-1]) breaks.pb(i);
        }
        vi breakt;
        rep(i, 1, n) {
            if (t[i] != t[i-1]) breakt.pb(i);
        }
        if (sz(breaks) != sz(breakt)) {
            cout << -1 << '\n';
            continue;
        }
        breaks.pb(n);
        breakt.pb(n);

        ll out = 0;
        ll poss = 0;
        ll post = 0;
        rep(i, 0, sz(breaks)) {
            ll nxtposs = breaks[i];
            ll nxtpost = breakt[i];

            out += max((ll)0, poss-post);
            out += max((ll)0, nxtpost-nxtposs);

            //cout << poss << ' ' <<  nxtposs << ' ' << post << ' ' << nxtpost << endl;

            //out += nxtpost - post - llersect(poss, nxtposs, post, nxtpost);
            //cout << out << endl;

            poss = nxtposs;
            post = nxtpost;
        }
        cout << out << '\n';
    }
}