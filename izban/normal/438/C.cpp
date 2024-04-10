#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#define double long double
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const double eps = 1e-7;

double sqr(double x) {
    return x * x;
}

bool eq(double a, double b) {
    return fabs(a - b) < eps;
}

struct pt {
    double x, y;
    
    pt() {}
    pt(double x, double y) : x(x), y(y) {}
    
    void read() {
        cin >> x >> y;
    }
    
    pt operator- (const pt &p) {
        return pt(x - p.x, y - p.y);
    }
    
    pt operator+ (const pt &p) {
        return pt(x + p.x, y + p.y);
    }
    
    pt operator* (double p) {
        return pt(p * x, p * y);
    }
    
    double operator^ (const pt &p) {
        return x * p.y - p.x * y;
    }
    
    double operator== (const pt &p) {
        return eq(x, p.x) && eq(y, p.y);
    }
    
    double d() {
        return sqrt(sqr(x) + sqr(y));
    }
};

int n;
pt a[maxn];
bool can[maxn][maxn];

bool intersect(pt a, pt b, pt c, pt d) {
    double A1 = a.y - b.y;
    double B1 = b.x - a.x;
    double C1 = -(A1 * a.x + B1 * a.y);

    double A2 = c.y - d.y;
    double B2 = d.x - c.x;
    double C2 = -(A2 * c.x + B2 * c.y);
    
    double det = A1 * B2 - A2 * B1;
    if (eq(det, 0)) return 0;
    double detx = C1 * B2 - C2 * B1;
    double dety = A1 * C2 - A2 * C1;
    
    pt e = pt(-detx / det, -dety / det);
    
    if (e == a || e == b) return 0;
    if (eq((a - e).d() + (b - e).d(), (a - b).d()) && eq((c - e).d() + (d - e).d(), (c - d).d())) return 1;
    return 0;
}

bool ok(pt o1) {
    pt o2 = o1 + pt(-111111100.333, 924512300.1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += intersect(o1, o2, a[i], a[(i + 1) % n]);
    }
    return cnt % 2 == 1;
}

bool check(int i, int j) { // nooo, pleeeaassee, i dont want to write that
    if (abs(i - j) == 1 || min(i, j) == 0 && max(i, j) == n - 1) return 1;
    
    for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        bool bad = true;
        bad &= eq(((a[i] - a[k]) ^ (a[j] - a[k])), 0);
        bad &= eq((a[k] - a[i]).d() + (a[k] - a[j]).d(), (a[i] - a[j]).d());
        if (bad) return 0;
    }
    
    for (int k = 0; k < n; k++) {
        if (intersect(a[i], a[j], a[k], a[(k + 1) % n])) {
            return 0;
        }
    }
    
    pt o = (a[i] + a[j]) * 0.5;
    if (ok(o)) return 1;
    return 0;
}

int dp[maxn][maxn];

int getdp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r || r - l == 1 || r == 0 && l == n - 1) return dp[l][r] = 1;
    dp[l][r] = 0;
    for (int i = (l + 1) % n; i != r; i = (i + 1) % n) {
        if (can[l][i] && can[i][r]) {
            dp[l][r] = (dp[l][r] + 1LL * getdp(l, i) * getdp(i, r)) % mod;
        }
    }
    return dp[l][r];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) a[i].read();
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                can[j][i] = can[i][j] = check(i, j);
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << getdp(0, n - 1) << endl;
    }

	return 0;
}