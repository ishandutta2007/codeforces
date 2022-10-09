// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

pair<ll, ll> sp(ll x, ll y) {
    if (x > y) return {y, x};
    return {x, y};
}

void test(ll a, ll b) {
    if (a > b) swap(a, b);
        
    set<pair<ll, ll>> s;
    queue<pair<ll, ll>> q;
    q.push({a, b});
    s.insert({a, b});
    while (q.size()) {
        auto [a, b] = q.front();
        q.pop();
        auto p1 = sp(a, abs(a-b));
        auto p2 = sp(b, abs(a-b));
        for (auto p : {p1, p2}) {
            if (!s.contains(p)) {
                s.insert(p);
                q.push(p);
            }
        }
    }

    for (auto [x, y] : s) cerr << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll a, b, x;
        cin >> a >> b >> x;
        if (a > b) swap(a, b);

        set<pair<ll, ll>> s;
        queue<pair<ll, ll>> q;
        q.push({a, b});
        s.insert({a, b});
        while (q.size()) {
            auto [a, b] = q.front();
            q.pop();

            if (a == 0) continue;
            auto p1 = sp(abs(a-b), b);
            auto p2 = sp(a, b-(b/a-1)*a);
            for (auto p : {p1, p2}) {
                if (!s.contains(p)) {
                    s.insert(p);
                    q.push(p);
                }
            }
        }

        bool f = false;
        for (auto [a, b] : s) {
            if (x == a || x == b) f = true;
            if (a > 0 && x > a && x < b && (b-x) % a == 0) f = true;
        }

        cout << (f ? "YES\n" : "NO\n");
    }
}