#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> primes;
    for (int i = 2; i < 60; i++) {
        bool b = true;
        for (int d = 2; d*d <= i; d++) {
            b &= (i % d) > 0;
        }
        if (b) {
            primes.push_back(i);
        }
    }

    vector<int> bitmasks(61);
    for (int i = 1; i < 61; i++) {
        int num = i;
        int bitmask = 0;
        int div = 2;
        while (num > 1) {
            while (num % div == 0) {
                num /= div;
                bitmask |= 1 << (find(primes.begin(), primes.end(), div) - primes.begin());
            }
            div++;
        }
        bitmasks[i] = bitmask;
    }

    
    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(1 << 17, {numeric_limits<int>::max() / 2, 0}));
    dp[0][0] = {0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << 16); j++) {
            for (int poss = 1; poss <= 58; poss++) {
                if ((j & bitmasks[poss]) == 0) {
                    int new_bit = j | bitmasks[poss];
                    int new_val = dp[i][j].first + abs(a[i] - poss);
                    if (dp[i+1][new_bit].first > new_val) {
                        dp[i+1][new_bit] = {new_val, poss};
                    }
                }
            }
        }
    }

    int bitmask = 0;
    for (int i = 0; i < (1 << 17); i++) {
        if (dp[n][i].first < dp[n][bitmask].first) {
            bitmask = i;
        }
    }

    vector<int> result;
    for (int k = n-1; k >= 0; k--) {
        result.push_back(dp[k+1][bitmask].second);
        bitmask ^= bitmasks[dp[k+1][bitmask].second];
    }

    reverse(result.begin(), result.end());
    for (int i : result) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}