#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int mod;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}

inline int mul(int x, int y) {
    return (x * ll(y)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> mod;
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = add(ans, mul(mul(n - i + 1, n - i + 1), mul(fact[i], fact[n - i])));
    }
    cout << ans << endl;
}