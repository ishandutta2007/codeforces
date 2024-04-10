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

LL solve(LL C, LL H1, LL W1, LL H2, LL W2) {
    LL use1s = C / W1;
    LL res = 0;
    REP(t, 1000000) {
        LL use1 = use1s - t;
        if(use1 < 0) break;
        LL CR = C - use1 * W1;
        LL use2 = CR / W2;
        LL sum = use1 * H1 + use2 * H2;
        res = max(res, sum);
    }
    return res;
}
int main(){
    iostream_init();
    LL C;
    while(cin >> C) {
        LL H[2], W[2];
        REP(i, 2) cin >> H[i];
        REP(i, 2) cin >> W[i];
        LL res = 0;
        res = max(res, solve(C, H[0], W[0], H[1], W[1]));
        res = max(res, solve(C, H[1], W[1], H[0], W[0]));
        cout << res << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */