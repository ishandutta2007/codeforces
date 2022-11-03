#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int MOD = 998244353;

long long f[N][N];
    
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    f[1][0] = m;
    for(int i = 2; i <= n; i++)
        for(int j = 0; j < i; j++) {
            f[i][j] = f[i - 1][j];
            if (j) 
                f[i][j] = (f[i][j] + f[i - 1][j - 1] * (m - 1)) % MOD;
        }
    cout << f[n][k];
}