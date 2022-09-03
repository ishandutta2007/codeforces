#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N, H, L, R;
    cin >> N >> H >> L >> R;
    vector<int> A(N);
    for (auto &x : A) cin >> x;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1e9));
    dp[0][0] = 0;
    int acc = 0;
    for (int d = 0; d < N; d++) {
        (acc += A[d]) %= H;
        for (int s = 0; s <= d; s++)
        {
            int T = (acc - s % H + H) % H;
            dp[d + 1][s] = max(dp[d + 1][s], dp[d][s] + (T >= L and T <= R));
            T = (T - 1 + H) % H;
            dp[d + 1][s + 1] = max(dp[d + 1][s + 1], dp[d][s] + (T >= L and T <= R));
        }
    }
    cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
}