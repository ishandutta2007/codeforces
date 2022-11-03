// HI
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int mod = 1'000'000'007;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int sub(int x, int y) {
    int z = x + mod - y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int mul(int x, int y) {
    return (x * (ll)y) % mod;
}
inline int binpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = mul(ans, x);
        }
        x = mul(x, x);
        p >>= 1;
    }
    return ans;
}
inline int inv(int x) {
    return binpow(x, mod - 2);
}

int mp[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            a.push_back(x);
        }
    }
    int m = a.size();
    if (m == 0) {
        cout << sub(binpow(2, n), 1) << '\n';
        return 0;
    }
    for (int y: a) {
        for (int i = 1, j = 0; i <= y; i *= 2, ++j) {
            if (y % i != 0) {
                break;
            }
            ++mp[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 40; ++i) {
        int y = mp[i];
        int z = mp[i + 1];
        if (y != z) {
            ans = add(ans, binpow(2, y - 1));
        }
    }
    ans = sub(sub(binpow(2, n), 1), ans);
    cout << ans << '\n';

}