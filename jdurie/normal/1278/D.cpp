#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 5000010;
vector<pair<ll, ll>> segs;
set<ll> rights;
ll st[2 * NN];

ll dsu(ll i) { return st[i] == i ? i : st[i] = dsu(st[i]); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    for(ll i = 0; i < 2 * n + 6; i++) st[i] = i;
    for(ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());
    for(ll i = 0; i < n; i++) {
        while(!rights.empty() && *rights.begin() < segs[i].first) rights.erase(*rights.begin());
        for(ll r : rights) {
            if(r > segs[i].second) break;
            if(dsu(r) == dsu(segs[i].second)) {
                cout << "NO" << endl;
                return 0;
            }
            st[dsu(segs[i].second)] = dsu(r);
        }
        rights.insert(segs[i].second);
    }
    for(ll i = 1; i < n; i++)
        if(dsu(segs[i].second) != dsu(segs[0].second)) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
}