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

#define MAXM 300'010

ll a[MAXM];
pair<pii, pair<ll, ll>> b[MAXM];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        map<pair<pii, pair<ll, ll>>, int> cnts;

        rep(i, 0, n) {
            
            rep(i, 0, m) cin >> a[i];
            int ind1 = 0;
            int ind2 = m-1;
            while (ind1+1 < ind2) {
                if (a[ind1] == 0) {
                    ind1++;
                    continue;
                }
                if (a[ind2] == 0) {
                    ind2--;
                    continue;
                }

                ll amt = min(a[ind1], a[ind2]);
                a[ind1+1] += amt;
                a[ind2-1] += amt;
                a[ind1] -= amt;
                a[ind2] -= amt;


            }
            b[i] = mp(mp(ind1, ind2), mp(a[ind1], a[ind2]));
            cnts[b[i]]++;
        }

        pair<pii, pair<ll, ll>> mode;
        pair<pii, pair<ll, ll>> spec;
        for (pair<pair<pii, pair<ll, ll>>, int> thing : cnts) {
            if (thing.second == 1) {
                spec = thing.first;
            } else {
                mode = thing.first;
            }
        }

        int specind = 0;
        rep(i, 0, n) if (b[i] == spec) specind = i;

        ll out = 0;
        if (spec.first.first == mode.first.first) {
            // same starting point... move stuff over
            out = mode.second.first - spec.second.first;
        } else {
            // not same starting point
            // move over everything on the second spot
            out = spec.second.second;
            out += mode.second.first * (spec.first.first - mode.first.first); // move over this much stuff
            out += mode.second.second * (spec.first.first - mode.first.second); // move over the rest
        }

        cout << specind+1 << ' ' << out << '\n';
        
    }
}