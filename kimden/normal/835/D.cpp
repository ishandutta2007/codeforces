#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
//    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> ans(100, 0);
    for(int j = 0; j < n; ++j){
        dp[j][j] = 1;
        ++ans[0];
    }
    for(int j = 0; j < n - 1; ++j){
        dp[j][j + 1] = (s[j] == s[j + 1] ? 2 : 0);
        if(dp[j][j + 1] > 0) {
            ++ans[dp[j][j + 1] - 1];
        }
    }
    for(int i = 2; i < n; ++i){
        for(int j = 0; j < n - i; ++j){
            if(s[j] == s[j + i] && dp[j + 1][j + i - 1] != 0){
                dp[j][j + i] = dp[j][j + ((i - 1) / 2)] + 1;
                ++ans[dp[j][j + i] - 1];
            }
        }
    }
    for(int i = 98; i >= 0; --i){
        ans[i] += ans[i + 1];
    }
    for(int i = 0; i < min(n, 13); ++i){
        if(i){
            cout << " ";
        }
        cout << ans[i];
    }
    for(int i = 13; i < n; ++i){
        cout << " 0";
    }
    cout << endl;
    return 0;
}