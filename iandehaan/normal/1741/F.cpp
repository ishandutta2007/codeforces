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

ll n;
pair<ll, ll> seg[MAXN];
ll c[MAXN];

ll out[MAXN];
set<ll> active[MAXN];
set<ll> needmatch[MAXN];


void walk() {
    vector<pair<ll, pair<bool, ll>>> event;
    rep(i, 0, n) {
        event.pb(mp(seg[i].first, mp(false, i))); // start
        event.pb(mp(seg[i].second, mp(true, i))); // end
    }

    sort(all(event));
    set<ll> activecolors;
    set<ll> needcolors;

    for (pair<ll, pair<bool, ll>> e : event) {
        ll pos = e.first;
        ll ind = e.second.second;
        ll color = c[ind];

        if (!e.second.first) {
            bool matched = false;
            // beginning

            vi toremove;
            // 1. try to match anything that needs matching
            for (ll clr : needcolors) {
                if (clr == color) continue; // can't match ourselves
                for (ll x : needmatch[clr]) {
                    out[x] = min(out[x], abs(pos-seg[x].second));
                    if (seg[x].second >= pos) out[x] = 0;
                }

                needmatch[clr].clear();
                toremove.pb(clr);
            }
            for (ll clr : toremove) needcolors.erase(clr);

            // 2. try to match ourselves with something active
            for (ll clr : activecolors) {
                if (clr == color) continue;

                matched = true;
                out[ind] = 0; // something active of another color
                //if (ind == 3) cout << "alerta" << endl;
                break;
            }

            // 3. update things
            activecolors.insert(color);
            active[color].insert(ind);
            if (!matched) {
                needcolors.insert(color);
                needmatch[color].insert(ind);
            }
        } else {
            // ending

            active[color].erase(ind);
            if (active[color].empty()) activecolors.erase(color);
        }
    }
}

void tc() {
    cin >> n;
    rep(i, 0, n) {
        cin >> seg[i].first >> seg[i].second >> c[i];
        c[i]--;
    }

    rep(i, 0, n) {
        out[i] = 2 * (1e9);
    }

    rep(i, 0, 2) {
        rep(j, 0, n) {
            active[j].clear();
            needmatch[j].clear();
        }
        walk();

        rep(j, 0, n) {
            seg[j].first *= -1;
            seg[j].second *= -1;
            swap(seg[j].first, seg[j].second);
        }
    }

    rep(i, 0, n) cout << out[i] << ' ';
    cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        tc();
    }
}