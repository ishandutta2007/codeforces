#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;
const ll md = (ll)1e9 + 7, inf = (ll)1e18;

vector<pair<ll,ll>> tr;
ll sz = 1;

pair<ll,ll> operator +(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return { a.first + b.first, a.second + b.second };
}

void add(ll i, ll val) {
    i += sz;
    tr[i].first += val;
    tr[i].second += val * 1ll * (i - sz);
    while (i) {
        i >>= 1;
        tr[i] = tr[i << 1 | 0] + tr[i << 1 | 1];
    }
}

ll get(ll v, ll l, ll r, ll k) {
    if (!k)
        return 0;
    if (l == r - 1) {
        ll pr = (tr[v].first ? tr[v].second / tr[v].first : 0);
        return min(k, tr[v].first) * pr;
    }
    ll m = (l + r) >> 1;
    if (tr[v << 1 | 0].first >= k)
        return get(v << 1 | 0, l, m, k);
    else
        return tr[v << 1 | 0].second + get(v << 1 | 1, m, r, k - tr[v << 1 | 0].first);
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    while (sz < 1e6)
        sz <<= 1;
    tr.resize(2 * sz, make_pair(0, 0));

    ll n, k, m;
    cin >> n >> k >> m;

    struct ev {
        ll i, type;
        ev(){}
        ev(ll type, ll i): type(type), i(i){}
    };

    vector<pair<ll,ll>> q(m);
    vector<vector<ev>> w(n + 1);
    for (ll i = 0; i < m; i++) {
        ll l, r, c, p;
        cin >> l >> r >> c >> p, l--;
        q[i] = {c, p};
        w[l].push_back({0, i});
        w[r].push_back({1, i});
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ev &cur : w[i]) {
            ll c = q[cur.i].first, p = q[cur.i].second;
            if (!cur.type)
                add(p, c);
            else
                add(p, -c);
        }
        ans += get(1, 0, sz, k);
    }

    cout << ans << '\n';

    return 0;
}