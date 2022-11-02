#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int64_t full(int x) { return int64_t(x) * int64_t(x + 1) / 2; }

const int N = 200000;

int n, pnt;

std::vector<int> as, nd, cp, vd;
std::vector<int64_t> ans;
std::vector<std::vector<int>> graph, divisors, hist;

void init() {
    nd.assign(N + 1, 0);
    divisors.assign(N + 1, std::vector<int>());
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) ++nd[j];
    }
    for (int i = 1; i <= N; i++) divisors[i].reserve(nd[i]);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) divisors[j].push_back(i);
    }
}

int rec1(int x, int prev) {
    int res = 1;
    vd[x] = pnt;
    for (int nx : graph[x]) {
        if (nx != prev && cp[nx] == pnt) res += rec1(nx, x);
    }
    return res;
}

void calculate(int d) {
    ++pnt;
    for (int v : hist[d]) cp[v] = pnt;
    for (int v : hist[d]) {
        if (vd[v] != pnt) ans[d] += full(rec1(v, -1));
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    init();
    std::cin >> n;
    as.resize(n);
    for (int i = 0; i < n; ++i) std::cin >> as[i];
    graph.assign(n, std::vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y, --x, --y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    ans.assign(N + 1, 0);
    hist.assign(N + 1, std::vector<int>());
    cp.assign(n, 0);
    vd.assign(n, 0);
    pnt = 0;
    for (int i = 0; i < n; i++) {
        for (int d : divisors[as[i]]) hist[d].push_back(i);
    }
    for (int d = 1; d <= N; d++) {
        if (hist[d].empty()) continue;
        calculate(d);
    }
    for (int i = ans.size(); i-- > 0;) {
        for (int d : divisors[i]) {
            if (d < i) ans[d] -= ans[i];
        }
    }
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] != 0) std::cout << i << " " << ans[i] << "\n";
    }
    return 0;
}