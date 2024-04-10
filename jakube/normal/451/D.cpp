#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(2, vector<int>(2, 0));
    // dp[start with a/b][odd/even]
    
    long long cnt_odd = 0, cnt_even = 0;
    dp[s[0] == 'a' ? 0 : 1] = {1, 0};
    cnt_odd++;
    
    for (int i = 1; i < n; i++) {
        int idx = s[i] == 'a' ? 0 : 1;
        dp[idx][i & 1]++;

        cnt_odd += dp[idx][i & 1];
        cnt_even += dp[idx][1 - (i & 1)];
    }

    cout << cnt_even << " " << cnt_odd << endl;

    return 0;
}