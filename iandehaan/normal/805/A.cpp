#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l, r;
    cin >> l >> r;
    if (l == r) cout << l << endl;
    else cout << 2 << endl;
    /*if (abs(l-r) > 9) {
        cout << 2 << endl;
        return 0;
    }

    unordered_map<ll, ll> cnts;
    for (ll i = l; i <= r; i++) {
        unordered_set<ll> seen;
        for (ll fac = 2; fac <= sqrt(i) + 3; fac++) {
            if (i % fac == 0) {
                if (seen.find(i) == seen.end()) {
                if (cnts.find(fac) == cnts.end()) cnts[fac] = 0;
                cnts[fac]++;
                seen.insert(i);
                }
                if (i/fac != fac && i/fac != 1) {
                    if (seen.find(i/fac) == seen.end()) {
                    if (cnts.find(i/fac) == cnts.end()) cnts[i/fac] = 0;
                    cnts[i/fac]++;
                    seen.insert(i/fac);
                    }
                }
            }
        }
        if (cnts.find(i) == cnts.end()) cnts[i] = 0;
        if (seen.find(i) == seen.end()) cnts[i]++;
    }

    ll mxval = 0;
    ll mxthing = -1;
    for (pair<ll, ll> thing : cnts) {
        if (thing.second > mxval) {
            mxval = thing.second; 
            mxthing = thing.first;
        }
    }
    cout << mxthing << endl;*/
}