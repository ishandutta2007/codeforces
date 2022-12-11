#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps = 1e-7;

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b) {
    return b - a > eps;
}

bool gt(ld a, ld b) {
    return a - b > eps;
}

bool leq(ld a, ld b) {
    return lt(a, b) || eq(a, b);
}

bool geq(ld a, ld b) {
    return gt(a, b) || eq(a, b);
}

struct pt {
    ll t;
    ll x, y;
    pt() {}
    pt(ll t, ll x, ll y) : t(t), x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {-1, x - other.x, y - other.y};
    }
    bool operator==(const pt& other) const {
        return t == other.t && x == other.x && y == other.y;
    }
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

const int buben = 40;

void nein() {
    cout << "-1\n";
    exit(0);
}

ld predict(const pt& p, const pt& q, ld y) {
    ld a = p.y - q.y;
    ld b = q.x - p.x;
    ld c = cross(p, q);
    return -(b * y + c) / a;
}

const ld inf = 1e9;

void solve(ld k, ld a, ld b, ld& l, ld& r) { // kx >= a, kx <= b
    if (eq(k, 0)) {
        if (leq(a, b)) {
            l = -inf, r = inf;
        } else {
            l = inf, r = -inf;
        }
        return;
    }
    if (k > 0) {
        l = a / k, r = b / k;
    } else {
        l = b / k, r = a / k;
    }
}

void solve2(ld lf, ld rg, ld k1, ld l1, ld k2, ld l2, ld k3, ld l3, ld k4, ld l4, ld& l, ld& r) {
    ld first = inf;
    ld last = -inf;
    assert(eq(k1, k2) && eq(k3, k4));
    solve(k1 - k3, l3 - l1, l4 - l2, l, r);
    if (leq(l, r)) {
        first = min(first, l);
        last = max(last, r);
    }

    solve(k1 - k3, l4 - l2, l4 - l1, l, r);
    if (leq(l, r)) {
        ld tmpl, tmpr;
        solve(k1 - k3, l3 - l1, l4 - l1, tmpl, tmpr);
        l = max(l, tmpl);
        r = min(r, tmpr);
        if (leq(l, r)) {
            first = min(first, l);
            last = max(last, r);
        }
    }

    solve(k1 - k3, l3 - l2, l4 - l2, l, r);
    if (leq(l, r)) {
        ld tmpl, tmpr;
        solve(k1 - k3, l3 - l2, l3 - l1, tmpl, tmpr);
        l = max(l, tmpl);
        r = min(r, tmpr);
        if (leq(l, r)) {
            first = min(first, l);
            last = max(last, r);
        }
    }

    solve(k1 - k3, l4 - l2, l3 - l1, l, r);
    if (leq(l, r)) {
        first = min(first, l);
        last = max(last, r);
    }

    if (gt(first, last)) {
        l = inf;
        r = -inf;
        return;
    }

    first = max(first, lf);
    last = min(last, rg);
    if (gt(first, last)) {
        l = inf;
        r = -inf;
        return;
    }

    l = max(k1 * first + l1, k3 * first + l3);
    r = min(k2 * last + l2, k4 * last + l4);
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ld w, h;
    cin >> w >> h;

    ld e1, e2;
    cin >> e1 >> e2;

    vector<pt> p;
    for (int i = 0; i < n; ++i) {
        pt q;
        cin >> q.t >> q.x >> q.y;
        if (!p.empty() && p.back() == q) {
            continue;
        } else {
            p.pb(q);
        }
    } 
    n = sz(p);

    ld lf = 0, rg = 2e3;
    for (int step = 0; step < buben; ++step) {
        ld md = (lf + rg) / 2;
        //ld md = 2;
        int ptr = 0;
        ld l = e2, r = e2;
        ld alpha1 = 0, beta1 = e1;
        bool ok = true;
        ld tPrev = 0;
        while (ptr < n) {
            //cout << l << " " << r << " " << alpha1 << " " << beta1 << endl;
            int nx = ptr;
            while (nx + 1 < n && p[nx + 1].t == p[ptr].t) {
                ++nx;
            }
            for (int j = ptr + 2; j <= nx; ++j) {
                if (cross(p[ptr + 1] - p[ptr], p[j] - p[ptr]) != 0) {
                    nein();
                }
            }
            ld t = p[ptr].t - tPrev;
            if (ptr != nx) {
                /*if (!eq(e1, 232) || !eq(e2,818)) {
                    assert(false);
                }*/
                if (p[ptr].y == p[ptr + 1].y) {
                    nein();
                }
                ld u = predict(p[ptr], p[ptr + 1], h);
                ld v = predict(p[ptr], p[ptr + 1], 0);
                if (lt(u, 0) || gt(u, w) || lt(v, 0) || gt(v, w)) {
                    ok = false;
                    break;
                }
                l = max(l, u - md * t);
                r = min(r, u + md * t);
                if (gt(l, r)) {
                    ok = false;
                    break;
                }
                if (eq(alpha1, 0)) {
                    if (lt(beta1, v - md * t) || gt(beta1, v + md * t)) {
                        ok = false;
                        break;
                    }
                } else {
                    ld l1, r1;
                    solve(alpha1, v - md * t - beta1, v + md * t - beta1, l1, r1);
                    l1 = max(l1, ld(0));
                    r1 = min(r1, w);
                    l = max(l, l1);
                    r = min(r, r1);
                    if (gt(l, r)) {
                        ok = false;
                        break;
                    }
                }
                // ok
                l = r = u;
                alpha1 = 0, beta1 = v;
            } else {
                // 1 5 5 0 0 1 1 4
                ld alpha2 = p[ptr].y / (p[ptr].y - h);
                ld beta2 = p[ptr].x * h / (h - p[ptr].y);
                ld l1, r1;
                solve2(l, r, 1, -md * t, 1, md * t, alpha1 / alpha2, (beta1 + md * t - beta2) / alpha2, alpha1 / alpha2, (beta1 - md * t - beta2) / alpha2, l1, r1);
                l1 = max(l1, ld(0));
                r1 = min(r1, w);
                if (gt(l1, r1)) {
                    /*if (n >= 200) {
                        //cout << x << " " << y << endl;
                        cout << alpha2 << " " << beta2 << " " << w << endl;
                        return 0;
                    }*/
                    ok = false;
                    break;
                }
                ld x = l1, y = r1;
                r1 = min(r1, -beta2 / alpha2);
                l1 = max(l1, (w - beta2) / alpha2);
                //assert(-beta2 / alpha2 > (w - beta2) / alpha2);
                if (gt(l1, r1)) {
                    
                    ok = false;
                    break;
                }
                l = l1, r = r1;
                alpha1 = alpha2, beta1 = beta2;
            }


            tPrev = p[ptr].t;
            ptr = nx + 1;
        }

        if (ok) {
            rg = md;
        } else {
            lf = md;
        }
    }

    if (rg > 1.5e3) {
        cout << "-1\n";
        return 0;
    }

    cout << fixed;
    cout.precision(20);
    cout << rg << "\n";
 
}