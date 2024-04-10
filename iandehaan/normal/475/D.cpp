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

    map<ll, ll> lst;
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> cnts;
    for (ll i = 0; i < n; i++) {
        map<ll, ll> curr;
        curr[a[i]] = 1;
        for (pair<ll, ll> thing : lst) {
            ll newkey = __gcd(thing.first, a[i]);
            if (curr.find(newkey) == curr.end()) curr[newkey] = 0;
            curr[newkey] += thing.second;
        }
        for (pair<ll, ll> thing: curr) {
            if (cnts.find(thing.first) == cnts.end()) cnts[thing.first] = 0;
            cnts[thing.first] += thing.second;
        }
        lst = curr;
    }

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll x;
        cin >> x;
        if (cnts.find(x) == cnts.end()) cout << 0 << '\n';
        else cout << cnts[x] << '\n';
    }
}