// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct offset : multiset<ll> {
    ll d = 0;

    void add(ll x) {
        d += x;
    }

    void insert(ll x) {
        multiset<ll>::insert(x - d);
    }

    ll first() {
        return *begin() + d;
    }

    ll last() {
        return *prev(end()) + d;
    }
};

int n;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    vector<pair<int, int>> a;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x+y, x-y);
    }

    n++;
    a.emplace_back(0, 0);

    sort(begin(a), end(a));
    offset levi, desni;
    ll sol = 0;

    for (int i=n-1; i>=0; i--) {
        ll t = a[i].second;
        if (i == n-1) {
            levi.insert(t);
            desni.insert(t);
        } else {
            // expand
            ll d = a[i+1].first - a[i].first;
            levi.add(-d);
            desni.add(d);
            sol -= (levi.size() + desni.size()) * d;

            if (t <= levi.last()) {
                levi.insert(t);
                levi.insert(t);
                desni.insert(levi.last());
                levi.erase(--levi.end());
            } else if (t >= desni.first()) {
                desni.insert(t);
                desni.insert(t);
                levi.insert(desni.first());
                desni.erase(desni.begin());
            } else {
                levi.insert(t);
                desni.insert(t);
            }
        }
    }

    for (auto p : {&levi, &desni}) {
        while (p->size()) {
            ll x = p->first();
            p->erase(p->begin());
            sol += abs(x);
        }
        cerr << '\n';
    }

    cout << sol / 4 << '\n';
}