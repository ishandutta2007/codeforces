#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> dp;
vector<int> factor;

int f(int r, int n) {
    long long result = 1;

    while (n != 1) {
        int f = factor[n];
        int cnt = 0;
        while (factor[n] == f) {
            cnt++;
            n /= f;
        }
        result = (result * dp[r][cnt]) % MOD; 
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    dp.assign(1e6+1, vector<long long>(21, 0));
    dp[0].assign(21, 2);
    dp[0][0] = 1;
    for (int r = 1; r < dp.size(); r++) {
        dp[r][0] = 1;
        for (int exp = 1; exp < 21; exp++) {
            dp[r][exp] = (dp[r][exp-1] + dp[r-1][exp]) % MOD;
        }
    }

    factor.resize(1e6+3);
    iota(factor.begin(), factor.end(), 0);
    for (int i = 2; i*i < factor.size(); i++) {
        if (factor[i] == i) {
            for (int j = i; j < factor.size(); j += i) {
                factor[j] = min(factor[j], i);
            }
        }
    }

    int q;
    cin >> q;
    for (int Q = 0; Q < q; Q++) {
        int r, n;
        cin >> r >> n;
        cout << f(r, n) << '\n';
    }

    return 0;
}