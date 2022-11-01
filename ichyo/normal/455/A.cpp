#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n;
    while(cin >> n) {
        const int MAX = 100010;
        vector<int> cnt(MAX);
        REP(i, n) {
            int x;
            cin >> x;
            cnt[x] ++;
        }
        long long dp[2] = {};
        REP(i, MAX) {
            long long next[2];
            next[0] = max(dp[0], dp[1]);
            next[1] = dp[0] + (long long)cnt[i] * i;
            REP(j, 2) dp[j] = next[j];
        }
        cout << max(dp[0], dp[1]) << endl;
    }
    return 0;
}