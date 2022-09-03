#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define forn(i, l, r) for (int i = l; i < r; i++)
const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int prost = 239;
const ll prost64 = 239;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int MAX_N = 5000001;
const int km = (1 << 18) - 1;

//geometry
struct point
{
    ld x, y;

    point()
    {
        x = y = 0;
    }

    point(ld a, ld b)
    {
        x = a;
        y = b;
    }

    bool operator==(const point &p) const
    {
        return (fabs(x - p.x) < eps && fabs(y - p.y) < eps);
    }

    ld polar()
    {
        return atan2(y, x);
    }

    void read()
    {
        cin >> x >> y;
    }

    void write()
    {
        cout << x << " " << y << " ";
    }
};

struct vect
{
    ld x, y;

    vect()
    {
        x = y = 0;
    }

    vect(point a, point b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    vect(ld a, ld b)
    {
        x = a;
        y = b;
    }

    bool operator==(const vect &p) const
    {
        return (fabs(x - p.x) < eps && fabs(y - p.y) < eps);
    }

    vect operator+(const vect &v)
    {
        vect ans;
        ans.x = x + v.x;
        ans.y = y + v.y;
        return ans;
    }

    ld operator*(const vect &v) const
    {
        return x * v.x + y * v.y;
    }

    ld operator^(const vect &v) const
    {
        return x * v.y - y * v.x;
    }

    vect operator*(const ld &k) const
    {
        vect v;
        v.x = x * k;
        v.y = y * k;
        return v;
    }

    ld leng()
    {
        return sqrt(x * x + y * y);
    }

    vect contr()
    {
        vect v;
        v.x = -y;
        v.y = x;
        return v;
    }

    void read()
    {
        cin >> x >> y;
    }

    void read_vect_point()
    {
        point p1, p2;
        p1.read();
        p2.read();
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }

    void write()
    {
        cout << x << " " << y << " ";
    }
};

struct line
{
    ld a, b, c;

    line()
    {
        a = b = c = 0;
    }

    line(point p, vect v)
    {
        a = -v.y;
        b = v.x;
        c = v.y * p.x - v.x * p.y;
    }

    line(ld x, ld y, ld z)
    {
        a = x;
        b = y;
        c = z;
    }

    bool operator==(const line &l) const
    {
        return (fabs(a - l.a) < eps && fabs(b - l.b) < eps && fabs(c - l.c) < eps);
    }

    vect napr()
    {
        vect v;
        v.x = -b;
        v.y = a;
        return v;
    }

    vect norm()
    {
        vect v;
        v.x = a;
        v.y = b;
        return v;
    }

    bool is(point p)
    {
        return (fabs(a * p.x + b * p.y + c) < eps);
    }

    ld height(point p)
    {
        return fabs(p.x * a + p.y * b + c) / sqrt(a * a + b * b);
    }

    ld f(point p)
    {
        return (a * p.x + b * p.y + c);
    }

    void read()
    {
        cin >> a >> b >> c;
    }

    void write()
    {
        cout << a << " " << b << " " << c << " ";
    }

    point rand_point()
    {
        point p;
        p.x = -(c * a) / (a * a + b * b);
        p.y = -(c * b) / (a * a + b * b);
        return p;
    }
};

struct circle
{
    point p;
    ld r;

    circle()
    {
        p = point(0, 0);
        r = 0;
    }

    circle(point x, ld t)
    {
        p = x;
        r = t;
    }

    bool operator==(const circle &l) const
    {
        return (p == l.p && fabs(r - l.r) < eps);
    }

    ld sqr(ld a)
    {
        return (a * r * r) / 2;
    }

    bool check_good()
    {
        return r > eps;
    }

    ld len(ld a)
    {
        return a * r;
    }

    ld degree(point c)
    {
        ld len = (c.x - p.x) * (c.x - p.x) + (c.y - p.y) * (c.y - p.y);
        return len - r * r;
    }

    bool in(point t)
    {
        vect v = vect(p, t);
        return (v.leng() < r + eps);
    }

    int pos(point t)
    {
        ld d = degree(t);
        if (fabs(d) < eps)
            return 1;
        if (d < 0)
            return 0;
        return 2;
    }

    void read()
    {
        p.read();
        cin >> r;
    }

    void write()
    {
        p.write();
        cout << r << " ";
    }
};

bool cmp_polar(point p1, point p2)
{
    vect v1 = vect(point(0, 0), p1);
    vect v2 = vect(point(0, 0), p2);
    if (fabs((v1 ^ v2)) > eps)
        return 0 < (v1 ^ v2);
    else
        return (v1 * v1) < (v2 * v2);
}

struct polygon
{
    int n;
    vector<point> p;

    polygon()
    {
        n = 0;
    }

    polygon(vector<point> v)
    {
        p = v;
        n = v.size();
    }

    ld square()
    {
        vector<vect> v;
        for (int i = 0; i < n; i++)
            v.push_back(vect(point(0, 0), p[i]));
        ld ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans += v[i] ^ v[i + 1];
        ans += v[n - 1] ^ v[0];
        ans /= 2;
        return fabs(ans);
    }

    ld length()
    {
        ld ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans += vect(p[i], p[i + 1]).leng();
        ans += vect(p[n - 1], p[0]).leng();
        return ans;
    }

    void go(vect v)
    {
        for (int i = 0; i < n; i++)
            p[i].x += v.x, p[i].y += v.y;
    }

    ld dist(point r)
    {
        ld ans = -1;
        for (int i = 0; i < n; i++)
            ans = max(ans, vect(r, p[i]).leng());
        return ans;
    }

    polygon convex_hull()
    {
        point to = p[0];
        for (int i = 0; i < n; i++)
            if (p[i].y < to.y || (fabs(p[i].y - to.y) < eps && p[i].x < to.x))
                to = p[i];
        go(vect(to, point(0, 0)));
        sort(p.begin(), p.end(), cmp_polar);
        vector<point> s;
        s.push_back(p[0]);
        s.push_back(p[1]);
        for (int i = 2; i < n; i++)
        {
            while (s.size() > 1 && (vect(s[s.size() - 2], s[s.size() - 1]) ^ vect(s[s.size() - 2], p[i])) < 0)
                s.pop_back();
            s.push_back(p[i]);
        }
        polygon r = polygon(s);
        r.go(vect(point(0, 0), to));
        return r;
    }

    void read()
    {
        cin >> n;
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i].read();
    }

    void write()
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            p[i].write();
            cout << endl;
        }
    }
};

///interface
///5 structures - point, vect, line, circle, polygon
///functions:
ld deg_to_rad(ld a); ///perevod ugla is gradusov v radianu
ld rad_to_deg(ld a); ///perevod ugla is radian v gradusu
point read_point_polar(); ///schitat tochku v polyarnoy sisteme
vect radius_v(point p); ///radius vector tochki p
ld polar_angle(point p); ///polyarnuy ugol tochki p
point point_napr(ld a); ///tohka s polyarnum uglom a
ld angle_vect(vect a, vect b); ///ugol mezdu vectorami
ld length(point p1, point p2); ///rasstoyanie ot p1 do p2
line line_point(point p1, point p2); ///pryamaya po 2 tochkam
point go(point p, vect v); ///peremestitsya is p na vector v
line go_line(line l, vect v); ///peremestit pryamuu na vector v
vect do_len(ld len, vect v); ///sdelat dlinu v ravnoi len
bool cmp_polar(point p1, point p2); ///standartnuy comparator dlya tochek
bool is_in_luch(point p1, point vn, point vk); ///lezhit li p1 na luche vn -> vk
bool is_in_one_side(line l, point p1, point p2); ///lezhit li p1 i p2 v odnoy poluploskosti otnositelno l
bool is_in_otr(point p, point vn, point vk); ///lezhit li p na otrezke vn - vk
ld dist_to_otr(point p, point vn, point vk); ///rasstoyanie ot tochki p do otreska vn - vk
int kol_intersec_line_line(line l1, line l2); ///kolichestvo tochek peresechenia l1 i l2 ! 2 - beskon. mnogo
point intersection_line_line(line l1, line l2); ///tochka peresecheniya l1 i l2 ! no check
line centr_perp(point p1, point p2); ///seredinniy perpendicular k otrezky p1, p2
point otnosh(point a, point b, ld m, ld n); ///tochka v otnoshenii m k n delit p1 - p2
line biss(point a, point b, point c); ///bissektisa ugla a - b - c
line median(point a, point b, point c); ///mediana treug a - b - c
line heig(point p, line l); /// pryamaya - vysota na l is p
point perp(point p, line l); ///perpendicular is p na l
point simm(point p, line l); ///simmetrichnay p tochka otnos. l
circle in_circle(point a, point b, point c); ///vpisannaya okruznost treug. a - b - c
circle out_circle(point a, point b, point c); ///opisannaya okruznost treug. a - b - c
int kol_intersec_circle_line(circle c, line l); ///kolichestvo tochek peresecheniya okr i pryamoy
pair<point, point> intersection_circle_line(circle c, line l); ///para tochek peresecheniya okr i pryamoy
line rad_os(circle c1, circle c2); ///radikalnaya os c1 i c2
int kol_intersec_circle_circle(circle c1, circle c2); ///kolichestvo tochek peresecheniya okr i okr
pair<point, point> intersection_circle_circle(circle c1, circle c2); ///para tochek peresecheniya okr i okr
int kol_tangent(circle c, point p); ///kolichestvo kasatelnuh k c is tochki p
pair<point, point> tangent(circle c, point p); ///tohki kasaniya kasatrlnuh is p k c
line tangent_point(circle c, point p); ///esly p na c to kasatelnaya k c v tochke p
ld square_treug(point a, point b, point c); ///ploshad treugolnika
ld square_treug_stor(ld a, ld b, ld c); ///ploshad treugolnika so storonami
polygon treug(point a, point b, point c); /// treugolnik a - b - c
bool in_polygon_easy(point p, polygon t); /// proverka togo chto p lezhit vnutri vup mnogoug t

ld deg_to_rad(ld a)
{
    return (a / 180) * pi;
}

ld rad_to_deg(ld a)
{
    return (a / pi) * 180;
}

point read_point_polar()
{
    ld r, a;
    cin >> r >> a;
    a = deg_to_rad(a);
    return point(r * cos(a), r * sin(a));
}

ld angle_vect(vect a, vect b)
{
    ld an = atan2(a ^ b, a * b);
    //if (an < 0)
    //    an += 2 * pi;
    return fabs(an);
}

vect radius_v(point p)
{
    return vect(point(0, 0), p);
}

ld polar_angle(point p)
{
    vect xn = radius_v(point(1, 0));
    vect yn = radius_v(point(0, 1));
    if (p.x >= 0 && p.y >= 0)
        return angle_vect(radius_v(p), xn);
    if (p.x >= 0 && p.y < 0)
        return (3 * pi) / 2 + angle_vect(yn * (-1), radius_v(p));
    if (p.x < 0 && p.y < 0)
        return pi + angle_vect(xn * (-1), radius_v(p));
    return pi / 2 + angle_vect(yn, radius_v(p));
}

ld length(point p1, point p2)
{
    return vect(p1, p2).leng();
}

point point_napr(ld a)
{
    point p = point(cos(a), sin(a));
    vect v = vect(point(0, 0), p);
    return go(point(0, 0), v);
}

line line_point(point p1, point p2)
{
    return line(p1, vect(p1, p2));
}

point go(point p, vect v)
{
    return point(p.x + v.x, p.y + v.y);
}

line go_line(line l, vect v)
{
    vect n = l.napr();
    point p = l.rand_point();
    point ne = go(p, v);
    return line(ne, n);
}

vect do_len(ld len, vect v)
{
    ld r = v.leng();
    return vect(v.x * len / r, v.y * len / r);
}

bool is_in_luch(point p1, point vn, point vk)
{
    ld r = vect(vn, p1).leng();
    vect v = vect(vn, vk);
    line l = line(vn, v);
    if (!l.is(p1))
        return false;
    v = do_len(r, v);
    point p = go(vn, v);
    return (p == p1);
}

bool is_in_one_side(line l, point p1, point p2)
{
    if (l.is(p1) || l.is(p2))
        return true;
    return (!((l.f(p1) < 0) ^ (l.f(p2) < 0)));
}

bool is_in_otr(point p, point vn, point vk)
{
    return is_in_luch(p, vn, vk) && is_in_luch(p, vk, vn);
}

ld dist_to_otr(point p, point vn, point vk)
{
    line l = line_point(vn, vk);
    if (l.is(p))
    {
        if (is_in_otr(p, vn, vk))
            return 0;
        return min(length(p, vn), length(p, vk));
    }
    point osn = perp(p, l);
    if (is_in_otr(osn, vn, vk))
        return length(p, osn);
    return min(length(p, vn), length(p, vk));
}

int kol_intersec_line_line(line l1, line l2)
{
    ld d = l1.a * l2.b - l1.b * l2.a;
    ld dx = -l1.c * l2.b + l2.c * l1.b;
    ld dy = -l1.a * l2.c + l2.a * l1.c;
    if (fabs(d) < eps && fabs(dx) < eps && fabs(dy) < eps)
        return 2;
    if (fabs(d) < eps)
        return 0;
    return 1;
}

point intersection_line_line(line l1, line l2)
{
    ld d = l1.a * l2.b - l1.b * l2.a;
    ld dx = -l1.c * l2.b + l2.c * l1.b;
    ld dy = -l1.a * l2.c + l2.a * l1.c;
    return point(dx / d, dy / d);
}

line centr_perp(point p1, point p2)
{
    vect v = vect(p1, p2);
    v = vect(v.y, -v.x);
    point m = point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    return line(m, v);
}

point otnosh(point a, point b, ld m, ld n)
{
    ld s = m + n;
    return point((m * a.x + n * b.x) / s, (m * a.y + n * b.y) / s);
}

line biss(point a, point b, point c)
{
    vect v1 = vect(b, a);
    vect v2 = vect(b, c);
    v1 = do_len(1, v1);
    v2 = do_len(1, v2);
    vect v = v1 + v2;
    if (v.leng() < eps)
        return line(b, line_point(b, a).norm());
    return line(b, v);
}

line median(point a, point b, point c)
{
    point s = otnosh(a, c, 1, 1);
    return line_point(b, s);
}

point perp(point p, line l)
{
    return intersection_line_line(l, heig(p, l));
}

point simm(point p, line l)
{
    point g = perp(p, l);
    vect v = vect(p, g);
    return go(g, v);
}

line heig(point p, line l)
{
    return line(p, l.norm());
}

circle in_circle(point a, point b, point c)
{
    circle ans;
    ans.p = intersection_line_line(biss(a, b, c), biss(b, a, c));
    ans.r = line_point(a, b).height(ans.p);
    return ans;
}

circle out_circle(point a, point b, point c)
{
    line l1 = centr_perp(a, b);
    line l2 = centr_perp(a, c);
    circle ans;
    ans.p = intersection_line_line(l1, l2);
    ans.r = vect(ans.p, a).leng();
    return ans;
}

int kol_intersec_circle_line(circle c, line l)
{
    ld h = l.height(c.p);
    if (fabs(h - c.r) < eps)
        return 1;
    return (c.r > h ? 2 : 0);
}

pair<point, point> intersection_circle_line(circle c, line l)
{
    ld h = l.height(c.p);
    ld q = sqrt(c.r * c.r - h * h);
    point p = perp(c.p, l);
    vect go1 = do_len(q, l.napr());
    vect go2 = go1 * (-1);
    return make_pair(go(p, go1), go(p, go2));
}

line rad_os(circle c1, circle c2)
{
    line l;
    l.a = 2 * (c2.p.x - c1.p.x);
    l.b = 2 * (c2.p.y - c1.p.y);
    l.c = c1.p.x * c1.p.x + c1.p.y * c1.p.y - c2.p.x * c2.p.x - c2.p.y * c2.p.y + c2.r * c2.r - c1.r * c1.r;
    return l;
}

int kol_intersec_circle_circle(circle c1, circle c2)
{
    line l = rad_os(c1, c2);
    if (l.napr() == vect(0, 0) && fabs(c1.r - c2.r) < eps)
        return 3;
    else if (l.napr() == vect(0, 0))
        return 0;
    return kol_intersec_circle_line(c1, l);
}

pair<point, point> intersection_circle_circle(circle c1, circle c2)
{
    return intersection_circle_line(c1, rad_os(c1, c2));
}

int kol_tangent(circle c, point p)
{
    ld deg = c.degree(p);
    if (fabs(deg) < eps)
        return 1;
    if (deg < 0)
        return 0;
    return 2;
}

line tangent_point(circle c, point p)
{
    ld a = p.x - c.p.x;
    ld b = p.y - c.p.y;
    return line(a, b, -c.r * c.r - a * c.p.x - b * c.p.y);
}

pair<point, point> tangent(circle c, point p)
{
    ld deg = c.degree(p);
    circle n = circle(p, sqrt(deg));
    return intersection_circle_circle(n, c);
}

ld square_treug(point a, point b, point c)
{
    return treug(a, b, c).square();
}

ld square_treug_stor(ld a, ld b, ld c)
{
    ld p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

polygon treug(point a, point b, point c)
{
    vector<point> y;
    y.push_back(a);
    y.push_back(b);
    y.push_back(c);
    return y;
}

bool in_polygon_easy(point p, polygon t)
{
    vector<polygon> v;
    for (int i = 0; i < t.n - 1; i++)
        v.push_back(treug(t.p[i], t.p[i + 1], p));
    ld sq = t.square();
    ld now = 0;
    for (int i = 0; i < v.size(); i++)
        now += v[i].square();
    return fabs(sq - now) < eps;
}
//over

string int_to_str(ll n)
{
    if (n == 0)
        return "";
    return int_to_str(n / 10) + (char)('0' + n % 10);
}

ll str_to_int(string s)
{
    ll ans = 0;
    for (char x : s)
        ans = 10LL * ans + (x - '0');
    return ans;
}

vector<ld> v;

int main()
{   /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    fast_read;
    PREX(30);
    polygon t;
    t.read();
    if (t.n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < t.n; i++)
        v.push_back(polar_angle(t.p[i]));
    sort(v.begin(), v.end());
    int n = v.size();
    ld ans = v[n - 1] - v[0];
    for (int i = 1; i < n; i++)
        ans = min(ans, 2 * pi + v[i - 1] - v[i]);
    cout << rad_to_deg(ans);
    return 0;
}