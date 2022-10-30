#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

double x, y;
double vx, vy, ux, uy;
double vmax, t;

bool can(double T) {
    double X = x, Y = y;
    X -= vx * min(t,T);
    Y -= vy * min(t,T);
    X -= ux * max(0.,T-t);
    Y -= uy * max(0.,T-t);
    if (sqrt(X*X+Y*Y) / vmax <= T) {
        return true;
    }
    return false;
}

int main() {
    double ox, oy;
    scanf("%lf %lf %lf %lf", &ox, &oy, &x, &y);
    x -= ox; y -= oy;
    scanf("%lf %lf", &vmax, &t);
    scanf("%lf %lf %lf %lf", &vx, &vy, &ux, &uy);
    double s = 0, e = 1e10;
    FO(Z,0,512) {
        double md = (s+e)/2;
        if (can(md)) {
            e = md;
        } else s = md;
    }
    printf("%.20lf\n", s);
}