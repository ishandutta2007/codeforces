#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>
#include <random>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<ll> a, b;
vector<ll> f;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    bool operator<(const pt& other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
};

typedef tree<
pt,
null_type,
less<pt>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ld cross(const pt& p, const pt& q) {
    return ld(p.x) * ld(q.y) - ld(p.y) * ld(q.x);
}

ll dot(const pt& p, const pt& q) {
    return p.x * q.x + p.y * q.y;
}

void add(ordered_set& a, const pt& p) {
    if (a.empty()) {
        a.insert(p);
        return;
    }
    auto it = a.lower_bound(p);
    if (it != a.end()) {
        if (it->x == p.x && it->y <= p.y) {
            return;
        }
        if (it->x == p.x) {
            auto nx = it;
            ++nx;
            a.erase(it);
            it = nx;
        }
    } else {
        auto tmp = --a.end();
        if (tmp->x == p.x) {
            return;
        }
    }
    if (a.empty()) {
        a.insert(p);
        return;
    }

    if (it == a.begin()) {
        while (it != a.end()) {
            auto nx = it;
            ++nx;
            if (nx == a.end()) {
                break;
            }
            if (cross(*it - p, *nx - p) <= 0) {
                a.erase(it);
                it = nx;
            } else {
                break;
            }
        }
        a.insert(p);
        return;
    }

    if (it == a.end()) {
        --it;
        while (it != a.begin()) {
            auto pr = it;
            --pr;
            if (cross(*pr - p, *it - p) <= 0) {
                a.erase(it);
                it = pr;
            } else {
                break;
            }
        }
        a.insert(p);
        return;
    }

    auto pr = it;
    --pr;
    if (cross(*it - *pr, p - *pr) >= 0) {
        return;
    }
    while (it != a.end()) {
        auto nx = it;
        ++nx;
        if (nx == a.end()) {
            break;
        }
        if (cross(*it - p, *nx - p) <= 0) {
            a.erase(it);
            it = nx;
        } else {
            break;
        }
    }
    it = pr;
    while (it != a.begin()) {
        pr = it;
        --pr;
        if (cross(*pr - p, *it - p) <= 0) {
            a.erase(it);
            it = pr;
        } else {
            break;
        }
    }
    a.insert(p);

    // TODO
    /*if (sz(a) <= 2) {
        return;
    }
    it = a.begin();
    auto x = it;
    ++x;
    auto y = x;
    ++y;
    while (y != a.end()) {
        //assert(cross(*x - *it, *y - *x) > 0);
        ++it;
        ++x;
        ++y;
    }*/
}

ll findMin(const ordered_set& a, const pt& p) {
    int lf = 0;
    int rg = sz(a) - 1;
    while (rg - lf > 2) {
        int x = (2 * lf + rg) / 3;
        int y = (2 * rg + lf) / 3;
        if (dot(*a.find_by_order(x), p) < dot(*a.find_by_order(y), p)) {
            rg = y;
        } else {
            lf = x;
        }
    }
    ll minn = 1e18;
    //cout << p.x << " " << p.y << endl;
    for (int i = lf; i <= rg; ++i) {
        minn = min(minn, dot(*a.find_by_order(i), p));
    }
    /*ll ans = 1e18;
    for (int i = 0; i < sz(a); ++i) {
        ans = min(ans, dot(*a.find_by_order(i), p));
    }
    assert(ans == minn);*/
    return minn;
}

void naive(int v, int p, ll x, ll& ans) {
    ans = min(ans, x * b[v] + f[v]);
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        naive(to, v, x, ans);
    }
}

void dfs(int v, int p, ordered_set& c) {
    //ll ans = 1e18;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        ordered_set t;
        dfs(to, v, t);
        //naive(to, v, a[v], ans);
        if (sz(t) < sz(c)) {
            for (auto it : t) {
                add(c, it);
            }
        } else {
            for (auto it : c) {
                add(t, it);
            }
            c.swap(t);
        }
    }



    if (c.empty()) {
        f[v] = 0;
    } else {
        f[v] = findMin(c, {a[v], 1});
        //cout << v << " " << f[v] << " " << ans << endl << endl;
        //assert(f[v] == ans);
    }
    add(c, {b[v], f[v]});

    /*for (auto it : c) {
        cout << "!" << it.x << " " << it.y << endl;
    }
    cout << endl;*/
}

mt19937 rr(2);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    bool test = false;

    int n;
    if (test) {
        n = 500;
    } else {
        cin >> n;
    }
    g.resize(n);
    a.resize(n);
    b.resize(n);
    f.resize(n);

    for (int i = 0; i < n; ++i) {
        if (test) {
            a[i] = ll(rr()) % 200500 - 100500;
        } else {
            long long x;
            cin >> x;
            a[i] = x;
        }

        //
        //a[i] = rr() % 100 - 50;
    }
    for (int i = 0; i < n; ++i) {
        if (test) {
            b[i] = ll(rr()) % 200500 - 100500;
        } else {
            long long x;
            cin >> x;
            b[i] = x;
        }
    }
    /*for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << b[i] << endl;
    }*/

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        if (test) {
            u = i + 2;
            v = u - 1;
            //v = rr() % (u - 1) + 1;
        } else {
            cin >> u >> v;
        }


        //cout << u << " " << v << endl;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ordered_set v;
    dfs(0, 0, v);

    for (int i = 0; i < n; ++i) {
        cout << (long long)f[i] << " ";
    }
    cout << "\n";

}