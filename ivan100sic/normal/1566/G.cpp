// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct pick {
    int w, o;

    bool operator< (const pick& b) const {
        return tie(w, o) < tie(b.w, b.o);
    }

    bool operator== (const pick& b) const {
        return tie(w, o) == tie(b.w, b.o);
    }
};

struct bigpick {
    int w, u, v;

    bool operator< (const bigpick& o) const {
        return tie(w, u, v) < tie(o.w, o.u, o.v);
    }

    bool complement(int x, int y) const {
        return u != x && u != y && v != x && v != y;
    }

    bigpick ortho() const {
        bigpick result = *this;
        if (u > v) {
            swap(result.u, result.v);
        }
        return result;
    }
};

int n;

set<pick> picks[100005];
set<bigpick> all_edges, good_edges;
multiset<ll> sum_three;
map<pair<int, int>, int> weightof;

bool in_first_three(int x, int w, int y) {
    auto it = picks[x].begin();
    for (int i=0; i<3 && it != picks[x].end(); i++, ++it) {
        if (*it == pick{w, y}) {
            return true;
        }
    }
    return false;
}
 
template<class F>
void modify_picks(int x, F f) {
    if (picks[x].size() >= 3) {
        ll w = 0;
        auto it = picks[x].begin();
        for (int i=0; i<3; i++) {
            w += it->w;
            ++it;
        }
        sum_three.erase(sum_three.find(w));
    }

    {
        auto it = picks[x].begin();
        for (int i=0; i<3 && it != picks[x].end(); i++, ++it) {
            good_edges.erase((bigpick{it->w, x, it->o}).ortho());
        }
    }
 
    f();

    if (picks[x].size() >= 3) {
        ll w = 0;
        auto it = picks[x].begin();
        for (int i=0; i<3; i++) {
            w += it->w;
            ++it;
        }
        sum_three.insert(w);
    }

    {
        auto it = picks[x].begin();
        for (int i=0; i<3 && it != picks[x].end(); i++, ++it) {
            int y = it->o, w = it->w;
            if (in_first_three(y, w, x)) {
                good_edges.insert((bigpick{w, x, y}).ortho());
            }
        }
    }
}

void addin() {
    int x, y, w;
    cin >> x >> y >> w;
    if (x > y) swap(x, y);

    weightof[{x, y}] = w;
    all_edges.insert({w, x, y});

    modify_picks(x, [&]() { picks[x].insert({w, y}); });
    modify_picks(y, [&]() { picks[y].insert({w, x}); });
}

void rmin() {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);

    int w = weightof[{x, y}];
    all_edges.erase({w, x, y});

    modify_picks(x, [&]() { picks[x].erase({w, y}); });
    modify_picks(y, [&]() { picks[y].erase({w, x}); });
}

void printsol() {
    ll sol = 1e18;
    if (sum_three.size()) {
        sol = min(sol, *sum_three.begin());
    }

    int k = min((int)good_edges.size(), 8);
    auto eit = good_edges.begin();
    for (int i=0; i<k; i++) ++eit;
    vector<bigpick> bestpicks(good_edges.begin(), eit);

    
    for (int i=0; i<k; i++) {
        for (int j=i+1; j<k; j++) {
            auto [w, x, y] = bestpicks[j];
            if (bestpicks[i].complement(x, y)) {
                sol = min(sol, 0ll + w + bestpicks[i].w);
            }
        }
    }

    cout << sol << '\n';
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        addin();
    }

    printsol();

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            addin();
        } else {
            rmin();
        }
        printsol();
    }
}