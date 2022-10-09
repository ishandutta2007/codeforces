// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct entry {
    int val, type;
    // 0 for mine, 1 for enemy's
    strong_ordering operator<=> (const entry& b) const = default;
};

struct difference {
    int val, id;
    strong_ordering operator<=> (const difference& b) const = default;
};

struct traderset {
    ll onesum = 0;
    multiset<int> zeros, ones;

    traderset() {}

    traderset(entry e) {
        (e.type ? ones : zeros).insert(e.val);
        onesum = e.type ? e.val : 0;
    }

    ll swallow(traderset& other) {
        onesum += other.onesum;

        if (zeros.size() < other.zeros.size()) swap(zeros, other.zeros);        
        if (ones.size() < other.ones.size()) swap(ones, other.ones);

        for (int x : other.zeros) zeros.insert(x);
        for (int x : other.ones) ones.insert(x);

        other.ones.clear();
        other.zeros.clear();
        other.onesum = 0;

        ll diff = 0;
        while (zeros.size() && ones.size() && *zeros.rbegin() > *ones.begin()) {
            int z = *zeros.rbegin();
            int o = *ones.begin();
            zeros.erase(prev(zeros.end()));
            ones.erase(ones.begin());
            zeros.insert(o);
            ones.insert(z);
            diff += z - o;
        }

        onesum += diff;
        return diff;
    }
};

struct union_find_fat {
    vector<traderset> a;
    vector<int> b;
    ll sum;

    union_find_fat(const vector<entry>& ab) {
        int n = ab.size();
        a.resize(n);
        b.resize(n);
        sum = 0;
        for (int i=0; i<n; i++) {
            a[i] = ab[i];
            sum += a[i].onesum;
            b[i] = i;
        }
    }

    int e(int x) {
        if (x == b[x]) return x;
        return b[x] = e(b[x]);
    }

    void join(int x, int y) {
        x = e(x);
        y = e(y);
        if (x == y) return;
        sum += a[y].swallow(a[x]);
        b[x] = y;
    }
};

void rdv(auto p) {
    for (int& x : *p) cin >> x;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m), u(q);
    for (auto p : {&a, &b, &u}) rdv(p);

    vector<entry> ab;
    for (int i : ra(0, n)) ab.push_back({a[i], 1});    
    for (int i : ra(0, m)) ab.push_back({b[i], 0});
    R::sort(ab);

    vector<difference> dif;
    for (int i : ra(0, n+m-1)) dif.push_back({ab[i+1].val - ab[i].val, i});

    R::sort(dif);
    union_find_fat euf(ab);

    map<int, ll> sol;

    auto us = u;
    R::sort(us);
    span vit = dif;
    for (int x : us) {
        while (vit.size() && vit[0].val <= x) {
            difference d = vit[0];
            euf.join(d.id, d.id+1);
            vit = vit.subspan(1);
        }
        sol[x] = euf.sum;
    }

    for (int x : u) cout << sol[x] << '\n';
}