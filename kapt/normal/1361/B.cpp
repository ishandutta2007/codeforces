#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 1e9 + 7, MAXN = 1e6 + 10;
int arr[MAXN];

int power(int p, int n) {
    int res = 1;
    while (n) {
        if (n % 2 == 0) {
            p = (p * p) % MOD;
            n /= 2;
        } else {
            res = (res * p) % MOD;
            n--;
        }
    }
    return res;
}

int xy[2];

int mgcd(int a, int b) {
    if (b == 0) {
        xy[0] = 1;
        xy[1] = 0;
        return a;
    }
    int d = mgcd(b, a % b);
    int q = a / b;
    int x = xy[0], y = xy[1];
    xy[0] = y;
    xy[1] = x - q * y;
    return d;
}

inline int inv(int x, int p) {
    int res = mgcd(x, p);
    if (res != 1) {
        return -1;
    }
    return (xy[0] % p + p) % p;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        if (p == 1) {
            cout << n % 2 << '\n';
            continue;
        }
        int ans = 0;
        int d = 0;
        sort(arr, arr + n);
        for (int i = n - 1; i >= 0; --i) {
            int x = power(p, arr[i]);
            if (ans == 0 && d == 0) {
                ans = x % MOD;
                d = 1;
            } else {
                ans = ((ans - x) % MOD + MOD) % MOD;
                d--;
            }
            while (i != 0 && arr[i] != arr[i - 1] && d < n && d != 0) {
                d *= p;
                arr[i]--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}