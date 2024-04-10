// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct closest {
    set<int> a, b;
    map<int, int> d;
    set<pair<int, int>> e;

    void update_dist(int x) {
        e.erase({d[x], x});

        auto ra = a.lower_bound(x);
        if (ra != a.end()) {
            d[x] = min(d[x], *ra - x);
        }
        
        if (ra != a.begin()) {
            auto la = prev(ra);
            d[x] = min(d[x], x - *la);
        }

        e.insert({d[x], x});
    }

    void insert_a(int x) {
        a.insert(x);
        auto it = b.lower_bound(x);
        if (it != b.end()) update_dist(*it);
        if (it != b.begin()) update_dist(*prev(it));
    }

    int best() {
        return e.begin()->second;
    }

    void erase_b(int x) {
        e.erase({d[x], x});
        d.erase(x);
        b.erase(x);
        auto it = b.lower_bound(x);
        if (it != b.end()) update_dist(*it);
        if (it != b.begin()) update_dist(*prev(it));
    }

    void init_b(int x) {
        d[x] = 123123123;
        e.insert({d[x], x});
        b.insert(x);
    }
};

int n, q, s, d;
int a[200005], w[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> q >> s >> d;
    
    closest naj;

    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (i != s) {
            naj.init_b(a[i]);
        }
    }

    naj.insert_a(a[s] - d);
    naj.insert_a(a[s] + d);
    int dw = 0;
    for (int i=0; i<n-1; i++) {
        int x = naj.best();
        dw = max(dw, naj.d[x]);
        w[lower_bound(a+1, a+n+1, x) - a] = dw;
        naj.erase_b(x);
        naj.insert_a(x - d);
        naj.insert_a(x + d);
    }

    while (q--) {
        int i, k;
        cin >> i >> k;
        cout << (w[i] <= k ? "Yes\n" : "No\n");
    }
}