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

const int MAX_N = 200002;
vector<int> childs[MAX_N];
LL cost[MAX_N];
LL dp[MAX_N][2] = {};
void update(LL& x, LL y) {
    if(x < y) x = y;
}
LL INF = 1000000000000000000LL;

void calc(int u) {
    dump(u);
    for(int c : childs[u]) {
        calc(c);
    }

    LL ldp[2] = {};
    ldp[0] = 0;
    ldp[1] = -INF;
    for(int c : childs[u]) {
        LL lndp[2] = {};
        lndp[0] = lndp[1] = -INF;

        update(lndp[0], ldp[0] + dp[c][0]);
        update(lndp[1], ldp[0] + dp[c][1]);
        update(lndp[0], ldp[1] + dp[c][1]);
        update(lndp[1], ldp[1] + dp[c][0]);

        ldp[0] = lndp[0];
        ldp[1] = lndp[1];
    }

    dp[u][0] = ldp[0];
    dp[u][1] = max(ldp[1], ldp[0] + cost[u]);
    dump(u);
    dump(dp[u][0]);
    dump(dp[u][1]);
}

int main(){
    iostream_init();
    int n;
    while(cin >> n) {
#ifdef LOCAL
        REP(i, MAX_N) childs[i].clear();
#endif

        REP(i, n) {
            int p;
            cin >> p >> cost[i];
            if(p != -1) {
                p--;
                childs[p].push_back(i);
            }
        }

        calc(0);

        cout << max(dp[0][0], dp[0][1]) << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */