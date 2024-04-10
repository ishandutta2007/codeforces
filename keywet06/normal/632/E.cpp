#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1000 + 5;
const int inf = 1e9 + 5;
int n, k;
int a[N], b[N];
int dp[N * N];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) b[i] = a[i] - a[1];
    for (int i = 0; i < N * N; i++) dp[i] = inf;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < N * N; j++) {
            if (j - b[i] >= 0) dp[j] = min(dp[j], dp[j - b[i]] + 1);
        }
    for (int i = 0; i < N * N; i++) {
        if (dp[i] <= k) cout << k * a[1] + i << ' ';
    }
}