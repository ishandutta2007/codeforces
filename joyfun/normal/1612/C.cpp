#include <bits/stdc++.h>

int t;
long long k, x;

long long range_sum(long long a, long long b) {
    if (a > b) std::swap(a, b);
    long long n = b - a + 1;
    return n * (a + b) / 2;
}

long long judge(long long k, long long mid, long long x) {
    long long ans = range_sum(1, std::min(k, mid));
    if (mid > k) {
        long long cnt = mid - k;
        x -= range_sum(k - 1, k - cnt);
    }
    return ans >= x;
}

int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> k >> x;
        long long l = 1, r = 2 * k - 1;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (judge(k, mid, x)) {
                r = mid;
            } else l = mid + 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}