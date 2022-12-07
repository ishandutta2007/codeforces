#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 2005;
typedef long long ll;

const double PI = acos(-1.0);
const double eps = 1e-8;

int n;

struct Point {
    int x, y;
    double ang;
    void read() {
        scanf("%d%d", &x, &y);
    }
} p[N], tmp[2 * N];

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

bool cmp(Point a, Point b) {
    return dcmp(a.ang - b.ang) < 0;
}

ll gao(int o) {
    int tn = 0;
    for (int i = 0; i < n; i++) {
        if (i == o) continue;
        tmp[tn].x = p[i].x - p[o].x;
        tmp[tn].y = p[i].y - p[o].y;
        tmp[tn].ang = atan2(tmp[tn].y * 1.0, tmp[tn].x * 1.0);
        tn++;
    }
    sort(tmp, tmp + tn, cmp);
    for (int i = 0; i < tn; i++) {
        tmp[i + tn] = tmp[i];
        tmp[i + tn].ang += 2 * PI;
    }
    int r = 0;
    ll ans = 0;
    for (int l = 0; l < tn; l++) {
        while (dcmp(tmp[r + 1].ang - tmp[l].ang - PI) < 0) r++;
        ans += r - l;
    }
    ll cnt = 1;
    for (int l = 1; l < tn; l++) {
        if (dcmp(tmp[l].ang - tmp[l - 1].ang) != 0) {
            ans -= (cnt - 1) * cnt / 2;
            cnt = 1;
        } else cnt++;
    }
    ans -= (cnt - 1) * cnt / 2;
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) p[i].read();
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += gao(i);
    cout << ans / 3 << endl;
    return 0;
}