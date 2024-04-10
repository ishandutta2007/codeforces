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
const int MAX_N = 4000;
const int INF = 1e9;
int slow(int N, int K, int cost[MAX_N][MAX_N]) {
    int dp[K+1][MAX_N+1] = {};
    REP(i, K+1) REP(j, MAX_N+1) dp[i][j] = INF;
    dp[0][0] = 0;
    for(int k = 1; k <= K; k++) for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            dp[k][i] = min(dp[k][i], dp[k-1][j] + cost[j][i-1]);
        }
    }
    return dp[K][N];
}
int dp[MAX_N+1][MAX_N+1];
void rec(int d, int L, int R, int optL, int optR, int cost[MAX_N][MAX_N]) {
    if(d == 0) {
        fill(dp[0], dp[0] + MAX_N+1, INF);
        dp[0][0] = 0;
        return;
    }
    if(L >= R) { return; }
    int m = (L + R) / 2;
    int opt = -1;
    dp[d][m] = INT_MAX;
    for(int k = optL; k < optR && k < m; k++) {
        if(dp[d][m] > dp[d-1][k] + cost[k][m-1]) {
            dp[d][m] = dp[d-1][k] + cost[k][m-1];
            opt = k;
        }
    }
    assert(opt != -1);
    rec(d, L, m, optL, opt+1, cost);
    rec(d, m+1, R, opt, optR, cost);
}
int main(){
    static int cost[MAX_N][MAX_N] = {}; // [l, r]
    int n, k;
    cin >> n >> k;
    cin.ignore();
    static int mat[MAX_N][MAX_N] = {};
    static int mat_s[MAX_N][MAX_N + 1] = {};
    REP(i, n){
        char buf[MAX_N * 2 + 2];
        fgets(buf, MAX_N * 2 + 2, stdin);
        REP(j, n){
            mat[i][j] = buf[j * 2] - '0';
            assert(mat[i][j] >= 0 && mat[i][j] <= 9);
        }
    }
    REP(i, n) {
        REP(j, n) mat_s[i][j+1] = mat_s[i][j] + mat[i][j];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            cost[i][j] = cost[i][j-1] + mat_s[j][j] - mat_s[j][i];
        }
    }

    //cout << slow(n, k, cost) << endl;
    REP(i, k+1) rec(i, 1, n+1, 0, n+1, cost);
    cout << dp[k][n] << endl;

    return 0;
}

/* vim:set foldmethod=marker: */