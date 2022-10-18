#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(n + 1, 0);
    for (int x = 1; x <= n; x++) {
        dp[x] = dp[v[x-1]];
        // how many between v[x-1] and x
        int l_seen = v[x-1] ? min(v[x-1] + k, n) : 0;
        int l_poss = min(n, x + k);
        int s_poss = max(1, x - k);
        int s = max(l_seen + 1, s_poss);
        dp[x] += l_poss - s + 1;
        cout << dp[x] << " ";
    }
    cout << endl;
    
}