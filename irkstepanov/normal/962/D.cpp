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

const int nmax = 200500;
const ll inf = 1e18;

ll t[nmax * 4];
ll res[nmax];

void build(int v, int tl, int tr, const vector<ll>& a) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

pll get(int v, int tl, int tr) {
    if (tl == tr) {
        return {tl, t[v]};
    }
    int tm = (tl + tr) >> 1;
    if (t[v * 2] == t[v]) {
        return get(v * 2, tl, tm);
    } else {
        return get(v * 2 + 1, tm + 1, tr);
    }
}

void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void relax(int v, int tl, int tr) {
    if (tl == tr) {
        if (t[v] != inf && res[tl] == 0) {
            res[tl] = t[v];
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    relax(v * 2, tl, tm);
    relax(v * 2 + 1, tm + 1, tr);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(1, 0, n - 1, a);

    pll prev = {-1, -1};

    while (true) {
        pll p = get(1, 0, n - 1);
        if (p.second == inf) {
            if (prev.first != -1) {
                res[prev.first] = prev.second;
            }
            break;
        }
        if (prev.second == p.second) {
            update(1, 0, n - 1, p.first, prev.second * 2);
            prev = {-1, -1};
            continue;
        } else {
            if (prev.first != -1) {
                res[prev.first] = prev.second;
            }
            prev = p;
            update(1, 0, n - 1, p.first, inf);
        }
    }

    relax(1, 0, n - 1);
    vector<ll> ans;
    for (int i = 0; i < n; ++i) {
        if (res[i]) {
            ans.pb(res[i]);
        }
    }

    cout << sz(ans) << "\n";
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}