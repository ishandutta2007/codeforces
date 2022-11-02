#include <bits/stdc++.h>

#define mkp std::make_pair
#define fir first
#define sec second

using pair = std::pair<int, int>;

const int N = 200005;

int T, n, x, y, z, k, head;
int a[N], p[N], ans[N];

std::set<pair, std::greater<pair> > set;

std::stack<pair> sta;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], p[i] = i, ans[i] = 0;
        std::sort(p + 1, p + n + 1, [](int x, int y) { return a[x] < a[y]; });
        x = 1, y = 0;
        for (int i = 2; i <= n; ++i) {
            if (a[p[i]] == a[p[i - 1]]) {
                ++x;
            } else {
                y += std::min(x, k), x = 1;
            }
        }
        y += std::min(x, k), z = y / k;
        set.clear();
        for (int i = 1; i <= k; ++i) set.insert(mkp(z, i));
        x = 1, y = 0;
        for (int i = 2; i <= n; ++i) {
            if (a[p[i]] != a[p[i - 1]]) {
                y = 0;
                for (pair pa : set) {
                    ans[p[i - x]] = pa.sec, --x, ++y;
                    if (pa.fir - 1) sta.push(mkp(pa.fir - 1, pa.sec));
                    if (!x) break;
                }
                while (y--) set.erase(set.begin());
                while (!sta.empty()) set.insert(sta.top()), sta.pop();
                x = 1;
            } else {
                ++x;
            }
        }
        for (pair pa : set) {
            ans[p[n - x + 1]] = pa.sec, --x;
            if (!x) break;
        }
        for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
        std::cout << '\n';
    }
    return 0;
}