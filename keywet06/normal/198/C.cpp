#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

double xp, yp, vp, x, y, v, r;

double dis(double x, double y) { return sqrt(x * x + y * y); }

double dis2(double x, double y) { return x * x + y * y; }

bool check(double k) {
    double ret = 0;
    double xt = dis(xp, yp) *
                cos(atan2(yp, xp) + 2 * PI / (2 * PI * dis(xp, yp) / vp) * k);
    double yt = dis(xp, yp) *
                sin(atan2(yp, xp) + 2 * PI / (2 * PI * dis(xp, yp) / vp) * k);
    if (abs(x * yt - y * xt) / dis(x - xt, y - yt) >= r) {
        ret = dis(x - xt, y - yt);
    } else if (x * xt - x * x + y * yt - y * y >= 0) {
        ret = dis(x - xt, y - yt);
    } else if (xt * x - xt * xt + yt * y - yt * yt >= 0) {
        ret = dis(x - xt, y - yt);
    } else {
        ret += sqrt(dis2(x, y) - r * r);
        ret += sqrt(dis2(xt, yt) - r * r);
        double a = acos(r / dis(x, y));
        double b = acos(r / dis(xt, yt));
        double c = acos((dis2(x, y) + dis2(xt, yt) - dis2(x - xt, y - yt)) / 2 /
                        dis(x, y) / dis(xt, yt));
        ret += (c - a - b) * r;
    }
    return ret <= k * v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> xp >> yp >> vp;
    cin >> x >> y >> v >> r;
    double lb = 0.0, rb = 1e10;
    for (int T = 0; T < 1000; ++T) {
        double mid = (lb + rb) / 2;
        if (check(mid)) {
            rb = mid;
        } else {
            lb = mid;
        }
    }
    cout << fixed << setprecision(10) << (lb + rb) / 2 << '\n';
    return 0;
}