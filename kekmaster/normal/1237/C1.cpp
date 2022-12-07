#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
#include <bits/stdc++.h>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

const int N = 5e4 + 10;
int n;
struct Point {
    int x, y, z;
    int id;
    Point() : x(), y(), z(), id() {}
    Point(int _x, int _y, int _z, int _id) : x(_x), y(_y), z(_z), id(_id) {}
    void read(int _id) {
        id = _id;
        scanf("%d%d%d", &x ,&y, &z);
    }
    bool operator< (const Point& p) const {
        if (x != p.x)
            return x < p.x;
        if (y != p.y)
            return y < p.y;
        return z < p.z;
    }
};

vector<Point> solve_z(vector<Point> pts) {
    for(int i = 0; i + 1 < int(pts.size()); i += 2)
        printf("%d %d\n", pts[i].id, pts[i + 1].id);
    if (pts.size() % 2 == 0)
        return {};
    else
        return {pts.back()};
}

vector<Point> solve_y(vector<Point> pts) {
    dbg("Y");
    for(auto p : pts)
        dbg(p.x, p.y, p.z, p.id);
    vector<Point> pts_n;
    int st = 0;
    for(int i = 0; i <= (int)pts.size(); ++i)
        if (i == int(pts.size()) || pts[i].y != pts[st].y) {
            vector<Point> seg(pts.begin() + st, pts.begin() + i);
            seg = solve_z(seg);
            if (!seg.empty())
                pts_n.push_back(seg[0]);
            st = i;
        }
    for(int i = 0; i + 1 < int(pts_n.size()); i += 2)
        printf("%d %d\n", pts_n[i].id, pts_n[i + 1].id);
    if (pts_n.size() % 2 == 0)
        return {};
    else
        return {pts_n.back()};
}

vector<Point> solve_x(vector<Point> pts) {
    vector<Point> pts_n;
    int st = 0;
    for(int i = 0; i <= (int)pts.size(); ++i)
        if (i == int(pts.size()) || pts[i].x != pts[st].x) {
            vector<Point> seg(pts.begin() + st, pts.begin() + i);
            seg = solve_y(seg);
            if (!seg.empty())
                pts_n.push_back(seg[0]);
            st = i;
        }
    for(int i = 0; i + 1 < int(pts_n.size()); i += 2)
        printf("%d %d\n", pts_n[i].id, pts_n[i + 1].id);
    if (pts_n.size() % 2 == 0)
        return {};
    else
        return {pts_n.back()};
}

void solve() {
    vector<Point> pts;
    scanf("%d", &n);
    pts.resize(n);
    for(int i = 0; i < n; ++i)
        pts[i].read(i + 1);
    sort(pts.begin(), pts.end());
    pts = solve_x(pts);
    if (!pts.empty())
        throw;
}

int main() {
#ifndef LOCAL
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

		int test_count = 1;
#ifdef MULTITEST
		scanf("%d", &test_count);
		char endl1[5];
		fgets(endl1, 5, stdin);
#endif
		for (int i = 0; i < test_count; ++i) {
#ifdef CASES
			printf("Case #%d: ", i + 1);
			solve();
			eprintf("Passed case #%d:\n", i + 1);
#else
			solve();
#endif
		}
	dbg_time();
    return 0;
}