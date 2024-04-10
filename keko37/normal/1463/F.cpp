#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = (1 << 22) + 5;

int n, x, y;
int dp[MAXN], prosli[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    int cost = n / (x + y), lim = n % (x + y);
    int mx_mask = 1 << max(x, y), comp = ((1 << 30) - 1) ^ mx_mask;
    for (int pos = x + y - 1; pos >= 0; pos--) {
        int curr_cost = cost + (pos < lim);
        for (int mask = 0; mask < mx_mask; mask++) {
            int res = prosli[(mask * 2) & comp];
            if ((mask & (1 << (x - 1))) == 0 && (mask & (1 << (y - 1))) == 0) {
                res = max(res, prosli[(mask * 2 + 1) & comp] + curr_cost);
            }
            dp[mask] = res;
        }
        for (int mask = 0; mask < mx_mask; mask++) {
            prosli[mask] = dp[mask];
        }
    }
    cout << dp[0];
    return 0;
}