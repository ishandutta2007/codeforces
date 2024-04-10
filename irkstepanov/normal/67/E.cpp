#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

struct line {
    ll a, b, c;
    line() {}
    line(const pt& p, const pt& q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
    }
};

const ll inf = 1e9;

struct frac {
    ll num, den;
    frac() {}
    frac(ll a, ll b) {
        if (b < 0) {
            a *= (-1), b *= (-1);
        }
        ll g = __gcd(abs(a), abs(b));
        num = a / g, den = b / g;
    }
    bool operator<(const frac& other) const {
        return num * other.den < other.num * den;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    ll y = p[0].y;
    frac xmin(-inf, 1);
    frac xmax(inf, 1);

    for (int i = 1; i < n; ++i) {
        line l(p[(i + 1) % n], p[i]);
        frac f(-l.b * y - l.c, l.a);

        if (l.a == 0 && l.b * y + l.c < 0) {
            xmin = frac(inf, 1);
            xmax = frac(-inf, 1);
        }

        if (l.a > 0) {
            if (xmin < f) {
                xmin = f;
            }
        } else if (l.a < 0) {
            if (f < xmax) {
                xmax = f;
            }
        }
    }

    ll lf = (xmin.num + xmin.den - 1) / xmin.den;
    ll rg = xmax.num / xmax.den;
    if (xmax.num < 0) {
        cout << "0\n";
        return 0;
    }

    if (lf > rg) {
        cout << "0\n";
    } else {
        cout << rg - lf + 1 << "\n";
    }

}