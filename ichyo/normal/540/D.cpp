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

double memo[110][110][110][3];
double rec(int r, int s, int p, int mode) {
    double& res = memo[r][s][p][mode];
    if(!isnan(res)) return res;
    int life = 0;
    if(r) life++;
    if(s) life++;
    if(p) life++;
    assert(life > 0);
    if(life == 1) {
        if(mode == 0 && r) return res = 1.0;
        if(mode == 1 && s) return res = 1.0;
        if(mode == 2 && p) return res = 1.0;
        return res = 0.0;
    }
    res = 0;
    double probA = (2.0 * r * s);
    double probB = (2.0 * s * p);
    double probC = (2.0 * p * r);
    double probS = probA + probB + probC;
    if(probA > 0) {
        res += rec(r, s-1, p, mode) * probA/probS;
    }
    if(probB > 0) {
        res += rec(r, s, p-1, mode) * probB/probS;
    }
    if(probC > 0) {
        res += rec(r-1, s, p, mode) * probC/probS;
    }
    return res;
}
int main(){
    iostream_init();
    memset(memo, -1, sizeof(memo));
    int r, s, p;
    while(cin >> r >> s >> p) {
        cout << rec(r, s, p, 0) << " " << rec(r, s, p, 1) << " " << rec(r, s, p, 2) << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */