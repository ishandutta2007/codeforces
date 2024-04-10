#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    sort(a.begin(), a.end());
    a.resize(k);
    n = k;

    vector<unsigned int> psum(a.size() + 1, 0u);
    for (auto psum_idx = 0u; psum_idx < a.size(); psum_idx++) {
        psum[psum_idx+1] = psum[psum_idx] + a[psum_idx];
    }
    auto sum = [&psum](int x, int y) {
        return (unsigned)(psum[y+1] - psum[x]);
    };

    vector<pair<unsigned int, unsigned int>> qs(m);
    unsigned int INF = std::numeric_limits<unsigned int>::max();
    vector<unsigned int> smallest(2001, INF);
    for (auto& x : qs) {
        cin >> x.first >> x.second; 
        if (x.first <= 2000)
            smallest[x.second] = min(smallest[x.second], x.first);
    }
    
    vector<unsigned int> dp(n+1, INF);
    dp[0] = 0;
    for (int len = 1; len <= n; len++) {
        int j = len;
        auto& x = dp[j];
        x = min(x, sum(0, j-1));
        for (int k = 1; k <= len; k++) {
            unsigned int le = smallest[k];
            if (len >= le) {
                x = min(x, sum(j-(le-k), j-1) + dp[j-le]);
            }
        }
    }
    cout << dp[n] << '\n';
}