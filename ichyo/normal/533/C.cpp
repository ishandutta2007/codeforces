// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

bool solve(int x1, int y1, int x2, int y2) {
    // int mt1 = x1 + y1;
    // int mt2 = max(x2, y2);
    // if(mt1 <= mt2) return true;
    while(true) {
        auto move1 = [&](int dx, int dy) {
            if(x1 - dx == x2 && y1 - dy == y2) return false;
            if(x1 - dx < 0 || y1 - dy < 0) return false;
            x1 -= dx;
            y1 -= dy;
            return true;
        };
        if(x1 == 0 && move1(0, 1)) {
        } else if(y1 == 0 && move1(1, 0)) {
        } else if(x1 - x2 >= y1 - y2 && move1(1, 0)) {
        } else if(move1(0, 1)) {
        }
        if(x1 == 0 && y1 == 0) return true;
        auto move2 = [&](int dx, int dy) {
            if(x2 - dx == x1 && y2 - dy == y1) return false;
            if(x2 - dx < 0 || y2 - dy < 0) return false;
            x2 -= dx;
            y2 -= dy;
            return true;
        };
        if(move2(1, 1)) {
        } else if(move2(1, 0)) {
        } else if(move2(0, 1)) {
        }
        if(x2 == 0 && y2 == 0) return false;
    }
    return false;
}
int main(){
    iostream_init();
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool ans = solve(x1, y1, x2, y2);
    cout << (ans ? "Polycarp" : "Vasiliy") << endl;
    return 0;
}

/* vim:set foldmethod=marker: */