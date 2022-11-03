#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int mod;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}

inline int mul(int x, int y) {
    return (x * ll(y)) % mod;
}

const int N = 2525;
const ld pi = acos(-1.);
int x[N], y[N];
const ld eps = 1e-12; /// MAYBE INTS????
inline bool eq(ld x, ld y) { return fabs(x - y) < eps; }
inline bool leq(ld x, ld y) { return x < y || eq(x, y); }
inline bool lss(ld x, ld y) { return x < y && !eq(x, y); }

struct Angle {
    ll y;
    ll x;
    Angle(ll y, ll x) : y(y), x(x) {}
    int typ() const {
        if (y == 0) {
            if (x < 0) {
                return 0;
            }
            return 4;
        }
        if (x == 0) {
            if (y < 0) {
                return 2;
            }
            return 6;
        }
        return 1 + (y * x < 0 ? 2 : 0) + (y > 0 ? 4 : 0);
    }
    bool operator < (const Angle& rhs) const {
        int t1 = typ();
        int t2 = rhs.typ();
        if (t1 != t2) {
            return t1 < t2;
        }
        return x * rhs.y > rhs.x * y;
    }

    ll cross(const Angle& rhs) const {
        return x * rhs.y - y * rhs.x;
    }

    Angle operator - () const {
        return Angle(-y, -x);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (int p = 0; p < n; ++p) {
        vector<pair<Angle, int>> pts;
        for (int i = 0; i < n; ++i) {
            if (i == p) {
                continue;
            }// or should i rotate a bit?????????
            pts.emplace_back(Angle(y[i] - y[p], x[i] - x[p]), i);
        }
        sort(pts.begin(), pts.end());
        for (int i = 0; i < n - 1; ++i) {
            pts.emplace_back(pts[i].first, pts[i].second);
        }
        int u = 0;
        ans += ((n - 1) * ll(n - 2) * ll(n - 3) * ll(n - 4)) / 24;
        vector<int> nxt(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            if (u == i) {
                ++u;
            }
            while (pts[i].first.cross(pts[u].first) > 0) {
                ++u;
            }
            nxt[i] = u - 1;
            ll len = nxt[i] - i;
            ans -= (len * (len - 1) * (len - 2)) / 6;
        }
    }
    cout << ans << "\n";
}