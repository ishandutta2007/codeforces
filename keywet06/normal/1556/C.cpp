#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp std::make_pair

using int64 = long long;
using pair = std::pair<int64, int64>;

const int N = 1000005;

int64 T, n, k, x, y, z, ans;
int64 a[N];

std::stack<pair> s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        if (i & 1) {
            y += x;
            continue;
        }
        ans += std::min(x, y);
        y -= x;
        while (!s.empty()) {
            pair o = s.top();
            s.pop();
            if (o.fi < y) {
                s.push(o);
                s.push(mkp(y, 1));
                break;
            }
            ans += o.se;
            if (o.fi == y) {
                s.push(mkp(y, o.se + 1));
                break;
            }
        }
        if (s.empty() && y >= 0) s.push(mkp(y, 1));
        if (y < 0) y = 0;
    }
    std::cout << ans << std::endl;
    return 0;
}