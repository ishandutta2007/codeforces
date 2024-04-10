#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
void add(int&x, long long y, int mod) {
    x = ((long long)x + y) % mod;
}
int solve(int n, int m, int mod) {
    int cnt[505] = {};
    REP(i, m) {
        string s;
        cin >> s;
        vector<int> v;
        REP(j, n) if(s[j] == '1') {
            v.push_back(j);
        }
        if(v.size() != 2) {
            return 0;
        }
        for(int j : v) cnt[j]++;
    }
    REP(i, n) if(cnt[i] > 2) return 0;

    int i_zero = 0, i_one = 0, i_two = 0;
    REP(i, n) if(cnt[i] == 0) i_zero++;
    REP(i, n) if(cnt[i] == 1) i_one++;
    REP(i, n) if(cnt[i] == 2) i_two++;

    int dp[505] = {};
    dp[i_one] = 1;

    for(int i = m; i < n; i++) {
        int next[505] = {};

        for(int one = 0; one <= 2*i; one++) {
            int rest = 2*i - one;
            if(rest % 2 != 0) continue;
            int two = rest / 2;
            if(!dp[one]) continue;
            int zero = n - one - two;
            if(zero >= 2){
                add(next[one+2], (long long)zero * (zero - 1) / 2 * dp[one], mod);
            }
            if(zero >= 1 && one >= 1) {
                add(next[one], (long long)zero * one * dp[one], mod);
            }
            if(one >= 2) {
                add(next[one-2], (long long)one * (one - 1) / 2 * dp[one], mod);
            }
        }

        memcpy(dp, next, sizeof(dp));
    }

    return dp[0];
}

int main(){
    int n, m, mod;
    while(cin >> n >> m >> mod) {
        cout << solve(n, m, mod) << endl;
    }
    return 0;
}