#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<long long>> dp;
vector<int> cnt;
long long cost = 0;
int L;
int R;

long long f(int l, int r) {
    while (R < r) cost += cnt[a[(++R) - 1]]++;
    while (L > l) cost += cnt[a[(--L) - 1]]++;
    while (R > r) cost -= --cnt[a[(R--) - 1]];
    while (L < l) cost -= --cnt[a[(L++) - 1]];
    return cost;
}

void solve(int K, int l, int r, int optl, int optr) {
    if (l > r) return;
    int opt = -1;
    long long opt_val = numeric_limits<long long>::max();
    int M = (l + r) / 2;
    for (int i = optl; i <= min(optr, M); i++) {
        long long c = f(i, M) + dp[K-1][i-1];
        if (c < opt_val) {
            opt_val = c;
            opt = i;
        }
    }
    dp[K][M] = opt_val;
    solve(K, l, M-1, optl, opt);
    solve(K, M+1, r, opt, optr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cnt.assign(n+1, 0);

    dp.assign(k+1, vector<long long>(n+1, 0));
    for (int i = 1; i <= n; i++)
        dp[0][i] = numeric_limits<long long>::max() / 2;

    L = 1, R = 0;
    for (int K = 1; K <= k; K++) {
        solve(K, 1, n, 1, n);
    }
    cout << dp[k][n] << endl;
}