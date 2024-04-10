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

    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];

    ll out = 0;
    ll active = 0;
    vector<pair<ll, pii>> act;
    rep(i, 0, n) {
        act.pb(mp(1, mp(0, 1e9)));
        vector<pair<ll, pii>> act2;
        map<pii, int> seen;
        active++;
        for (int j = 0; j < sz(act); j++) {
            if (a[i] < act[j].second.first) {
                // can't put it in increasing
                if (a[i] > act[j].second.second) {
                    // also can't put it in decreasing
                    //cout << "oh no!" << endl;
                    active -= act[j].first;
                } else {
                    // must put it in decreasing
                    pii newamt = mp(act[j].second.first, a[i]);
                    if (seen.count(newamt) != 0) {
                        act2[seen[newamt]].first += act[j].first;
                    } else {
                        seen[newamt] = sz(act2);
                        act2.pb(mp(act[j].first, newamt));
                    }
                }
            } else {
                // can put it in increasing
                if (a[i] > act[j].second.second) {
                    // can't put it in decreasing
                    // must put it in increasing
                    pii newamt = mp(a[i], act[j].second.second);
                    if (seen.count(newamt) != 0) {
                        act2[seen[newamt]].first += act[j].first;
                    } else {
                        seen[newamt] = sz(act2);
                        act2.pb(mp(act[j].first, newamt));
                    }
                } else {
                    // can put it in either
                    if (i == n-1 || a[i] < a[i+1]) {
                        // put in increasing
                        pii newamt = mp(a[i], act[j].second.second);
                        if (seen.count(newamt) != 0) {
                            act2[seen[newamt]].first += act[j].first;
                        } else {
                            seen[newamt] = sz(act2);
                            act2.pb(mp(act[j].first, newamt));
                        }
                    } else {
                        pii newamt = mp(act[j].second.first, a[i]);
                        if (seen.count(newamt) != 0) {
                            act2[seen[newamt]].first += act[j].first;
                        } else {
                            seen[newamt] = sz(act2);
                            act2.pb(mp(act[j].first, newamt));
                        }
                    }
                }
            }
        }

        out += active;
        act = act2;

    }
    cout << out << endl;
}