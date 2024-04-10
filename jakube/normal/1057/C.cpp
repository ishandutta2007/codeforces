#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, k;
    cin >> n >> s >> k;
    s--;
    vector<int> r(n);
    for (auto& x : r)
        cin >> x;
    string c;
    cin >> c;

    int INF = std::numeric_limits<int>::max() / 2;
    int best = INF;
    // dp[pos][sum]
    vector<vector<int>> dp(n, vector<int>(k, INF));
    for (int i = 0; i < n; i++) {
        int s2 = abs(i - s);
        if (r[i] >= k)
            best = min(best, s2);
        else
            dp[i][r[i]] = s2;
    }

    for (int R = 1; R <= 50; R++) {
        for (int i = 0; i < n; i++) {
            if (r[i] != R)
                continue;

            for (int sum = 0; sum < k; sum++) {
                for (int j = 0; j < n; j++) {
                    if (r[j] > r[i] && c[i] != c[j]) {
                        int s2 = sum + r[j];
                        int c2 = dp[i][sum] + abs(j - i);
                        if (s2 >= k)
                            best = min(best, c2);
                        else
                            dp[j][s2] = min(dp[j][s2], c2);
                    }
                }
            }
        }
    }
    if (best < INF)
        cout << best << '\n';
    else
        cout << -1 << '\n';
}