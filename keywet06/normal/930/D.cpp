#include <bits/stdc++.h>

using int64 = long long;

const int N = 500001;
const int C = 220000;

int umn[N], umx[N];
int dmn[N], dmx[N];

int64 ans;

struct Val {
    std::vector<int> a[N];
    void calc(int md) {
        umn[0] = N;
        umx[0] = -N;
        for (int i = 1; i < N; ++i) {
            umn[i] = umn[i - 1], umx[i] = umx[i - 1];
            for (int y : a[i]) umn[i] = std::min(umn[i], y);
            for (int y : a[i]) umx[i] = std::max(umx[i], y);
        }
        dmn[N - 1] = N;
        dmx[N - 1] = -N;
        for (int i = N - 2; i >= 0; --i) {
            dmn[i] = dmn[i + 1], dmx[i] = dmx[i + 1];
            for (int y : a[i]) dmn[i] = std::min(dmn[i], y);
            for (int y : a[i]) dmx[i] = std::max(dmx[i], y);
        }
        for (int i = 1; i < N; ++i) {
            if (i % 2 != md) continue;
            int l = std::max(dmn[i + 1], umn[i - 1]) + 1;
            int r = std::min(dmx[i + 1], umx[i - 1]) - 1;
            if (((l + C) % 2) != (i % 2)) ++l;
            if (((r + C) % 2) != (i % 2)) --r;
            int ad = (r - l);
            if (ad >= 0) ans += std::max(0, ad / 2 + 1);
        }
    }
};

Val v[2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        v[(x + y + C) % 2].a[x + y + C].push_back(x - y);
    }
    v[0].calc(1), v[1].calc(0);
    std::cout << ans << "\n";
    return 0;
}