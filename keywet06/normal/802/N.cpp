#include <bits/stdc++.h>

using int64 = long long;
using pli = std::pair<int64, int>;

const int N = 5005;

int n, k, cc;
int a[N], b[N];

int64 calc(int64 c) {
    std::priority_queue<pli> q;
    int64 st = cc = 0;
    for (int i = 1; i <= n; ++i) {
        q.emplace(-a[i], 0);
        int64 t = b[i] - c;
        pli tp = q.top();
        if (-t > -tp.first) st += t - tp.first, q.pop(), q.emplace(t, 1);
    }
    while (!q.empty()) cc += q.top().second, q.pop();
    return st;
}
int main() {
    int64 g = 0, e = 2e9, r;
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) std::cin >> b[i];
    while (g <= e) {
        int64 mid = (g + e) >> 1, d = calc(mid);
        if (cc <= k) {
            g = mid + 1, r = d + k * mid;
        } else {
            e = mid - 1;
        }
    }
    std::cout << r << std::endl;
    return 0;
}