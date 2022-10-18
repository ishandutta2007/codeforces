#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    vector<int> d(N-1);
    for (int i = 0; i < N-1; i++) {
        d[i] = t[i+1] - t[i];
    }

    if (3 * K < N - 1) {
        auto x = d;
        sort(x.begin(), x.end());
        int val = x[3 * K - 1];
        vector<int> D;
        bool last = true;
        for (int y : d) {
            if (y <= val) {
                D.push_back(y);
                last = false;
            } else if (!last) {
                D.push_back(std::numeric_limits<int>::max());
                last = true;
            }
        }

        d.swap(D);
    }

    N = (int)d.size();
    vector<vector<long long>> dp(K+1, vector<long long>(2, std::numeric_limits<int>::max()));
    dp[0][0] = 0;
    vector<vector<long long>> dp2(K+1, vector<long long>(2, std::numeric_limits<int>::max()));
    
    for (int i = 0; i < N; i++) {
        dp2[0][0] = 0;
        dp2[0][1] = std::numeric_limits<int>::max();
        for (int k = 0; k < K; k++) {
            dp2[k+1][0] = min(dp[k+1][0], dp[k+1][1]);
            dp2[k+1][1] = dp[k][0] + d[i];
        }
        dp.swap(dp2);
    }

    cout << min(dp[K][0], dp[K][1]) << '\n';
}