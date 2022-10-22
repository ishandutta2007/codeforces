#include<bits/stdc++.h>

using namespace std;

#define int long long

int cnt(int n, int x) {
    if (x == 0) x = 9;
    return (n + (9 - x)) / 9;
}

int d(int x) {
    int res = 1;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        res = res * (cnt + 1);
    }
    if (x > 1) res *= 2;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans2 += (n / i);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if ((i * j) % 9 == k) {
                    ans += cnt(n, i) * cnt(n, j) * cnt(n, k);
                }
            }
        }
    }
    cout << ans - ans2;
}