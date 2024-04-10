#include <bits/stdc++.h>

using int64 = long long;

namespace oct {

void ios() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

}  // namespace oct

const int N = 10005;

struct data {
    int x, y;
};

int n, l, r;
int f[N];

data a[N];

bool cmp(data a, data b) { return a.y < b.y || a.y == b.y && a.x > b.x; }

int main() {
    oct::ios();
    std::cin >> n >> l >> r;
    int s = 0;
    for (int i = 1; i <= n; i++) std::cin >> a[i].x, s += a[i].x;
    for (int i = 1; i <= n; i++) std::cin >> a[i].y;
    std::sort(a + 1, a + n + 1, cmp);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= a[i].x; j--) {
            if (f[j - a[i].x]) {
                f[j] = std::max(
                    f[j], f[j - a[i].x] + a[i].y * (j >= s - r && j <= s - l));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= s; i++) ans = std::max(ans, f[i]);
    std::cout << --ans << std::endl;
    return 0;
}