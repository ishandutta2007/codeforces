#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll ans = 0;
const ll inf = 1e18;

ll calc(const vector<ll>& a, ll x, ll y) {
    ll val = inf;
    for (int i = -1; i < sz(a); ++i) {
        ll z = 0;
        if (i >= 0) {
            z += a[i] - x;
        }
        if (i + 1 < sz(a)) {
            z += y - a[i + 1];
        }
        val = min(val, z);
    }
    return val;
}

void solve(const vector<ll>& a, const vector<ll>& b, ll x, ll y) {
    ll first = y - x;
    if (!a.empty()) {
        first += calc(a, x, y);
    }
    if (!b.empty()) {
        first += calc(b, x, y);
    }
    if (a.empty() || b.empty()) {
        ans += first;
        return;
    }
    ll second = (y - x) * 2;
    ans += min(first, second);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a, b, c;
    while (n--) {
        ll pos;
        char type;
        cin >> pos >> type;
        if (type == 'P') {
            c.pb(pos);
        } else if (type == 'R') {
            a.pb(pos);
        } else {
            b.pb(pos);
        }
    }

    if (c.empty()) {
        if (!a.empty()) {
            ans += a.back() - a[0];
        }
        if (!b.empty()) {
            ans += b.back() - b[0];
        }
        cout << ans << "\n";
        return 0;
    }

    int ptra = 0, ptrb = 0;
    while (ptra < sz(a) && a[ptra] < c[0]) {
        ++ptra;
    }
    while (ptrb < sz(b) && b[ptrb] < c[0]) {
        ++ptrb;
    }

    if (ptra) {
        ans += c[0] - a[0];
    }
    if (ptrb) {
        ans += c[0] - b[0];
    }

    for (int i = 0; i + 1 < sz(c); ++i) {
        int starta = ptra;
        int startb = ptrb;
        while (ptra < sz(a) && a[ptra] < c[i + 1]) {
            ++ptra;
        }
        while (ptrb < sz(b) && b[ptrb] < c[i + 1]) {
            ++ptrb;
        }
        vector<ll> u, v;
        for (int j = starta; j < ptra; ++j) {
            u.pb(a[j]);
        }
        for (int j = startb; j < ptrb; ++j) {
            v.pb(b[j]);
        }
        solve(u, v, c[i], c[i + 1]);
    }

    if (ptra != sz(a)) {
        ans += a.back() - c.back();
    }
    if (ptrb != sz(b)) {
        ans += b.back() - c.back();
    }

    cout << ans << "\n";

}