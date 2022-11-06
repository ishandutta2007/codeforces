#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

struct point {
    int x, y;
    void scan() {
        cin >> x >> y;
    }
} ps[8];

int ccw(point a, point b, point c) {
    int xx = (b.x - a.x) * (c.y - b.y);
    int yy = (b.y - a.y) * (c.x - b.x);
    if (xx < yy) return -1;
    if (xx > yy) return 1;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < 8; ++i) ps[i].scan();
	int am = 300, aM = -300, bm = 300, bM = -300;
	for (int i = 4; i < 8; ++i) {
        am = min(am, ps[i].x + ps[i].y);
        bm = min(bm, ps[i].x - ps[i].y);
        aM = max(aM, ps[i].x + ps[i].y);
        bM = max(bM, ps[i].x - ps[i].y);
	}
	for (int i = 0; i < 4; ++i) {
        int t = ps[i].x + ps[i].y;
        if (t < am || aM < t) continue;
        t = ps[i].x - ps[i].y;
        if (t < bm || bM < t) continue;
        printf("Yes\n");
        return 0;
	}
	
	am = 200, aM = -200, bm = 200, bM = -200;
	for (int i = 0; i < 4; ++i) {
        am = min(am, ps[i].x);
        bm = min(bm, ps[i].y);
        aM = max(aM, ps[i].x);
        bM = max(bM, ps[i].y);
	}
	for (int i = 4; i < 8; ++i) {
        if (ps[i].x < am || aM < ps[i].x) continue;
        if (ps[i].y < bm || bM < ps[i].y) continue;
        printf("Yes\n");
        return 0;
	}
	for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (ccw(ps[i], ps[(i + 1) % 4], ps[j + 4]) * ccw(ps[i], ps[(i + 1) % 4], ps[(j + 1) % 4 + 4]) <= 0) {
                if (ccw(ps[j + 4], ps[(j + 1) % 4 + 4], ps[i]) * ccw(ps[j + 4], ps[(j + 1) % 4 + 4], ps[(i + 1) % 4]) <= 0) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
	}
	printf("No\n");
	return 0;
}