#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector< vector<int> > prev(k + 1, vector<int>(n + 1));
    vector< vector<int> > next(k + 1, vector<int>(n + 1));
    prev[0][0] = prev[0][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= k; sum++) {
            for (int j = 0; j <= n; j++) {
                prev[sum][j] %= MOD;
            }
            for (int j = 0; j <= n; j++) {
                if (prev[sum][j] == 0) continue;
                int nsum = sum + j * (a[i] - a[i - 1]);
                if (nsum > k) continue;
                if (j != n) next[nsum][j + 1] += prev[sum][j];
                next[nsum][j] += prev[sum][j] * (j + 1);
                if (j != 0) next[nsum][j - 1] += prev[sum][j] * j;
            }
        }
        prev.swap(next);
        next.assign(k + 1, vector<int>(n + 1));
    }

    int result = 0;
    for (int i = 0; i <= k; i++) {
        result += prev[i][0];
    }
    cout << result % MOD << endl;

}