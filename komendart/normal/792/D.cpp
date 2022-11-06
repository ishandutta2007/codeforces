#include <bits/stdc++.h>

using namespace std;

#define int long long

int getpower(int x) {
    int ans = 1;
    while (!(x & 1)) {
        x >>= 1LL;
        ans <<= 1LL;
    }
    return ans;
}

int solve(int v, string s, int n) {
    for (auto c: s) {
        int k = getpower(v);
        if (c == 'U') {
            int t = v | (k << 1);
            if (t & k) t ^= k;
            if (t <= n) v = t;
        } else if (c == 'L') {
            v -= k >> 1LL;
        } else {
            v += k >> 1LL;
        }
    }
    return v;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int v; string s;
        cin >> v >> s;
        cout << solve(v, s, n) << '\n';
    }
}