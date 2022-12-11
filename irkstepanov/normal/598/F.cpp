#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long double ld;

const ld eps = 1e-6;

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

struct pt
{
    ld x, y;
    int id;
    pt(ld newX = 0, ld newY = 0, int newId = -1)
    : x(newX)
    , y(newY)
    , id(newId)
    {}
    bool operator<(const pt& other)
    {
        if (!eq(x, other.x)) {
            return lt(x, other.x);
        }
        return lt(y, other.y);
    }
};

struct triangle
{
    pt a, b, c;
};

struct edge
{
    pt p1, p2;
};

ld dist(const pt& a, const pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct line
{
    ld a, b, c;
};

bool onLine(const line& l, const pt& p)
{
    return eq(p.x * l.a + p.y * l.b + l.c, 0.0);
}

line buildLine(const pt& p, const pt& q)
{
    line l;
    l.a = p.y - q.y;
    l.b = q.x - p.x;
    l.c = p.x * q.y - p.y * q.x;
    return l;
}

pair<pt, bool> intersectLines(const line& p, const line& q)
{
    if (eq(p.a * q.b, p.b * q.a)) {
        pt anyPoint;
        return mp(anyPoint, false);
    }
    ld det0 = p.a * q.b - p.b * q.a;
    ld det1 = (-p.c) * q.b - p.b * (-q.c);
    ld det2 = p.a * (-q.c) - (-p.c) * q.a;
    pt ans = pt(det1 / det0, det2 / det0, -1);
    return mp(ans, true);
}

pair<pt, bool> intersect(const line& l, const pt& p, const pt& q)
{
    line m = buildLine(p, q);
    pair<pt, bool> ans = intersectLines(l, m);
    if (!ans.second) {
        return ans;
    }
    if (eq(dist(p, q), dist(p, ans.first) + dist(ans.first, q))) {
        return ans;
    } else {
        ans.second = false;
        return ans;
    }
}

int sign(const line& l, const pt& p)
{
    ld x = l.a * p.x + l.b * p.y + l.c;
    if (lt(x, 0.0)) {
        return -1;
    }
    if (lt(0.0, x)) {
        return 1;
    }
    return 0;
}

bool collinear(const pt& p1, const pt& p2, const pt& p3)
{
    line l = buildLine(p1, p2);
    return onLine(l, p3);
}

ld area(const pt& a, const pt& b, const pt& c)
{
    return 0.5 * abs((a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x));
}

bool convex(const pt& p1, const pt& p2, const pt& p3)
{
    //cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << "\n";
    ld x = (p1.x - p2.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p1.y - p2.y);
    //cout << x << "\n";
    return lt(x, 0.0);
}

bool inside(const pt& p, const pt& p1, const pt& p2, const pt& p3)
{
    ld s1 = area(p, p1, p2) + area(p, p2, p3) + area(p, p3, p1);
    ld s2 = area(p1, p2, p3);
    return eq(s1, s2);
}

bool trivial(const pt& p, const pt& p1, const pt& p2, const pt& p3)
{
    if (eq(p.x, p1.x) && eq(p.y, p1.y)) {
        return true;
    }
    if (eq(p.x, p2.x) && eq(p.y, p2.y)) {
        return true;
    }
    if (eq(p.x, p3.x) && eq(p.y, p3.y)) {
        return true;
    }
    return false;
}

ld intersectTriangle(const line& l, const triangle& t)
{
    const pt &p1 = t.a, &p2 = t.b, &p3 = t.c;
    int cnt = 0;
    if (onLine(l, p1)) {
        ++cnt;
    }
    if (onLine(l, p2)) {
        ++cnt;
    }
    if (onLine(l, p3)) {
        ++cnt;
    }
    if (cnt == 2) {
        return 0.0;
    }
    vector<pt> points;
    if (onLine(l, p1)) {
        points.pb(p1);
    }
    if (onLine(l, p2)) {
        points.pb(p2);
    }
    if (onLine(l, p3)) {
        points.pb(p3);
    }
    pair<pt, bool> p = intersect(l, p1, p2);
    if (p.second && !trivial(p.first, p1, p2, p3)) {
        points.pb(p.first);
    }
    p = intersect(l, p2, p3);
    if (p.second && !trivial(p.first, p1, p2, p3)) {
        points.pb(p.first);
    }
    p = intersect(l, p3, p1);
    if (p.second && !trivial(p.first, p1, p2, p3)) {
        points.pb(p.first);
    }
    if (sz(points) != 2) {
        return 0.0;
    }
    return dist(points[0], points[1]);
}

ld orientedArea(const pt& a, const pt& b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, tt;
    scanf("%d%d", &n, &tt);

    vector<pt> vertices(n);

    for (int i = 0; i < n; ++i) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        vertices[i] = {(ld) x, (ld) y, i};
    }

    vector<char> good(n, true);
    for (int i = 0; i < n; ++i) {
        pt &p1 = vertices[(i - 1 + n) % n];
        pt &p2 = vertices[i];
        pt &p3 = vertices[(i + 1) % n];
        if (collinear(p1, p2, p3)) {
            good[i] = false;
        }
    }

    vector<pt> tmp;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            tmp.pb(vertices[i]);
        }
    }
    vertices = tmp;
    n = sz(vertices);

    for (int i = 0; i < n; ++i) {
        vertices[i].id = i;
    }

    ld totalArea = 0.0;
    for (int i = 0; i < n; ++i) {
        totalArea += orientedArea(vertices[i], vertices[(i + 1) % n]);
    }

    vector<triangle> triangles;
    vector<edge> edges;

    vector<int> linkL(n), linkR(n);
    for (int i = 0; i < n; ++i) {
        linkL[i] = (i - 1 + n) % n;
        linkR[i] = (i + 1) % n;
    }

    for (int i = 0; i < n; ++i) {
        edge e = {vertices[i], vertices[(i + 1) % n]};
        edges.pb(e);
    }

    int pos = 0;

    while (n > 3) {
        pt &p1 = vertices[linkL[pos]], &p2 = vertices[pos], &p3 = vertices[linkR[pos]];
        //cout << (convex(p1, p2, p3) ? 1 : 0);
        if ((convex(p1, p2, p3) && totalArea > 0) || (!convex(p1, p2, p3) && totalArea < 0)) {
            //cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << p3.x << " " << p3.y << "\n";
            bool ok = true;
            int tmp = linkR[linkR[pos]];
            while (tmp != linkL[pos]) {
                if (inside(vertices[tmp], p1, p2, p3)) {
                    ok = false;
                    break;
                }
                tmp = linkR[tmp];
            }
            if (ok) {
                //cout << "OKED\n";
                triangle t = {p1, p2, p3};
                triangles.pb(t);
                edge e = {p1, p3};
                edges.pb(e);
                int l = linkL[pos], r = linkR[pos];
                linkR[l] = r;
                linkL[r] = l;
                --n;
                if (collinear(vertices[linkL[l]], p1, p3)) {
                    linkR[linkL[l]] = linkR[l];
                    linkL[linkR[l]] = linkL[l];
                    --n;
                }
                if (collinear(vertices[linkR[r]], p1, p3)) {
                    linkR[pos] = linkR[r];
                    linkL[linkR[r]] = linkL[r];
                    linkR[linkL[r]] = linkR[r];
                    --n;
                }
            }
        }
        pos = linkR[pos];
    }

    triangle t = {vertices[linkL[pos]], vertices[pos], vertices[linkR[pos]]};
    triangles.pb(t);

    //for (int i = 0; i < sz(triangles); ++i) {
    //    cout << triangles[i].a.x << " " << triangles[i].a.y << " " << triangles[i].b.x << " " << triangles[i].b.y << " " << triangles[i].c.x << " " << triangles[i].c.y << "\n";
    //}

    while (tt--) {
        double x, y;
        pt p1, p2;
        scanf("%lf%lf", &x, &y);
        p1 = {(ld) x, (ld) y, -1};
        scanf("%lf%lf", &x, &y);
        p2 = {(ld) x, (ld) y, -1};
        line l = buildLine(p1, p2);
        ld ans = 0.0;
        for (int i = 0; i < sz(edges); ++i) {
            if (onLine(l, edges[i].p1) && onLine(l, edges[i].p2)) {
                ans += dist(edges[i].p1, edges[i].p2);
            }
        }
        for (int i = 0; i < sz(triangles); ++i) {
            ans += intersectTriangle(l, triangles[i]);
        }
        double ANS = ans;
        printf("%.10lf\n", ANS);
    }

}