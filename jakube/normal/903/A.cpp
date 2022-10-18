#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> dp(101, false);
    dp[0] = true;

    for (int i = 1; i < 101; i++) {
        if ((i >= 3 && dp[i - 3]) || (i >= 7 && dp[i - 7]))
            dp[i] = true;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (dp[x])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
}