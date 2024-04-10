#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define va first
#define vb second
using namespace std;
typedef unsigned long long lint;
typedef pair<int, int> pint;

const int M = 4e6 + 10;
int n, m; lint Dp[M];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    
    Dp[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        Dp[i] = 2 * Dp[i + 1] % m;
        for (int j = 2; 1LL * i * j <= n; j++) {
            Dp[i] = (Dp[i] + Dp[j * i] + m - Dp[min(n + 1, j * i + j)]) % m;
        }
    }
    cout << (Dp[1] + m - Dp[2]) % m;
}