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
    int n;
    while(cin >> n) {
        string S, T;
        cin >> S >> T;
        int dp[100010][16] = {};
        dp[0][1] = 1;
        REP(i, n+1) REP(s, 1<<4) if(s > 0 && dp[i][s]) {
            dump(i);
            dump(s);
            dump(dp[i][s]);
            // if(!(s & 1)) {
            //     dp[i+1][s|1] += dp[i][s];
            // }
            // if(!(s & 2)) {
            //     dp[i+1][s|2] += dp[i][s];
            // }
            // int x = i - (s      & 1);
            // int y = i - (s >> 1 & 1);
            // if(x < n && y < n && S[x] == T[y]) {
            //     dp[i+1][s] += dp[i][s];
            // }
            REP(c, 26){
                int ns = 0;
                REP(dx, 2) REP(dy, 2) {
                    int k = dx + 2*dy;
                    if(!(s >> k & 1)) continue;
                    // if(c == 0) { dump(dx); dump(dy); }
                    int x = i - dx;
                    int y = i - dy;
                    if(dx == 0 && y < n && T[y] == c + 'a') {
                        int ndx = 1;
                        int ndy = dy;
                        int nk = ndx + 2*ndy;
                        ns |= 1 << nk;
                    }
                    if(dy == 0 && x < n && S[x] == c + 'a') {
                        int ndx = dx;
                        int ndy = 1;
                        int nk = ndx + 2*ndy;
                        ns |= 1 << nk;
                    }
                    if(x < n && y < n && S[x] == T[y] && S[x] == c + 'a') {
                        int nk = k;
                        ns |= 1 << nk;
                    }
                }
                assert(ns < 16);
                dp[i+1][ns] += dp[i][s];
            }
        }
        int ans = 0;
        REP(s, 1<<4) if(s > 0) ans += dp[n+1][s];
        cout << ans << endl;
    }

    return 0;
}

/* vim:set foldmethod=marker: */