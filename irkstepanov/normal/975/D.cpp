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
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    bool operator<(const pt& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

ll dot(const pt& p, const pt& q) {
    return p.x * q.x + p.y * q.y;
}

pt line;

ll solve(const vector<pt>& v) {
    map<ll, int> mapa;
    for (pt p : v) {
        //cout << "!" << cross(p, line) << "\n";
        ++mapa[cross(p, line)];
    }
    map<pt, int> t;
    for (pt p : v) {
        ++t[p];
    }
    ll ans = 0;
    for (auto it : t) {
        ans -= ll(it.second) * (it.second - 1);
    }
    for (auto it : mapa) {
        //cout << it.first << " " << it.second << "\n";
        ans += ll(it.second) * (it.second - 1);
    }
    return ans;
}

ll len2(const pt& p) {
    return p.x * p.x + p.y * p.y;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll a, b;
    cin >> a >> b;

    line = {1, a};
    vector<pt> above, below, on;

    while (n--) {
        ll x;
        pt dir;
        cin >> x >> dir.x >> dir.y;
        if (cross(dir, line) == 0) {
            on.pb(dir);
        } else if (cross(dir, line) > 0) {
            above.pb(dir);
        } else {
            below.pb(dir);
        }
    }

    ll ans = solve(below) + solve(above);
    map<ll, int> mapa;
    for (pt p : on) {
        ll val = len2(p);
        if (dot(p, line) >= 0) {
            ++mapa[val];
        } else {
            ++mapa[-val];
        }
    }

    ans += ll(sz(on)) * (sz(on) - 1);
    for (auto it : mapa) {
        ans -= ll(it.second) * (it.second - 1);
    }
    cout << ans << "\n";

}