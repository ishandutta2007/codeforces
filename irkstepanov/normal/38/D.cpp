#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const ld eps = 1e-9;

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || eq(a, b);
}

bool geq(ld a, ld b)
{
    return gt(a, b) || eq(a, b);
}

struct pt
{
    ld x, y;
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator-(const pt& other) const
    {
        return {x - other.x, y - other.y};
    }
    pt operator+(const pt& other) const
    {
        return {x + other.x, y + other.y};
    }
    pt operator*(ld k) const
    {
        return {x * k, y * k};
    }
};

bool inside(const pt& p, const pt& a, const pt& b)
{
    ld xmin = min(a.x, b.x);
    ld xmax = max(a.x, b.x);
    ld ymin = min(a.y, b.y);
    ld ymax = max(a.y, b.y);
    return geq(p.x, xmin) && leq(p.x, xmax) && geq(p.y, ymin) && leq(p.y, ymax);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<pt> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    }

    vector<pt> c(n);
    vector<ld> m(n);
    for (int i = 0; i < n; ++i) {
        ld v = abs(a[i].x - b[i].x);
        m[i] = v * v * v;
        c[i] = (a[i] + b[i]) * 0.5;
    }

    vector<pt> d(n);
    for (int i = 1; i < n; ++i) {
        ld sum_m = m[i];
        pt sum_c = c[i] * m[i];
        d[i] = c[i];
        for (int j = i - 1; j >= 0; --j) {
            sum_m += m[j];
            sum_c = sum_c + c[j] * m[j];
            d[j] = sum_c * (1 / sum_m);
        }
        bool ok = true;
        for (int j = i; j; --j) {
            if (!inside(d[j], a[j - 1], b[j - 1])) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";

}