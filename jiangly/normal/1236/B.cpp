#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1E9 + 7;
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = 1LL * ans * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int t = power(2, m) - 1;
    cout << power(t, n) << "\n";
    return 0;
}