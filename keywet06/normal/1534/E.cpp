#include <bits/stdc++.h>

const int N = 505;

int n, k, x, ans;
int f[N], t[N], d[N];

std::queue<int> q;

std::stack<int> a1, b1, a2, b2, s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    f[0] = 1, q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = std::max(0, k - u); i <= n - u && i <= k; ++i) {
            if (f[u + i + i - k]) continue;
            f[u + i + i - k] = f[u] + 1;
            t[u + i + i - k] = u;
            d[u + i + i - k] = i;
            q.push(u + i + i - k);
        }
    }
    if (!f[n]) return std::cout << -1 << std::endl, 0;
    x = n;
    while (x) s.push(d[x]), x = t[x];
    for (int i = 1; i <= n; ++i) a1.push(i);
    while (--f[n]) {
        int u = s.top();
        s.pop();
        std::cout << '?';
        for (int i = 1; i <= u; ++i) {
            std::cout << ' ' << a1.top();
            a2.push(a1.top()), a1.pop();
        }
        for (int i = u + 1; i <= k; ++i) {
            std::cout << ' ' << b1.top();
            b2.push(b1.top()), b1.pop();
        }
        std::cout << std::endl;
        while (!a2.empty()) b1.push(a2.top()), a2.pop();
        while (!b2.empty()) a1.push(b2.top()), b2.pop();
        std::cin >> x;
        ans ^= x;
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}