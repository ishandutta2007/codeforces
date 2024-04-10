#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

const int INF = 1000000000;

int main(){
    int h, w;
    while(cin >> h >> w){
        vector<string> grid(h);
        REP(y, h) cin >> grid[y];
        int dp[555][26 * 26] = {};
        int back[555][26 * 26] = {};
        REP(y, h) fill(dp[y + 1], dp[y + 1] + 26 * 26, INF);

        REP(y, h) {
            
            int odd[26] = {};
            int even[26] = {};

            REP(x, w) {
                if(x % 2 == 0) even[grid[y][x] - 'a']++;
                if(x % 2 == 1)  odd[grid[y][x] - 'a']++;
            }

            REP(pc1, 26) REP(pc2, 26) if(pc1 != pc2) {
                int p = pc2 * 26 + pc1;
                REP(c1, 26) if(c1 != pc1) REP(c2, 26) if(c2 != c1 && c2 != pc2) {
                    int q = c2 * 26 + c1;
                    int next = dp[y][p] + w - even[c1] - odd[c2];
                    if(dp[y + 1][q] > next) {
                        dp[y + 1][q] = next;
                        back[y + 1][q] = p;
                    }
                }
            }

        }

        int pair = 0;
        REP(p, 26 * 26) {
            if(dp[h][pair] > dp[h][p]) {
                pair = p;
            }
        }

        cout << dp[h][pair] << endl;
        vector<string> ans(h);

        for(int y = h - 1; y >= 0; y--) {
            int c1 = pair % 26;
            int c2 = pair / 26;
            REP(x, w) {
                ans[y] += (char)(x % 2 == 0 ? c1 : c2) + 'a';
            }
            pair = back[y + 1][pair];
        }

        REP(y, h) {
            cout << ans[y] << endl;
        }

    }
    return 0;
}