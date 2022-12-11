#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const ld eps = 1e-9;
const ld pi = 4 * atan(1.0);

const int inf = 100500;

bool lt(ld a, ld b)
{
    return b - a > eps;
}

bool eq(ld a, ld b)
{
    return abs(a - b) <= eps;
}

bool leq(ld a, ld b)
{
    return lt(a, b) || eq(a, b);
}

bool gt(ld a, ld b)
{
    return a - b > eps;
}

bool geq(ld a, ld b)
{
    return gt(a, b) || eq(a, b);
}

struct pt
{
    ld x, y;
    pt() : x(0), y(0) {}
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

const pt origin = {0, 0};

struct line
{
    ld a, b, c;
    line() {}
    line(ld aa, ld bb, ld cc)
    {
        ld tmp = sqrt(aa * aa + bb * bb);
        a = aa / tmp;
        b = bb / tmp;
        c = cc / tmp;
    }
};

ld dist(const pt& p, const line& l)
{
    return abs(p.x * l.a + p.y * l.b + l.c);
}

ld dist(const pt& p, const pt& q)
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

pt ortho(const pt& p, const line& l)
{
    ld alpha = (-p.x * l.a - p.y * l.b - l.c);
    pt n = {l.a, l.b};
    return p + n * alpha;
}

struct circle
{
    pt c;
    ld r;
};

vector<pt> intersect(const line& l, const circle& c)
{
    ld d = dist(c.c, l);
    if (gt(d, c.r)) {
        return {};
    }
    pt h = ortho(c.c, l);
    if (eq(d, c.r)) {
        return {h};
    }
    ld t = sqrt(c.r * c.r - d * d);
    pt a = {l.b, -l.a};
    return {h + a * t, h - a * t};
}

ld polar(const pt& p)
{
    ld ans = atan2(p.y, p.x);
    while (lt(ans, 0)) {
        ans += 2 * pi;
    }
    return ans;
}

vector<int> t;
int N;

void update(int l, int r, int val)
{
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            t[l] += val;
        }
        if (!(r & 1)) {
            t[r] += val;
        }
    }
}

int get(int pos)
{
    int ans = 0;
    for (pos += N; pos; pos >>= 1) {
        ans += t[pos];
    }
    return ans;
}

int count(ld angle, ld d, const circle& c)
{
    line l(sin(angle), -cos(angle), 0);
    vector<pt> v = intersect(l, c);
    if (v.empty()) {
        return 0;
    }
    ld x = dist(origin, v[0]);
    ld y = dist(origin, v.back());
    if (lt(y, x)) {
        swap(x, y);
    }
    int lf = 0, rg = inf;
    while (lf < rg - 1) {
        int md = (lf + rg) >> 1;
        if (geq(d * md, x)) {
            rg = md;
        } else {
            lf = md;
        }
    }
    int t = rg;
    int ans = 0;
    for (ld R = d * t; leq(R, y); R += d) {
        ++ans;
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    ld d;
    cin >> d;

    vector<circle> circles(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].c.x >> circles[i].c.y >> circles[i].r;
    }

    vector<vector<ld> > v(n);
    vector<ld> angles;

    for (int i = 0; i < n; ++i) {
        ld x = dist(origin, circles[i].c) - circles[i].r;
        ld x0 = circles[i].c.x;
        ld y0 = circles[i].c.y;
        ld y = dist(origin, circles[i].c) + circles[i].r;
        int lf = 0, rg = inf;
        while (lf < rg - 1) {
            int md = (lf + rg) >> 1;
            if (geq(d * md, x)) {
                rg = md;
            } else {
                lf = md;
            }
        }
        int c = rg;
        for (ld R = d * c; leq(R, y); R += d) {
            line l(-2.0 * x0, -2.0 * y0, x0 * x0 + y0 * y0 + R * R - circles[i].r * circles[i].r);
            vector<pt> p = intersect(l, {origin, R});
            for (pt& point : p) {
                v[i].pb(polar(point));
                angles.pb(polar(point));
            }
        }
        sort(all(v[i]));
        v[i].resize(unique(all(v[i])) - v[i].begin());
        if (!v[i].empty()) {
            if (lt(v[i][0], pi / 2) && geq(v[i].back(), 3 * pi / 2)) {
                for (int j = 0; j < sz(v[i]); ++j) {
                    if (gt(v[i][j], pi)) {
                        v[i][j] -= 2 * pi;
                    }
                }
                sort(all(v[i]));
                for (int j = 0; j < sz(v[i]); ++j) {
                    if (lt(v[i][j], 0)) {
                        v[i][j] += 2 * pi;
                    }
                }
            }
        }
    }
    sort(all(angles));
    angles.resize(unique(all(angles)) - angles.begin());
    /*for (ld val : angles) {
        cout << val << "\n";
    }*/
    N = sz(angles);

    t.resize(2 * N);

    for (int i = 0; i < n; ++i) {
        for (ld angle : v[i]) {
            int c = count(angle, d, circles[i]);
            int pos = lower_bound(all(angles), angle) - angles.begin();
            update(pos, pos, c);
        }
        for (int j = 0; j < sz(v[i]) - 1; ++j) {
            ld angle = (v[i][j] + v[i][j + 1]) / 2.0;
            int c = count(angle, d, circles[i]);
            int l = lower_bound(all(angles), v[i][j]) - angles.begin();
            int r = lower_bound(all(angles), v[i][j + 1]) - angles.begin();
            if (l <= r) {
                update(l + 1, r - 1, c);
                //cout << "!" << l + 1 << " " << r - 1 << "\n";
            } else {
                update(l + 1, N - 1, c);
                //cout << l + 1 << " " << N - 1 << "\n";
                update(0, r - 1, c);
                //cout << 0 << " " << r - 1 << "\n";
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, get(i));
    }

    cout << ans << "\n";

}