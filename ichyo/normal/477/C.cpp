#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

const int INF = 1000000000;
void update(int& x, int y) {
    if(x < y) x = y;
}

vector<int> solve(string s, string p) {
    int n = s.size();
    int cost[2005] = {};
    int to[2005] = {};
    REP(i, s.size()) {
        cost[i] = -INF;
    }
    for(int i = 0; i < s.size(); i++) if(s[i] == p[0]) {
        int j = i;
        int k = 0;
        for(;j < s.size() && k < p.size(); j++) {
            if(s[j] == p[k]) {
                k++;
            }
        }
        if(k == p.size()) {
            cost[i] = (j - i) - p.size();
            to[i] = j;
        } else {
        }
    }
    // REP(i, n) cout << cost[i] << " "; cout << endl;
    // REP(i, n) cout << to[i] << " "; cout << endl;
    static int dp[2005][2005] = {}; // i, j
    REP(i, n + 1) REP(j, n + 1) dp[i][j] = -INF;
    dp[0][0] = 0;
    REP(i, n) {
        if(cost[i] >= 0) {
            REP(j, n + 1) if(dp[i][j] > -INF) {
                assert(j + cost[i] <= n);
                update(dp[to[i]][j + cost[i]], dp[i][j] + 1);
            }
        }
        REP(j, n + 1) if(dp[i][j] > -INF) {
            //assert(j <= i);
            update(dp[i + 1][j], dp[i][j]);
            update(dp[i + 1][j + 1], dp[i][j]);
        }
    }

    vector<int> res;
    REP(i, n + 1) {
        res.push_back(dp[n][i]);
    }
    return res;
}

/*
vector<int> slow(string s, string p) {
    int n = s.size();
    int m = p.size();
    static int dp[200][200][50] = {};
    REP(i, n + 1) REP(j, n + 1) REP(k, m + 1) dp[i][j][k] = INT_MIN;
}
*/

int main(){
    string s, p;
    while(cin >> s >> p){
        vector<int> res = solve(s, p);
        REP(i, res.size()) {
            cout << res[i];
            if(i + 1 == res.size()) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}