#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> point;
#define x first
#define y second

double f(point p, point o, point q) {
    int a = p.y - q.y;
    int b = q.x - p.x;
    int c = -(a * p.x + b * p.y);
    return 0.5 * fabs(a * o.x + b * o.y + c) / sqrt(a * a + b * b);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(12);

    int n;
    cin >> n;
    vector<point> pt(n);
    for (int i = 0; i < n; ++i) {
        cin >> pt[i].x >> pt[i].y;
    }

    double ans = 1e15;
    for (int i = 0; i < n; ++i) {
        point A = pt[i];
        point B = pt[(i + 1) % n];
        point C = pt[(i + 2) % n];
        ans = min(ans, f(A, B, C));
    }
    cout << ans << '\n';
}