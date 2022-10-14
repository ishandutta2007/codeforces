#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const llint INF = 1000000000000000000LL;

llint n, r1, r2, r3, d, sol = INF;
llint a[MAXN], dp[MAXN];

llint f (int ind) {
    return min(r1 * a[ind] + min(r3, 2 * r1), r2 + r1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1] + r1 * a[i] + r3;
        if (i > 1) dp[i] = min(dp[i], dp[i - 2] + f(i - 1) + f(i) + 2 * d);
    }
    sol = dp[n];
    llint last = min(r1 * a[n] + r3, f(n) + 2 * d);
    sol = min(sol, dp[n - 1] + last);
    llint curr = last;
    for (int i = n - 1; i >= 1; i--) {
        curr += f(i) + d;
        sol = min(sol, dp[i - 1] + curr);
    }
    cout << sol + (n - 1) * d;
    return 0;
}