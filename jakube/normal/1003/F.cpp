#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto w = v;
    sort(w.begin(), w.end());
    auto end = unique(w.begin(), w.end());
    vector<int> V(n, 0);
    for (int i = 0; i < n; i++)
        V[i] = lower_bound(w.begin(), end, v[i]) - w.begin();   

    vector<int> size(n, 0);
    for (int i = 0; i < n; i++)
        size[i] = v[i].size();
    vector<int> psum(size.size() + 1, 0);
    for (auto psum_idx = 0u; psum_idx < size.size(); psum_idx++)
        psum[psum_idx+1] = psum[psum_idx] + size[psum_idx];
    auto sum = [&psum](int x, int y) { return psum[y+1] - psum[x]; };

    int total = sum(0, n-1) + n - 1;
    int best = total;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            for (int k = 0; j + k < n && i + k < j && V[i+k] == V[j+k]; k++) {
                dp[j][j+k] = max(dp[j][j+k], dp[i][i+k] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dp[i][j])
                best = min(best, total + (dp[i][j] + 1) * (-sum(i, j) + -(j - i) + (j - i + 1)));
        }
    }

    cout << best << '\n';
}