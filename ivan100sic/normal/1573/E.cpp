// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        a.erase(unique(begin(a), end(a)), a.end());
        n = a.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        auto read_dp = [&](int l, int r) {
            if (l > r) return 0;
            return dp[l][r];
        };

        for (int l=n-1; l>=0; l--) {
            vector<int> isti = {l}, subdp = {0};
            dp[l][l] = 0;
            for (int r=l+1; r<n; r++) {
                if (a[r] == a[l]) {
                    int z = 0;
                    for (int j=0; j<(int)isti.size(); j++) {
                        int p = isti[j];
                        z = max(z, subdp[j] + 1 + read_dp(p+1, r-1));
                    }
                    isti.push_back(r);
                    subdp.push_back(z);
                }

                {
                    int z = 0;
                    for (int j=0; j<(int)isti.size(); j++) {
                        int p = isti[j];
                        z = max(z, subdp[j] + read_dp(p+1, r));
                    }
                    dp[l][r] = z;
                }
            }
        }

        cout << n-1-dp[0][n-1] << '\n';
    }
}