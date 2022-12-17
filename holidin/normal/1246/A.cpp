#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int cnt_b(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

signed main() {
    int i, j, k, n, p, x;
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    cin >> n >> p;
    int sum = 1;
    for (i = 1; i < 33; ++i) {
        int x = n - i * p;
        sum *= 2;
        if (x >= i && cnt_b(x) <= i) {
            cout << i;
            return 0;

        }

    }
    cout << -1;
}