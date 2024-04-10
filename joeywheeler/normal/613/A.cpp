#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct pt {
    double x, y;
};

double sqr(double x) { return x * x; }
double dist2(pt v, pt w) { return sqr(v.x - w.x) + sqr(v.y - w.y); }
double distToSegmentSquared(pt p, pt v, pt w) {
    double l2 = dist2(v, w);
    if (abs(l2) < 1e-5) return dist2(p, v);
    double t = ((p.x - v.x) * (w.x - v.x) + (p.y - v.y) * (w.y - v.y)) / 1. / l2;
    if (t < 0) return dist2(p, v);
    if (t > 1) return dist2(p, w);
    return dist2(p, { v.x + t * (w.x - v.x),
            v.y + t * (w.y - v.y) });
}

pt p;
pt v[100005];
int n;

int main() {
    scanf("%d %lf %lf", &n, &p.x, &p.y);
    FO(i,0,n) {
        scanf("%lf %lf", &v[i].x, &v[i].y);
    }
    v[n] = v[0];
    double mn = 1e18, mx = 0;
    FO(i,0,n) mn = min(mn, distToSegmentSquared(p,v[i],v[i+1])), mx = max(mx, dist2(p,v[i]));
    printf("%.18lf\n", acos(-1) * (mx-mn));
}