#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

struct fw {
    int x, y, dx, dy;

    fw () {};
    fw (int x, int y, int dx, int dy) : x(x), y(y), dx(dx), dy(dy) {};

    void shift() {
        x += dx;
        y += dy;
    }

    bool operator< (const fw &a) const {
        if (x == a.x) {
            if (y == a.y) {
                if (dx == a.dx) {
                    return dy < a.dy;
                } else return dx < a.dx;
            } else return y < a.y;
        } else return x < a.x;
    }

    void rotate_left() {
        if (dx == 0 || dy == 0) {
            int ndx = dx - dy, ndy = dx + dy;
            dx = ndx, dy = ndy;
        } else {
            int ndx = (dx - dy) / 2, ndy = (dx + dy) / 2;
            dx = ndx, dy = ndy;
        }
    }

    void rotate_right() {
        if (dx == 0 || dy == 0) {
            int ndx = dx + dy, ndy = dy - dx;
            dx = ndx, dy = ndy;
        } else {
            int ndx = (dx + dy) / 2, ndy = (dy - dx) / 2;
            dx = ndx, dy = ndy;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<fw> pr, nx;
    set<pair<int, int>> ans;
    pr.emplace(0, 0, 1, 0);
    while (n--) {
        int d;
        cin >> d;
        while (d--) {
            nx.clear();
            for (auto p : pr) {
                p.shift();
                ans.emplace(p.x, p.y);
                nx.insert(p);
            }
            pr = nx;
        }
        nx.clear();
        for (auto p : pr) {
            fw q = p;
            p.rotate_left();
            q.rotate_right();
            nx.insert(p);
            nx.insert(q);
        }
        pr = nx;
    }
    cout << ans.size() << '\n';
}