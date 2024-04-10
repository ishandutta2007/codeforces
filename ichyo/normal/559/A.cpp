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
    int a[6];
    REP(i, 6) cin >> a[i];
    int H = a[1] + a[2];
    //assert(H == a[4] + a[5]);
    int w = 2 * a[0] - 1;
    int ans = 0;
    REP(i, H) {
        if(a[1] > 0) {
            a[1]--;
            w++;
        } else {
            w--;
            ans ++;
        }
        if(a[5] > 0) {
            a[5]--;
            w++;
        } else {
            w--;
            ans ++;
        }
        ans += w;
    }
    cout << ans << endl;
    return 0;
}

/* vim:set foldmethod=marker: */