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

constexpr ll inf = (((ll) 1) << ((ll) 50));

// s == -1 if invalid
struct envelope {
    ll s, t, d, w;


    bool operator<(const envelope& other) const {
        if (w > other.w) {
            return true;
        } else if (w < other.w) {
            return false;
        }

        return d > other.d;
    }
};

ll n, m, k;

ll memo[100010][210];

envelope a[100010];

envelope opt[100010];

ll dp(ll pos, ll annoys) {
    //cout << pos << ' ' << annoys << ' ' << opt[pos].s << endl;
    if (pos > n) return 0;
    if (memo[pos][annoys] != -1) return memo[pos][annoys];

    ll out = inf;
    if (annoys > 0) {
        out = min(out, dp(pos+1, annoys-1));
    }

    if (opt[pos].s == -1) {
        // nothing to choose
        out = min(out, dp(pos+1, annoys));
    } else {
        // choose envelope
        out = min(out, opt[pos].w + dp(opt[pos].d+1, annoys));
    }

    return memo[pos][annoys] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);

    cin >> n >> m >> k;

    vector<ll> events[n+2];
    for (ll i = 0; i < k; i++) {
        cin >> a[i].s >> a[i].t >> a[i].d >> a[i].w;
        events[a[i].s].pb(i);
    }



    multiset<envelope> b;
    for (ll time = 0; time <= n; time++) {
        for (ll e : events[time]) {
            b.insert(a[e]);
        }

        while ((!b.empty()) && (b.begin()->t < time)) {
            b.erase(b.begin());
        }

        if (b.empty()) {
            opt[time].s = -1;
        } else {
            opt[time] = *b.begin();
        }
    }



    cout << dp(1, m) << endl;
}