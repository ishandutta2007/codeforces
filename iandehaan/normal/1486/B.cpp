#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define pb push_back
#define mp make_pair

ll n;
pair<ll, ll> a[1000];

ll scorePos(ll x, ll y) {
    ll out = 0;
    for (ll i = 0; i < n; i++) {
        out += abs(a[i].first-x) + abs(a[i].second-y);
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (ll i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

        int x[n];
        for (int i = 0; i < n; i++) x[i] = a[i].first;
        sort(x, x+n);
        pair<int, int> pos;
        pos.first = x[(int)((ceil((double)n / 2) - 1))];
        int y[n];
        for (int i = 0; i < n; i++) y[i] = a[i].second;
        sort(y, y+n);
        pos.second = y[(int)((ceil((double)n / 2) - 1))];
        //cout << pos.first << ' ' << pos.second << endl;
        /*while (true) {
            ll posscore = scorePos(pos.first, pos.second);
            bool found = false;
            if (scorePos(pos.first-1, pos.second) < posscore) {
                pos.first--;
                found = true;
            } else if (scorePos(pos.first+1, pos.second) < posscore) {
                pos.first++;
                found = true;
            } else if (scorePos(pos.first, pos.second-1) < posscore) {
                pos.second--;
                found = true;
            } else if (scorePos(pos.first, pos.second+1) < posscore) {
                pos.second++;
                found = true;
            }
            if (!found) break;
        }*/

        vector<pair<ll, ll>> out;
        set<pair<ll, ll>> seen;
        out.pb(pos);
        seen.insert(pos);
        ll xcoord = 1;
        ll ycoord = 1;
        ll bestscore = scorePos(pos.first, pos.second);
        //cout << "pos " << pos.first << ' ' << pos.second << endl;
        for (ll j = 0; j < out.size(); j++) {
            if (scorePos(out[j].first-1, out[j].second) == bestscore) {
                //out.pb(mp(out[j].first-1, out[j].second));
                //seen.insert(mp(out[j].first-1, out[j].second));
                ll mxdown = -100;
                for (int i = 0; i < n; i++) {
                    if (a[i].first < out[j].first) {
                        mxdown = max(mxdown, a[i].first);
                    }
                }
                //cout << "mxdown " << mxdown << endl;
                xcoord += (out[j].first)-mxdown;
            }
            if (scorePos(out[j].first+1, out[j].second) == bestscore) {
                ll mxup = (ll)1000000001;
                for (int i = 0; i < n; i++) {
                    if (a[i].first > out[j].first) {
                        mxup = min(mxup, a[i].first);
                    }
                }
                //cout << "mxup " << mxup << endl;
                xcoord += mxup - (out[j].first);
            }
            if (scorePos(out[j].first, out[j].second-1) == bestscore) {
                ll mxleft = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i].second < out[j].second) {
                        mxleft = max(mxleft, a[i].second);
                    }
                }
                ycoord += out[j].second-mxleft;

            }
            if (scorePos(out[j].first, out[j].second+1) == bestscore) {
                ll mxright = (ll)1000000001;
                for (int i = 0; i < n; i++) {
                    if (a[i].second > out[j].second) {
                        //cout << "hi " << out[j].second << ' ' << a[i].second << endl;
                        mxright = min(mxright, a[i].second);
                    }
                }
                //cout << out[j].second << endl;
                //cout << "mxright " << mxright << endl;
                ycoord += mxright - out[j].second;
            }
        }
        //cout << xcoord << ' ' << ycoord << endl;
        cout << xcoord*ycoord << endl;
    }
}