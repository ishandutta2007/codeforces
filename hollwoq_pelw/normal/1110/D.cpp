#include <bits/stdc++.h>

using namespace std;

int main() {
    int cc, n;
    cin >> cc >> n;
    vector<int> a(n);
    for (int i = 0; i < cc; i++) {
        int x;
        cin >> x;
        x--;
        a[x]++;
    }
    vector<vector<int>> dp(3, vector<int>(3, 0));
    for (int c : a) {
        vector<vector<int>> new_dp(3, vector<int>(3, 0));
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    if (x + y + z <= c) {
                        new_dp[y][z] = max(new_dp[y][z], dp[x][y] + z + (c - x - y - z) / 3);
                    }
                }
            }
        }
        swap(dp, new_dp);
    }
    cout << dp[0][0] << '\n';
    return 0;
}