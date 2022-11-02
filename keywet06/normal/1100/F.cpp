#include <bits/stdc++.h>

const int N = 500005;

typedef std::pair<int, int> Pair;

int n, q, a[N], ans[N], bas[40], pos[40];

std::vector<Pair> eve[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        eve[r].push_back(Pair(l, i));
    }
    for (int i = 1; i <= n; ++i) {
        int x = a[i], p = i;
        for (int j = 20; j >= 0; --j) {
            if (x & (1 << j)) {
                if (!bas[j]) {
                    bas[j] = x;
                    pos[j] = p;
                    break;
                }
                if (pos[j] < p) std::swap(bas[j], x), std::swap(pos[j], p);
                x ^= bas[j];
            }
        }
        for (auto p : eve[i]) {
            for (int j = 20; j >= 0; --j) {
                if (pos[j] >= p.first) ans[p.second] = std::max(ans[p.second], ans[p.second] ^ bas[j]);
            }
        }
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}