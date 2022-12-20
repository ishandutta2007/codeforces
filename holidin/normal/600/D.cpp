#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323846;

int main() {
    long double a, b, c, x1, y1, x2, y2, r1, r2, alp, alp1, s, p;
    //freopen("input.txt", "r", stdin);
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    long double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (min(r1, r2) + d <= max(r1, r2)) {
        cout << fixed << setprecision(12) << pi * min(r1, r2) * min(r1, r2);
        return 0;
    }
    if (r1 + r2 <= d + 1e-12) {
        cout << 0;
        return 0;
    }
    long double ans = 0;
    a = (r1 * r1 + d * d - r2 * r2) / (2 * d);
    b = sqrt(r1 * r1 - a * a);
    b *= 2;
    alp = (-b * b + 2 * r1 * r1) / (2 * r1 * r1);
    p = (r1 + r1 + b) / 2;
    s = sqrt(1 - alp * alp) * r1 * r1 / 2;
    alp1 = acos(alp);
    if (a >= 0)
        ans += pi * r1 * r1 * alp1 / (2 * pi) - s;
    else
        ans += pi * r1 * r1 - (pi * r1 * r1 * alp1 / (2 * pi) - s);
    swap(r1, r2);
    a = (r1 * r1 + d * d - r2 * r2) / (2 * d);
    b = sqrt(r1 * r1 - a * a);
    b *= 2;
    alp = (-b * b + 2 * r1 * r1) / (2 * r1 * r1);
    p = (r1 + r1 + b) / 2;
    s = sqrt(1 - alp * alp) * r1 * r1 / 2;
    alp1 = acos(alp);
    if (a >= 0)
        ans += pi * r1 * r1 * alp1 / (2 * pi) - s;
    else
        ans += pi * r1 * r1 - (pi * r1 * r1 * alp1 / (2 * pi) - s);
    cout << fixed << setprecision(12) << ans;
}