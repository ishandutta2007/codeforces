#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    vector<int> dp(s.size()+1, 0);
    for (int i = 0; i < s.size()-1; ++i) {
        dp[i+1] = dp[i] + (s[i] == s[i+1]);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        cout << dp[r-1]-dp[l-1] << "\n";
    }
    

    

    return 0;
}