#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }

    long long operator % (const Point &a) const {
        return 1LL * x * a.y - 1LL * a.x * y;
    }

    int getArea(void) const {
        if (x > 0 && y == 0) return 0;
        if (x > 0 && y > 0) return 1;
        if (x == 0 && y > 0) return 2;
        if (x < 0 && y > 0) return 3;
        if (x < 0 && y == 0) return 4;
        if (x < 0 && y < 0) return 5;
        if (x == 0 && y < 0) return 6;
        if (x > 0 && y < 0) return 7;
    }
};

bool CompareCCW(const Point &a, const Point &b) {
    int ta = a.getArea();
    int tb = b.getArea();
    if (ta != tb) return ta < tb;
    return a % b > 0;
}

#define MAX   5050
int numPoint;
Point points[MAX];

void init(void) {
    scanf("%d", &numPoint);
    FOR(i, 1, numPoint) scanf("%d%d", &points[i].x, &points[i].y);
}

long long chooseCenter(int index) {
//    printf("INDEX = %d\n", index);

    vector<Point> dirs;
    FOR(i, 1, numPoint) if (i != index) dirs.push_back(points[i] - points[index]);
    sort(ALL(dirs), CompareCCW);

//    FORE(it, dirs) printf("(%d, %d) ", it->x, it->y); printf("\n");

    long long res = 0;

    int j = 0, cnt = 1;
    REP(i, dirs.size()) {
        while (true) {
            int k = (j + 1) % dirs.size();
//            cerr << i << " " << k << " " << dirs[i] % dirs[k] << endl;
            if (dirs[i] % dirs[k] <= 0) break;
            cnt++; j = k;
        }

//        printf("with %d is %d (%d)\n", i, j, cnt);

        if (cnt >= 4) res += 1LL * (cnt - 1) * (cnt - 2) * (cnt - 3) / 6;
        if (i == j) {
            j = i + 1; cnt = 1;
        } else cnt--;
    }

    return 1LL * (numPoint - 1) * (numPoint - 2) * (numPoint - 3) * (numPoint - 4) / 24 - res;
}

void process(void) {
    long long res = 0;
    FOR(i, 1, numPoint) res += chooseCenter(i);
    cout << res << endl;
}

int main(void) {
//    freopen("tmp.txt", "r", stdin);

    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/