#include <bits/stdc++.h>

const int N = 200005;

int n, m, o, x, l, r, now, d;
int px[N], py[N], beg[N];

std::unordered_map<int, int> add[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> px[i] >> py[i], py[i] += px[i];
    for (int i = 1; i <= m; ++i) {
        std::cin >> o >> x;
        if (o == 1) {
            beg[x] = i;
            if (i + px[x] <= m) ++add[i + px[x]][py[x]];
            if (i + py[x] <= m) --add[i + py[x]][py[x]];
        } else {
            d = beg[x] + (i - beg[x]) / py[x] * py[x] - py[x];
            l = d + px[x], r = d + py[x];
            while (l < i) l += py[x];
            while (r < i) r += py[x];
            if (l <= m) --add[l][py[x]];
            if (r <= m) ++add[r][py[x]];
            now -= l > r;
        }
        for (auto x : add[i]) {
            now += x.second;
            if ((r = x.first + i) <= m) add[r][x.first] += x.second;
        }
        std::cout << now << '\n';
    }
    return 0;
}