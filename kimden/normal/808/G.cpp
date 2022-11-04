#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s;
    cin >> t;
    string r = t + '#' + s;
    vector<int> p(t.size() + 1, 0);
    vector<vector<int>> next(t.size() + 1, vector<int>(26, 0));
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
//    vector<vector<pair<int, char>>> ans(s.size() + 1, vector<pair<int, char>>(t.size()));
    for(int i = 1; i < t.length() + 1; ++i){
        int cur = p[i - 1];
        while(cur > 0 && t[i] != t[cur]){
            cur = p[cur - 1];
        }
        p[i] = cur + 1;
        if(cur == 0){
            if(t[i] == t[0]){
                p[i] = 1;
            }else{
                p[i] = 0;
            }
        }
    }
    for(int j = 0; j < 26; ++j){
        char c = 'a' + j;
        next[0][j] = (c == t[0] ? 1 : 0);
    }
    for(int i = 1; i <= t.length(); ++i){
        for(int j = 0; j < 26; ++j){
            char c = 'a' + j;
            if(c == t[i]){
                next[i][j] = i + 1;
            }else{
                next[i][j] = next[p[i - 1]][j];
            }
        }
    }
    dp[0][p[t.length()]] = 0;
    for(int i = 1; i <= s.length(); ++i){
        if(s[i - 1] == '?'){
            for(int j = 0; j < t.size() + 1; ++j){
                if(dp[i - 1][j] == -1){
                    continue;
                }
                for(int u = 0; u < 26; ++u) {
                    int x = dp[i - 1][j] + (next[j][u] >= t.length() ? 1 : 0);
                    if(dp[i][next[j][u]] < x){
                        dp[i][next[j][u]] = x;
//                        cout << "[" << i << "][" << next[j][u] << "] := " << x << endl;
//                        ans[i][next[j][u]] = {j, u + 'a'};
                    }
                }
            }
        }else{
            for(int j = 0; j < t.size() + 1; ++j){
                if(dp[i - 1][j] == -1){
                    continue;
                }
                char c = s[i - 1];
                int x = dp[i - 1][j] + (next[j][c - 'a'] >= t.length() ? 1 : 0);
                if(dp[i][next[j][c - 'a']] < x){
                    dp[i][next[j][c - 'a']] = x;
//                    cout << "[" << i << "][" << next[j][c - 'a'] << "] := " << x << endl;
//                    ans[i][next[j][c - 'a']] = {j, c};
                }
            }
        }
    }
//    int bestPF = -1;
    int bestAns = -1;
    for(int i = 0; i < t.size() + 1; ++i){
        bestAns = max(bestAns, dp[s.length()][i]);
//        if(dp[s.length()][i] > bestAns){
//            bestAns = dp[s.length()][i];
//            bestPF = i;
//        }
    }
//    for(int i = (int)s.length(); i >= 1; --i){
//        if(s[i - 1] == '?'){
//            s[i - 1] = ans[i][bestPF].second;
//            bestPF = ans[i][bestPF].first;
//        }
//    }
//    cout << s << endl;
    cout << bestAns << endl;
}