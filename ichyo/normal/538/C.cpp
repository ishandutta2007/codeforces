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

int main(){
    iostream_init();
    int n, m;
    cin >> n >> m;
    int d1 = 1;
    int h1 = 0;
    int ans = 0;
    bool impossible = false;
    REP(i, m) {
        int d2, h2;
        cin >> d2 >> h2;
        int D = d2 - d1;
        int H = abs(h2 - h1);
        if(i == 0) {
            ans = max(ans, h2 + D);
            d1 = d2;
            h1 = h2;
            continue;
        }
        if(H > D) {
            impossible = true;
        } else {
            int R = D - H;
            ans = max(ans, max(h1, h2) + R / 2);
        }
        d1 = d2;
        h1 = h2;
    }
    int D = n - d1;
    ans = max(ans, h1 + D);
    if(impossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */