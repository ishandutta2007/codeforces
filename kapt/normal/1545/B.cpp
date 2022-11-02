#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 998244353;

int inv(int x) {
    int res = 1;
    int n = MOD - 2;
    while (n) {
        if (n % 2 == 0) {
            x *= x;
            x %= MOD;
            n /= 2;
        } else {
            res *= x;
            res %= MOD;
            n--;
        }
    }
    return res;
}

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') continue;
            arr.push_back(i);
        }
        arr.push_back(n);
        n -= arr.size() - 1;
        int lst = -1;
        for (auto elem : arr) {
            n -= (elem - lst - 1) % 2;
            lst = elem;
            /// cout << n << endl;
        }
        n /= 2;
        n += arr.size() - 1;
        int k = arr.size() - 1;
        int ans = 1;
        for (int i = n; i > n - k; --i) {
            ans *= i;
            ans %= MOD;
        }
        for (int i = 1; i <= k; ++i) {
            ans *= inv(i);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}