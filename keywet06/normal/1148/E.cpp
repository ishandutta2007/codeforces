#include <bits/stdc++.h>
using int64 = long long;
const int N = 300005;
int n, d[N], sta[N], top;
struct node {
    int pos, id;
} a[N], b[N];
bool cmp(node a, node b) { return a.pos < b.pos; }
struct point {
    int i, j, d;
    point(int _i, int _j, int _d) {
        i = _i;
        j = _j;
        d = _d;
    }
};
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i].pos, a[i].id = i;
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) std::cin >> b[i].pos, b[i].id = i;
    std::sort(b + 1, b + n + 1, cmp);
    int64 sum = 0;
    for (int i = 1; i <= n; ++i) {
        d[i] = b[i].pos - a[i].pos;
        sum += d[i];
        if (sum < 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    if (sum != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    std::cout << "YES" << std::endl;
    std::vector<point> ans;
    for (int i = 1; i <= n; ++i) {
        if (d[i] > 0) {
            sta[++top] = i;
        } else if (d[i] < 0) {
            while (top) {
                int delta = std::min(a[i].pos - b[i].pos,
                                     b[sta[top]].pos - a[sta[top]].pos);
                a[i].pos -= delta;
                a[sta[top]].pos += delta;
                ans.push_back(point(a[sta[top]].id, a[i].id, delta));
                if (a[i].pos == b[i].pos) break;
                --top;
            }
            assert(a[i].pos == b[i].pos);
        }
    }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i].i << " " << ans[i].j << " " << ans[i].d
                  << std::endl;
    }
    return 0;
}