#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl
#define pub push_back

using int64 = long long;

const int INF5 = 1e9;
const int64 INF6 = 1e15;
const int B = 2;
const int N = 200005;

int T, n, d, mas, mis, x;
int fa[N], a[N], de[N];

int64 ans, fax, gax;
int64 f[N];

std::vector<int> ve[N];

std::stack<int> s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, d = ans = 0;
        for (int i = 2; i <= n; ++i) std::cin >> fa[i], de[i] = 0;
        for (int i = 2; i <= n; ++i) {
            if (!de[i]) s.push(i);
            for (int u = i; !de[u] && u > 1; u = fa[u]) s.push(u);
            while (!s.empty()) de[s.top()] = de[fa[s.top()]] + 1, s.pop();
        }
        for (int i = 2; i <= n; ++i) std::cin >> a[i], d = std::max(d, de[i]);
        for (int i = 1; i <= d; ++i) ve[i].clear();
        for (int i = 2; i <= n; ++i) ve[de[i]].pub(i);
        // for (int i = 1; i <= d; ++i) {
        //     Debug << "deep-" << i << " :";
        //     for (int u : ve[i]) Deb << ' ' << u;
        //     Deb << std::endl;
        // }
        for (int i = 1; i <= d; ++i) {
            mas = -INF5, mis = INF5, fax = -INF6, gax = -INF6;
            for (int u : ve[i]) {
                f[u] = 0, mas = std::max(mas, a[u]), mis = std::min(mis, a[u]);
                fax = std::max(fax, f[fa[u]] + a[u]);
                gax = std::max(gax, f[fa[u]] - a[u]);
            }
            for (int u : ve[i]) {
                f[u] = std::max(f[u], f[fa[u]] + a[u] - mis);
                f[u] = std::max(f[u], f[fa[u]] - a[u] + mas);
                f[u] = std::max(f[u], fax - a[u]);
                f[u] = std::max(f[u], gax + a[u]);
                ans = std::max(ans, f[u]);
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}