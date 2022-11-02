#include <bits/stdc++.h>

const int P = 1000000007;

int n, m, ans, ways, curAns, curWays;

std::vector<int> s, l, r, w, c;
std::vector<std::vector<int>> pos, f;

int power(int base, int e) {
    int res = 1;
    while (e > 0) {
        if (e % 2 == 1) res = 1LL * res * base % P;
        base = 1LL * base * base % P;
        e /= 2;
    }
    return res;
}

void calculate(int k) {
    int cl = std::upper_bound(f[k].begin(), f[k].end(), l[k]) - f[k].begin();
    int cr = std::upper_bound(f[k].begin(), f[k].end(), r[k]) - f[k].begin();
    if (cl > cr) std::swap(cl, cr);
    if (cr == 0) {
        c[k] = 0, w[k] = 1;
    } else if (cl == 0 || cr == 1) {
        c[k] = 1, w[k] = cl + cr;
    } else {
        c[k] = 2, w[k] = cl * (cr - 1);
    }
}

void erase(int k) {
    curAns -= c[k], curWays = 1LL * curWays * power(w[k], P - 2) % P;
}

void insert(int k) { curAns += c[k], curWays = 1LL * curWays * w[k] % P; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    s.resize(n), pos.resize(n), f.resize(n), l.resize(n);
    r.resize(n), c.resize(n), w.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i], --s[i];
        pos[s[i]].push_back(i), ++r[s[i]];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y, --x;
        f[x].push_back(y);
    }
    curWays = 1;
    for (int i = 0; i < n; ++i) std::sort(f[i].begin(), f[i].end());
    for (int i = 0; i < n; ++i) calculate(i), insert(i);
    ans = curAns, ways = curWays;
    for (int i = 0; i < n; ++i) {
        int x = s[i];
        ++l[x], --r[x], erase(x);
        if (std::binary_search(f[x].begin(), f[x].end(), l[x])) {
            int cr = std::upper_bound(f[x].begin(), f[x].end(), r[x]) -
                     f[x].begin() - (l[x] <= r[x]);
            if (cr == 0) {
                c[x] = 1, w[x] = 1;
            } else {
                c[x] = 2, w[x] = cr;
            }
            insert(x);
            if (curAns > ans) {
                ans = curAns, ways = curWays;
            } else if (curAns == ans) {
                ways = (ways + curWays) % P;
            }
            erase(x);
        }
        calculate(x), insert(x);
    }
    std::cout << ans << " " << ways << "\n";
    return 0;
}