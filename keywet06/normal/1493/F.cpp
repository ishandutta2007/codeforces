#include <bits/stdc++.h>

using namespace std;

int n, m;

bool Query(int h, int w, int lx1, int ly1, int lx2, int ly2) {
    std::cout << "? " << h << " " << w << " " << lx1 + 1 << " " << ly1 + 1 << " " << lx2 + 1 << " " << ly2 + 1
              << std::endl;
    int res = 1;
    std::cin >> res;
    return res;
}

bool Query(int h, int w, int lx1, int ly1, int lx2, int ly2, bool rev) {
    if (rev) std::swap(h, w), std::swap(lx1, ly1), std::swap(lx2, ly2);
    return Query(h, w, lx1, ly1, lx2, ly2);
}

std::vector<std::pair<int, int>> Fac(int x) {
    std::vector<std::pair<int, int>> res;
    for (int p = 2; p * p <= x; ++p) {
        int cnt = 0;
        while (x % p == 0) x /= p, ++cnt;
        if (cnt) res.push_back({p, cnt});
    }
    if (x > 1) res.push_back({x, 1});
    return res;
}

bool Check(int lx, int rx, int H, int cnt, bool rev) {
    int len = (rx - lx + 1) / cnt;
    len *= cnt / 2;
    if (!Query(len, H, lx, 0, lx + len, 0, rev)) return false;
    if (cnt == 2) return true;
    return Check(lx + len, rx, H, cnt - cnt / 2, rev);
}

int main() {
    std::cin >> n >> m;
    int d1 = 1, d2 = 1;
    for (auto p : Fac(n)) {
        int x = 1, ans = 1;
        for (int i = 0; i < p.second; ++i) {
            if (Check(0, n / x - 1, m, p.first, 0)) {
                ++ans, x *= p.first;
            } else {
                break;
            }
        }
        d1 *= ans;
    }
    for (auto p : Fac(m)) {
        int x = 1, ans = 1;
        for (int i = 0; i < p.second; ++i) {
            if (Check(0, m / x - 1, n, p.first, 1)) {
                ++ans, x *= p.first;
            } else {
                break;
            }
        }
        d2 *= ans;
    }
    int ans = d1 * d2;
    std::cout << "! " << ans << std::endl;
    return 0;
}