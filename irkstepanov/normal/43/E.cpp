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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const ld eps = 1e-9;
const ld inf = 1e9;

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

bool gt(ld a, ld b) {
    return a - b > eps;
}

bool lt(ld a, ld b) {
    return b - a > eps;
}

bool leq(ld a, ld b) {
    return lt(a, b) || eq(a, b);
}

bool geq(ld a, ld b) {
    return gt(a, b) || eq(a, b);
}

struct pt {
    ld x, y;
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
    bool operator==(const pt& other) const {
        return eq(x, other.x) && eq(y, other.y);
    }
    bool operator!=(const pt& other) const {
        return !(*this == other);
    }
};

ld cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

ld dot(const pt& p, const pt& q) {
    return p.x * q.x + p.y * q.y;
}

struct line {
    ld a, b, c;
    line(const pt& p, const pt& q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
        ld tmp = sqrt(a * a + b * b);
        a /= tmp, b /= tmp, c /= tmp;
    }
};

int sgn(const pt& p, const line& l) {
    ld val = p.x * l.a + p.y * l.b + l.c;
    if (gt(val, 0)) {
        return 1;
    } else if (eq(val, 0)) {
        return 0;
    } else {
        return -1;
    }
}

pt origin;

bool onSegment(const pt& p, const pt& a, const pt& b) {
    pt u = a - p, v = b - p;
    return eq(cross(u, v), 0) && leq(dot(u, v), 0);
}

pt intersect(const line& l, const line& m) {
    ld a1 = l.a, b1 = l.b, c1 = -l.c;
    ld a2 = m.a, b2 = m.b, c2 = -m.c;
    ld det = a1 * b2 - a2 * b1;
    if (eq(det, 0)) {
        return {inf, inf};
    }
    ld det1 = c1 * b2 - c2 * b1;
    ld det2 = a1 * c2 - a2 * c1;
    return {det1 / det, det2 / det};
}

pt intersect(const pt& a, const pt& b, const pt& c, const pt& d) {
    line l(a, b), m(c, d);
    pt p = intersect(l, m);
    if (eq(p.x, inf) && eq(p.y, inf)) {
        return p;
    }
    if (onSegment(p, a, b) && onSegment(p, c, d)) {
        return p;
    }
    return {inf, inf};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    ll s;
    cin >> n >> s;

    vector<vector<pt> > a(n);
    for (int i = 0; i < n; ++i) {
        pt p = {0, 0};
        a[i].pb(p);
        int k;
        cin >> k;
        while (k--) {
            ll v, t;
            cin >> v >> t;
            p.x += t;
            p.y += v * t;
            a[i].pb(p);
        }
    }

    origin = {0, 0};

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<ld> v;
            for (int x = 0; x < sz(a[i]); ++x) {
                v.pb(a[i][x].x);
            }
            for (int y = 0;y < sz(a[j]); ++y) {
                v.pb(a[j][y].x);
            }
            int y = 0;
            int x = 0;
            while (x + 1 < sz(a[i]) && y + 1 < sz(a[j])) {
                pt p = intersect(a[i][x], a[i][x + 1], a[j][y], a[j][y + 1]);
                if (!eq(p.x, inf)) {
                    v.pb(p.x);
                }
                if (a[i][x + 1].x == a[j][y + 1].x) {
                    ++x, ++y;
                } else if (a[i][x + 1].x > a[j][y + 1].x) {
                    ++y;
                } else {
                    ++x;
                }
            }

            sort(all(v));
            x = 0, y = 0;
            vector<char> vct;
            for (int k = 0; k + 1 < sz(v); ++k) {
                if (eq(v[k], v[k + 1])) {
                    continue;
                }
                ld pos = (v[k] + v[k + 1]) / 2;
                if (geq(pos, a[i].back().x) || geq(pos, a[j].back().x)) {
                    break;
                }
                while (lt(a[i][x + 1].x, pos)) {
                    ++x;
                }
                while (lt(a[j][y + 1].x, pos)) {
                    ++y;
                }
                ld val1 = a[i][x].y + (a[i][x + 1].y - a[i][x].y) / (a[i][x + 1].x - a[i][x].x) * (pos - a[i][x].x);
                ld val2 = a[j][y].y + (a[j][y + 1].y - a[j][y].y) / (a[j][y + 1].x - a[j][y].x) * (pos - a[j][y].x);
                if (val1 > val2) {
                    vct.pb('+');
                } else {
                    vct.pb('-');
                }
            }
            /*for (int k = 0; k < sz(vct); ++k) {
                cout << vct[k];
            }
            cout << "\n";*/
            for (int k = 0; k + 1 < sz(vct); ++k) {
                if (vct[k] != vct[k + 1]) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << "\n";

}