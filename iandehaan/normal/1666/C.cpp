#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;

#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pair<ll, ll> pts[3];
    rep(i, 0, 3) cin >> pts[i].first >> pts[i].second;

    sort(pts, pts+3);

    vector<pair<pair<ll, ll>, pair<ll, ll>>> out;
    if (pts[0].first != pts[1].first) {
        // line going up
        out.pb(mp(pts[0], mp(pts[1].first, pts[0].second)));
    }

    if (pts[0].second != pts[1].second) {
        // line going right or left
        out.pb(mp(mp(pts[1].first, pts[0].second), pts[1]));
    }

    ll lb = min(pts[0].second, pts[1].second);
    ll ub = max(pts[0].second, pts[1].second);

    ll currx = lb;

    if (true) {
        // line going up
        if (lb <= pts[2].second && pts[2].second <= ub) {
            // can go up exactly
            currx = pts[2].second;
        } else if (pts[2].second < lb) {
            currx = lb;
        } else if (pts[2].second > ub) {
            currx = ub;
        }

        if (pts[2].first != pts[1].first) {
            // draw line going up
            out.pb(mp(mp(pts[1].first, currx), mp(pts[2].first, currx)));
        }
    }

    if (currx != pts[2].second) {
        // draw horizontal
        out.pb(mp(mp(pts[2].first, currx), pts[2]));
    }

    cout << sz(out) << endl;
    for (auto x : out) {
        cout << x.first.first << ' ' << x.first.second << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

}