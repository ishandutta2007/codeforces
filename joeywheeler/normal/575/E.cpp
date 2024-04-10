#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef double real;

const real Max = 1e5, eps = 1e-9;

struct P {
    real x, y;
    P() : x(0.), y(0.) { }
    P(real xx, real yy) : x(xx), y(yy) { }
    P(const P &p) : x(p.x), y(p.y) { }
    bool operator==(const P &p) const {
        return x == p.x && y == p.y;
    }
    bool operator<(const P &p) const {
        return (y == p.y ? x < p.x : y < p.y);
    }
};
P operator-(P a, P b) {
    return P(a.x - b.x, a.y - b.y);
}
real operator^(P a, P b) {
    return a.x*b.y - a.y*b.x;
}
bool right(P a, P b, P c) {
    return ((b-a)^(c-b)) < -eps;
}
std::vector<P> convexHull(std::vector<P> p) {
    std::vector<P> h; h.resize(3 * sz(p)); int H = 0;
    for (int i = 0; i < sz(p); i++) {
        while (H >= 2 && !right(h[H-2], h[H-1], p[i])) H--;
        h[H++] = p[i];
    }
    int midH = H;
    for (int i = sz(p)-2; i >= 0; i--) {
        while (H >= 2 && H > midH && !right(h[H-2], h[H-1], p[i])) H--;
        h[H++] = p[i];
    }
    if (H) H--;
    h.resize(H);
    return h;
}

int N, ansi;
std::vector<P> p;
double ans;

// eps shouldn't be necessary because integral at this point but... just in case?
bool within(real fanx, real fany, real fanv, real x, real y) {
    return std::abs(fanx-x) + std::abs(fany-y) <= fanv + eps;
}
void add(real x, real y) {
    assert(0 <= x); assert(x <= Max); assert(0 <= y); assert(y <= Max);
    p.pb(P(x, y));
}
void push(real x, real y, real v) {
    if (within(x, y, v, 0, 0)) {
        add(0, 0);
        assert(x-v <= 0); assert(y-v <= 0);
        add(0, y - (x-v));
        add(x - (y-v), 0);
        add(x, y+v);
        add(x+v, y);
    } else if (within(x, y, v, 0, Max)) {
        add(0, Max);
        assert(x-v <= 0); assert(y+v >= Max);
        add(0, y + (x-v));
        add(x + (y+v-Max), Max);
        add(x+v, y);
        add(x, y-v);
    } else if (within(x, y, v, Max, 0)) {
        add(Max, 0);
        assert(x+v >= Max); assert(y-v <= 0);
        add(x + (y-v), 0);
        add(Max, y + (x+v-Max));
        add(x-v, y);
        add(x, y+v);
    } else if (within(x, y, v, Max, Max)) {
        add(Max, Max);
        assert(x+v >= Max); assert(y+v >= Max);
        add(x - (y+v-Max), Max);
        add(Max, y - (x+v-Max));
        add(x, y-v);
        add(x-v, y);
    } else {
        if (x-v < 0) {
            add(0, y + (x-v));
            add(0, y - (x-v));
        } else add(x-v, y);
        if (x+v > Max) {
            add(Max, y + (x+v-Max));
            add(Max, y - (x+v-Max));
        } else add(x+v, y);
        if (y-v < 0) {
            add(x + (y-v), 0);
            add(x - (y-v), 0);
        } else add(x, y-v);
        if (y+v > Max) {
            add(x + (y+v-Max), Max);
            add(x - (y+v-Max), Max);
        } else add(x, y+v);
    }
}

struct L {
    real a, b, c;
    L(P r, P s) {
        a = r.y - s.y;
        b = s.x - r.x;
        c = (r ^ s);
    }
};
L perpBisector(P r, P s) {
    P delta = s-r;
    P midP = P((r.x + s.x) / 2, (r.y + s.y) / 2);
    P otherP = P(midP.x + delta.y, midP.y - delta.x);
    return L(midP, otherP);
}
P intersection(L l, L m) {
    return P((l.b*m.c - l.c*m.b) / (l.a*m.b - l.b*m.a),
             (l.c*m.a - l.a*m.c) / (l.a*m.b - l.b*m.a));
}

double dist(P p, P q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}
double f(P p, P q, P r) {
    P centre = intersection(perpBisector(p, q), perpBisector(q, r));
    //printf("centre = %lf %lf\n", centre.x, centre.y);
    return dist(centre, p);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        real x, y, v; scanf("%lf%lf%lf", &x, &y, &v);
        push(x, y, v);
    }
    
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    p = convexHull(p);
    //printf("convex hull of %d points:\n", sz(p));
    //for (int i = 0; i < sz(p); i++) printf("%lf %lf\n", p[i].x, p[i].y);
    
    assert(sz(p) >= 3);
    for (int i = 0; i < sz(p); i++) {
        int j = (i+1) % sz(p), k = (i+2) % sz(p);
        if (domax(ans, f(p[i], p[j], p[k]))) ansi = i;
    }
    //printf("%lf %lf %lf\n", f(p[0], p[1], p[2]), f(p[1], p[2], p[3]), f(p[3], p[4], p[5]));
    
    for (int i = ansi; i < ansi+3; i++) {
        int j = i % sz(p);
        printf("%d %d\n", int(p[j].x), int(p[j].y));
    }
}