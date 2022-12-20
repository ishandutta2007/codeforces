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

#define MAXN 200'010
ll s[MAXN];
ll p[MAXN];
vector<ll> children[MAXN];
ll n;

map<pair<ll, ll>, ll> memo; 
ll dp(ll pos, ll amt) {
    pair<ll, ll> key = mp(pos, amt);
    if (memo.count(key)) return memo[key];

    ll nc = sz(children[pos]);
    ll out = amt*s[pos];
    if (nc == 0) {
        return out;
    }

    ll avg = amt / nc;
    ll leftover = amt % nc;
    vector<ll> special(nc);
    rep(i, 0, nc) {
        ll nxt = children[pos][i];

        ll regular = dp(nxt, avg);
        if (leftover != 0) {
            ll extra = dp(nxt, avg+1);
            special[i] = extra-regular;
        }
        out += regular;
    }
    sort(all(special));
    reverse(all(special));
    rep(i, 0, leftover) out += special[i];
    return memo[key] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        memo.clear();
        ll k;
        cin >> n >> k;
        rep(i, 0, n) children[i].clear();
        p[0] = -1;
        rep(i, 1, n) {
            cin >> p[i];
            p[i]--;
            children[p[i]].pb(i);
        }

        rep(i, 0, n) cin >> s[i];

        cout << dp(0, k) << '\n';
    }
}