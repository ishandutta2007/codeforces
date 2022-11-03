#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int mod = 998244353;
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

int f[300000], invf[300000];

inline int c(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return mul(f[n], mul(invf[k], invf[n - k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0] = invf[0] = 1;
    for (int i = 1; i < 300000; ++i) {
        f[i] = mul(f[i - 1], i);
        invf[i] = inv(f[i]);
    }
    int n;
    cin >> n;
    vector<string> s(n);
    bool can_1 = true;
    bool can_2 = true;
    vector<int> cnt(5164);
    int only_12 = 1;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (can_1 && !(s[i] == "??" || s[i] == "B?" || s[i] == "?W" || s[i] == "BW")) {
            can_1 = false;
        }
        if (can_2 && !(s[i] == "??" || s[i] == "W?" || s[i] == "?B" || s[i] == "WB")) {
            can_2 = false;
        }
        if (s[i] == "BB" || s[i] == "WW") {
            only_12 = 0;
        } else if (s[i] == "??") {
            only_12 = mul(only_12, 2);
        } else {
            //only_12 = mul(only_12, 1);
        }
        ++cnt[s[i][0]];
        ++cnt[s[i][1]];
    }
    int diff = abs(cnt['B'] - cnt['W']);
    int sum = cnt['?'];
    int a = (sum + diff) / 2;
    int ans = c(sum, a);
//    cout << (can_1 ? 1 : 0) << " " << (can_2 ? 1 : 0) << " " << ans << " " << only_12 << endl;
    ans = sub(ans, only_12);
    if (can_1) {
        ans = add(ans, 1);
    }
    if (can_2) {
        ans = add(ans, 1);
    }
    cout << ans << "\n";

}