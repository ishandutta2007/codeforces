#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long count(long long x) {
    int l1 = 64 - __builtin_clzll(n);
    int l2 = 64 - __builtin_clzll(x);
    long long res = (1LL << (l1 - l2)) - 1;
    long long y = n >> (l1 - l2);
    if (y > x) {
        res += res + 1;
    } else if (y == x) {
        res += n - (x << (l1 - l2)) + 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    long long ans;
    long long l = 0, r = (n - 1) / 2;
    while (l < r) {
        long long x = (l + r + 1) / 2;
        if (count(2 * x + 1) >= k) {
            l = x;
        } else {
            r = x - 1;
        }
    }
    ans = 2 * l + 1;
    l = 1;
    r = n / 2;
    while (l < r) {
        long long x = (l + r + 1) / 2;
        if (count(2 * x) + count(2 * x + 1) >= k) {
            l = x;
        } else {
            r = x - 1;
        }
    }
    if (count(2 * l) + count(2 * l + 1) >= k)
        ans = max(ans, 2 * l);
    cout << ans << endl;
    return 0;
}