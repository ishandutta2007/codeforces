// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define error(args...) 
#endif

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
const int MAX_L = 13;
const int STATE = 5;
int main(){
    iostream_init();
    int n, q;
    char target[5] = {'2', '0', '1', '6', '6'};
    char change[5] = {'2', '0', '1', '7', '@'};
    while(cin >> n >> q) {
        string s;
        cin >> s;
        static short dp[MAX_N][STATE][STATE][MAX_L] = {};
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                dp[i][j][j][0] = (s[i] == target[j] ? 1 : 0);
                if(s[i] == change[j]) {
                    dp[i][j][j+1][0] = 0;
                }
            }
        }
        // REP(i, n) REP(j, 5) REP(k, 5) {
        //     if(dp[i][j][k][0] < 0x3f3f3f3f) {
        //         error(i, j, k, dp[i][j][k][0]);
        //     }
        // }
        for(int l = 1; l < MAX_L; l++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < 5; j++) {
                    for(int k = j; k < 5; k++) {
                        for(int m = j; m <= k; m++) {
                            int ni = i + (1 << (l-1));
                            if(ni < n) {
                                dp[i][j][k][l] = min<int>(dp[i][j][k][l], dp[i][j][m][l-1] + dp[ni][m][k][l-1]);
                            } else if(m == k) {
                                dp[i][j][k][l] = min<int>(dp[i][j][k][l], dp[i][j][m][l-1] + 0);
                            } else {
                                // dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][m][l-1] + INF);
                            }
                        }
                    }
                }
            }
        }
        // error(dp[0][0][4][3]);
        while(q--) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            b++;
            int len = b - a;
            int opt[5] = {};
            memset(opt, 0x3f, sizeof(opt));
            opt[0] = 0;

            int from = a;
            auto get_next = [&](int L) {
                int nopt[5] = {};
                memset(nopt, 0x3f, sizeof(nopt));
                for(int i = 0; i < 5; i++) {
                    for(int j = i; j < 5; j++) {
                        if(dp[from][i][j][L] < 0x3f3f) {
                            nopt[j] = min(nopt[j], opt[i] + dp[from][i][j][L]);
                        }
                    }
                }
                memcpy(opt, nopt, sizeof(nopt));
                from = from + (1 << L);
            };
            const int MAX_LEN = (1 << (MAX_L-1));
            REP(_, len / MAX_LEN) {
                get_next(MAX_L-1);
            }
            int rest = len % MAX_LEN;
            for(int l = MAX_L-1; l >= 0; l--) {
                if(rest >> l & 1) {
                    get_next(l);
                }
            }
            // assert(from == b);
            int ans = opt[4];
            if(ans == 0x3f3f3f3f) {
                cout << "-1" << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
    return 0;
}