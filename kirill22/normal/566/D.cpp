#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

class dsu {
public:
    vector<int> p, rang;
    int n;
    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rang.resize(n, 1);
    }
    void clear() {
        iota(p.begin(), p.end(), 0);
        fill(all(rang), 1);
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (rang[x] < rang[y]) swap(x, y);
        if (x != y) {
            p[y] = x;
            rang[x] += (rang[x] == rang[y]);
            return true;
        }
        return false;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    dsu a(n);
    set<int> g;
    for (int i = 0; i < n - 1; i++) g.insert(i);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--, y--;
        if (t == 1) {
            a.unite(x, y);
        }
        if (t == 2) {
            while (true) {
                auto it = g.lower_bound(x);
                if (it == g.end() || *it >= y) break;
                a.unite(*it, *it + 1);
                g.erase(*it);
            }
        }
        if (t == 3) {
            cout << (a.get(x) == a.get(y) ? "YES" : "NO") << '\n';
        }
    }
}