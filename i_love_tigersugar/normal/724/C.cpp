#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   200200

struct Point {
    int x, y;
    Point() {
        x = y = 0;
    }
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
    Point operator + (const Point &a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator * (int k) const {
        return (Point(x * k, y * k));
    }
};

#define RIGHT   1
#define LEFT   -1
#define UP   1
#define DOWN    -1

map<int, set<int> > pointAdd, pointSub;
Point points[MAX];
long long answer[MAX];
int n, limX, limY;

void init(void) {
    scanf("%d%d%d", &limX, &limY, &n);
    FOR(i, 1, n) scanf("%d%d", &points[i].x, &points[i].y);
    FOR(i, 1, n) {
        pointAdd[points[i].x + points[i].y].insert(i);
        pointSub[points[i].x - points[i].y].insert(i);
    }
    FOR(i, 1, n) answer[i] = -1;
}

void removePoint(Point pos, Point dir, long long curTime) {
    set<int> &pass = dir.x * dir.y < 0 ? pointAdd[pos.x + pos.y] : pointSub[pos.x - pos.y];
    while (!pass.empty()) {
        int id = *pass.begin();
        answer[id] = curTime + (points[id].x - pos.x) / dir.x;
        pointAdd[points[id].x + points[id].y].erase(id);
        pointSub[points[id].x - points[id].y].erase(id);
    }
}

bool inside(Point p) {
    return 0 <= p.x && p.x <= limX && 0 <= p.y && p.y <= limY;
}
Point getNextPos(Point pos, Point dir) {
    int L = 0;
    int R = MAX;
    while (true) {
        if (L == R) return (pos + dir * R);
        if (R - L == 1) return (inside(pos + dir * R) ? pos + dir * R : pos + dir * L);
        int M = (L + R) >> 1;
        if (inside(pos + dir * M)) L = M; else R = M - 1;
    }
}

bool isCorner(Point p) {
    if (0 < p.x && p.x < limX) return false;
    if (0 < p.y && p.y < limY) return false;
    return true;
}
Point getNextDir(Point dir, Point nextPos) {
    if (nextPos.x == 0 || nextPos.x == limX) return Point(-dir.x, dir.y);
    if (nextPos.y == 0 || nextPos.y == limY) return Point(dir.x, -dir.y);
    assert(false);
}

void process(void) {
    Point pos(0, 0);
    Point dir(RIGHT, UP);
    long long curTime = 0;
    while (true) {
        removePoint(pos, dir, curTime);

        Point nextPos = getNextPos(pos, dir);
        if (isCorner(nextPos)) break;
        Point nextDir = getNextDir(dir, nextPos);
        long long nextTime = curTime + (nextPos.x - pos.x) / dir.x;

        pos = nextPos;
        dir = nextDir;
        curTime = nextTime;
    }
    FOR(i, 1, n) cout << answer[i] << "\n";
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/